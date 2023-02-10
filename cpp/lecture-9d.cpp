#include <pthread.h>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <chrono>

#define NUM_THREADS 5
using namespace std;

#define IN_PRODUCTION

void *wait (void *t ) {
   int i;

   long tid;

   tid = (long)t;

   cout << "Sleeping in thread " << endl;

   sleep(1);

   cout << "Thread with id : " << tid << "  ...exiting " << endl;

   pthread_exit(NULL);
}

int main () 
{
#ifdef IN_PRODUCTION
   std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
#endif
   int ret;
   int i;
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;

   void *status;

   // Initialize and set thread joinable
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);  //PTHREAD_CREATE_DETACHED

   //pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
   for( i = 0; i < NUM_THREADS; i++ ) {

      cout << "main() : creating thread, " << i << endl;

      ret = pthread_create(&threads[i], &attr, wait, &i );
      //ret = pthread_create(&threads[i], NULL, wait, (void *)i );

      if (ret) {
         cout << "Error:unable to create thread," << ret << endl;
         exit(-1);
      }
   }

   // free attribute and wait for the other threads
   //pthread_attr_destroy(&attr);
   
   for( i = 0; i < NUM_THREADS; i++ ) {

      ret = pthread_join(threads[i], &status);

      if (ret) {
         cout << "Error:unable to join," << ret << endl;
         exit(-1);
      }
      //cout << "completed thread id :" << i <<endl;
      cout << "exiting with status :" << status << endl;
   }

#ifdef IN_PRODUCTION
   auto final = std::chrono::high_resolution_clock::now();
   std::cout << "Performance Metric: Time Taken: " 
              << std::chrono::duration_cast<std::chrono::nanoseconds>(final-start).count() 
              << "ns\n";
#endif

   cout << "Main: program exiting." << endl;
   pthread_exit(NULL);

}