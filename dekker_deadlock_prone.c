#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

// Shared variable between threads
int x = 0;

// Flags to indicate if a thread wants to enter the critical section
bool flag[2];

// Critical section function
void *criticalSection()
{
     // Increment the shared variable
     x++;
}

// Thread 1 function
void *Thread1(void *arg)
{
     do
     {
          // Indicate that Thread 1 wants to enter the critical section
          flag[0] = true;

     wait_for_thread2:
          // Busy-wait if Thread 2 is in the critical section
          if (flag[1])
          {
               goto wait_for_thread2;
          }

          // Enter the critical section
          criticalSection();
          printf("thread 1 : %d \n", x);

          // Indicate that Thread 1 has exited the critical section
          flag[0] = false;

     } while (1); // Infinite loop
}

// Thread 2 function
void *Thread2(void *arg)
{
     do
     {
          // Indicate that Thread 2 wants to enter the critical section
          flag[1] = true;

     wait_for_thread1:
          // Busy-wait if Thread 1 is in the critical section
          if (flag[0])
          {
               goto wait_for_thread1;
          }

          // Enter the critical section
          criticalSection();
          printf("thread 2 : %d \n", x);

          // Indicate that Thread 2 has exited the critical section
          flag[1] = false;

     } while (x < 10); // Loop until the shared variable reaches 10
}

int main(void)
{
     // Declare thread variables
     pthread_t t1;
     pthread_t t2;

     // Create and start Thread 1 and Thread 2
     pthread_create(&t1, NULL, Thread1, (void *)NULL);
     pthread_create(&t2, NULL, Thread2, (void *)NULL);

     // Wait for both threads to finish
     pthread_join(t1, NULL);
     pthread_join(t2, NULL);

     // Print the final value of the shared variable
     printf("  x= %d", x);

     // Normal program termination
     return 0;
}