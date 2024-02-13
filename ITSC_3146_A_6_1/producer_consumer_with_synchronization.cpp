#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

#define MAX 10
#define N 4

// Data structure to represent a simplified Order 
// that has an order number and an item number.
struct Order
{
    int order_num;
    int item_num;	
};

Order new_orders [N];		// array of elements of type Order to be used as a shared buffer
int num_new_orders = 0;		// count of number of new (i.e., unprocessed) orders
int order_num = 0;			// global variable used to generate unique order numbers

// Define and initialize necessary mutex and condition variables
pthread_mutex_t data_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t console_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;

void* takeOrders(void* arg)
{
    int item;
    int index = 0;
    
    for(int i = 0; i < MAX; ++i) {
        cout << "Enter a menu item number between 1 and 50: ";
        cin >> item;

        pthread_mutex_lock(&data_mutex);
        while(num_new_orders == N)
            pthread_cond_wait(&cond_full, &data_mutex);

        new_orders[index].order_num = order_num;
        new_orders[index++].item_num = item;
        ++num_new_orders;
        ++order_num;
        if(index == N)
            index = 0;

        pthread_cond_signal(&cond_empty);
        pthread_mutex_unlock(&data_mutex);

        pthread_mutex_lock(&console_mutex);
        cout << "Got new order! Order number is " << order_num - 1 << " and item number: " << item << std::endl;
        pthread_mutex_unlock(&console_mutex);

        sleep(1);  // Introduce a small delay
    }

    pthread_exit(NULL);
}

void* processOrders(void* arg)
{
    int item;
    int index = 0;
    int o_num;

    for(int i = 0; i < MAX; ++i) {
        pthread_mutex_lock(&data_mutex);
        while(num_new_orders == 0)
            pthread_cond_wait(&cond_empty, &data_mutex);

        o_num = new_orders[index].order_num;
        item = new_orders[index++].item_num;
        --num_new_orders;

        if(index == N)
            index = 0;

        pthread_cond_signal(&cond_full);
        pthread_mutex_unlock(&data_mutex);

        sleep(1);  // Introduce a small delay

        pthread_mutex_lock(&console_mutex);
        cout << "Processing order number " << o_num << " with item number: " << item << std::endl;
        pthread_mutex_unlock(&console_mutex);
    }

    pthread_exit(NULL);
}

int main()
{
    // Create threads to take and process orders
    pthread_t id1, id2;
    pthread_create(&id2, NULL, takeOrders, NULL);  // Create takeOrders thread first
    pthread_create(&id1, NULL, processOrders, NULL);  // Then create processOrders thread
    
    // Wait for both threads to finish
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    // Print goodbye message
    cout << "Phew! Done with orders for today!" << endl;

    pthread_exit(NULL);
}