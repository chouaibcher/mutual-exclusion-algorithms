#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Shared variable between threads
int VAL = 0;

// Function executed by each thread
void *function(void *args)
{
     do
     {
          // Simulate some work with a delay
          sleep(1);

          // Increment the shared variable
          VAL++;

          // Print the current value of the shared variable and thread name
          printf("=> %s : %d \n", args, VAL);

     } while (1); // Infinite loop

     // Exit the thread
     pthread_exit(NULL);
}

int main(void)
{
     // Declare thread variables
     pthread_t thread1;
     pthread_t thread2;

     // Create and start threads 1 and 2
     pthread_create(&thread1, NULL, function, "Thread 1");
     pthread_create(&thread2, NULL, function, "Thread 2");

     // Wait for both threads to finish before terminating the main function
     pthread_join(thread1, NULL);
     pthread_join(thread2, NULL);

     // Normal program termination
     return 0;
}