#include <pthread.h>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <chrono>

#define NUM_THREADS 5
using namespace std;

#define IN_PRODUCTION

void *PrintHello(void *threadid) {
    long tid;

    tid = (long) threadid;

    // givces the current time in seconds
    time_t create_time = time(NULL);

    cout << "Create thread ID: " << tid << " at " << ctime(&create_time) << endl;

    sleep(2); // sleep 1 second to simulate the task takes a while to complete

    time_t end_time = time(NULL);

    cout << "Thread ID, " << tid << " , completed at " << ctime(&end_time) << endl;
    cout << "Time in the thread in seconds from 1970= " << (end_time) << endl;
    cout << "Time in the thread with bad resolutions = " << (end_time) - (create_time) << endl;

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    auto start = std::chrono::high_resolution_clock::now();
    pthread_t threads[NUM_THREADS];
    int ret;

    for (int i = 0; i < NUM_THREADS; i++) {
        cout << "main() : creating thread, " << i << endl;

        ret = pthread_create(&threads[i], NULL, PrintHello, &i);

        usleep(100000); // sleep 100000 microseconds, 0.1 seconds

        if (ret) {
            cout << "Error: unable to create thread." << ret << endl;
            exit(-1);
        }
    }

    cout << "main exit" << endl;
    auto final = std::chrono::high_resolution_clock::now();
    cout << "Performance Metric: Time Taken: " << std::chrono::duration_cast<std::chrono::nanoseconds>(final - start).count() << "ns\n";

    pthread_exit(NULL); //end with pthread_exit, otherwise created threads may hang

    return 0;
}