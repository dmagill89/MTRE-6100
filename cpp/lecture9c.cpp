#include <pthread.h>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <chrono>

#define NUM_THREADS 5
using namespace std;

#define IN_PRODUCTION

// creat a class to input multiple parameters
class cls_data {
   public:
      int thread_id;
      int delay;
      std::string message;
      void printMessage();
};

void cls_data::printMessage() {
         cout << "******thread" << thread_id << "hold Message: " << message << endl;
}
/*
start-routine of our created threads
the parameter must by void * 
*/
void *PrintHello(void *inputdata) {

   cls_data *my_data;

   my_data = (cls_data *)inputdata;

   time_t create_time = time(NULL);

   int tid = my_data->thread_id;

   int delay = my_data->delay;

   cout<< "Create thread ID: " << tid << ",dalay:"<< delay << " at " << ctime(&create_time) <<  endl;

   cout << "Message: " << my_data->message << endl;

   my_data->printMessage();

   sleep(delay); //sleep delay seconds to simulate the task takes a while to compeleted

   time_t end_time = time(NULL);

   cout << "Thread ID, " << tid  << " ,compeleted at " << ctime(&end_time) <<endl;

   pthread_exit(NULL); //exit the thread!  explicitly exit 
}

int main(int argc, char ** argv) {  
   pthread_t threads[NUM_THREADS];
   cls_data td[NUM_THREADS];
   int ret;
   
   for( int i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : creating thread, " << i << endl;
      td[i].thread_id = i;
      td[i].message = "This is message";
      td[i].delay = i+1;
      
      ret = pthread_create(&threads[i], NULL, PrintHello, &td[i]);
      //without usleep, the print will mass with each other
      usleep(100000); //sleep 100000 microseconds ( one millionth),0.1 second

      if (ret) {
         cout << "Error:unable to create thread," << ret << endl;
         exit(-1);
      }
   }

   cout << "main exit" << endl;
   pthread_exit(NULL);  //the main thread should end with pthread_exit, 
                        //otherwise when main thread ends, all created threads will exit
}