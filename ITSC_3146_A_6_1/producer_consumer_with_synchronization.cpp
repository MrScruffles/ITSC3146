#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

#define MAX 10
#define N 4

struct Order {
    int order_num;
    int item_num;	
};

Order new_orders[N];
int num_new_orders = 0;
int order_num = 0;

// Initialize mutexes and condition variables
pthread_mutex_t data_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t console_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_produce = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_consume = PTHREAD_COND_INITIALIZER;

void* takeOrders(void* arg) {
    int item;
    int index = 0;
	
    for(int i = 0; i < MAX; ++i) {
       
        pthread_mutex_lock(&console_mutex);
        cout << "Enter a menu item number between 1 and 50: ";
        cin >> item;
        cout << "Got new order! Order number is " << order_num << " and item number: " << item << std::endl;
        pthread_mutex_unlock(&console_mutex);

     
        pthread_mutex_lock(&data_mutex);
        while (num_new_orders == N) { 
            pthread_cond_wait(&can_produce, &data_mutex);
        }

        new_orders[index].order_num = order_num;
        new_orders[index++].item_num = item;
        ++num_new_orders;
        ++order_num;

        pthread_cond_signal(&can_consume); 
        pthread_mutex_unlock(&data_mutex);

        if(index == N) index = 0;
    }

    pthread_exit(NULL);
}

void* processOrders(void* arg) {
    int item, index = 0, o_num;

    for(int i = 0; i < MAX; ++i) {
        pthread_mutex_lock(&data_mutex);
        while (num_new_orders == 0) {  // Wait if there are no new orders
            pthread_cond_wait(&can_consume, &data_mutex);
        }

        o_num = new_orders[index].order_num;
        item = new_orders[index++].item_num;
        --num_new_orders;

        pthread_cond_signal(&can_produce);  // Signal that a new order can be produced
        pthread_mutex_unlock(&data_mutex);

        // Protect console access
        pthread_mutex_lock(&console_mutex);
        cout << "Processing order number " << o_num << " with item number: " << item << std::endl;
        pthread_mutex_unlock(&console_mutex);

        sleep(1);

        if(index == N) index = 0;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t id1, id2;
    pthread_create(&id1, NULL, processOrders, NULL);
    pthread_create(&id2, NULL, takeOrders, NULL);

    // Wait for threads to finish
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    cout << "Phew! Done with orders for today!" << endl;

    pthread_exit(NULL);
}