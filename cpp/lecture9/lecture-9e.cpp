#include <iostream>
#include <thread>

#define NUM_THREADS 5
using namespace std;

#define IN_PRODUCTION


//Please Read About
//POSIX
//Semaphore
//Mutex Locks and Unlocks
//Sequential

pthread_mutex_t locking;
double globalVar = 10;

void *mainThread(void *arg) {
    std::cout << "In Thread" << std::endl;
    std::cout << pthread_self() << std::endl;

    // double val = *(double*)arg;
    double *val = (double*)arg;
    std::cout << *val << std::endl;

    pthread_mutex_lock(&locking);
    globalVar = 8;
    pthread_mutex_unlock(&locking);

    return NULL;
}

void *secThread(void *arg) {

    std::cout << "In Thread 2" << std::endl;
    std::cout << pthread_self() << std::endl;

    double val = *(double*)arg;

    std::cout << val << std::endl;

    pthread_mutex_lock(&locking);
    globalVar = 8;
    pthread_mutex_unlock(&locking);

    return NULL;
}

void thread_3(int val) {

    std::cout << "In Thread 3" <<std::endl;
    std::cout << pthread_self() <<std::endl;

    std::cout << val << std::endl;

    pthread_mutex_lock(&locking);
    globalVar = 8;
    pthread_mutex_unlock(&locking);
}

int main(){

    double passVal1 = 77;
    double passVal2 = 88;

    pthread_t thread1, thread2; // uintptr not actual variable

    pthread_create(&thread1, NULL, *mainThread, (void *) &passVal1); 
    pthread_create(&thread2, NULL, &secThread, (void* ) &passVal2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    //C++ way of writing threads using the thread class instead of pthread
    int val = 1;
    std::thread new_thread(thread_3, val);
    new_thread.join();
}