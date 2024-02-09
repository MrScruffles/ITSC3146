#include <iostream>
#include <pthread.h>
#include <stdlib.h>

#define TOTAL_THREADS 4

int count;
pthread_mutex_t the_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex initializer macro

void* myFunction(void* arg) {
    int actual_arg = *((int*) arg);
    
    for(unsigned int i = 0; i < 10; ++i) {
        // Lock the mutex before entering the critical region
        pthread_mutex_lock(&the_mutex);
        
        // Beginning of the critical region
        count++;
        std::cout << "Thread #" << actual_arg << " count = " << count << std::endl;
        // End of the critical region

        // Unlock the mutex after the critical region is done
        pthread_mutex_unlock(&the_mutex);

        // Random wait - This code is just to ensure that the threads
        // show data sharing problems
        int max = rand() % 100000;
        for (int x = 0; x < max; x++); // End of random wait code
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t ids[TOTAL_THREADS];
    int args[TOTAL_THREADS];
    int rc[TOTAL_THREADS];
    
    count = 0;
    for(unsigned int i = 0; i < TOTAL_THREADS; ++i) {
        args[i] = i;
        rc[i] = pthread_create(&ids[i], NULL, myFunction, (void*) &args[i]);
    }
    
    for(unsigned int i = 0; i < TOTAL_THREADS; ++i) {
        pthread_join(ids[i], NULL);
    }
    
    std::cout << "Final count = " << count << std::endl;
    
    // Destroy the mutex after it's no longer needed
    pthread_mutex_destroy(&the_mutex);
    
    pthread_exit(NULL);
}
