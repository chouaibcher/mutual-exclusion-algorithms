#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

int x = 0;
bool flag[2];

void *criticalSection()
{
    x++;
}

void *Thread1(void *arg)
{
    do
    {
        // Indicate that Thread 1 wants to enter the critical section
        flag[0] = true;

        // Wait while Thread 2 wants to enter the critical section
        while (flag[1])
        {
            // Relinquish the critical section if Thread 2 is active
            flag[0] = false;

        retry_thread1:
            // Busy-wait until Thread 2 finishes
            if (flag[1])
            {
                goto retry_thread1;
            }

            // Reassert that Thread 1 wants to enter the critical section
            flag[0] = false;
        }

        // Enter the critical section
        criticalSection();

        // Print the current value of the shared variable
        printf("thread 1 : %d \n", x);

        // Simulate some work in the critical section
        sleep(1);

        // Indicate that Thread 1 has exited the critical section
        flag[0] = false;
    } while (1); // Infinite loop
}

void *Thread2(void *arg)
{
    // Delay Thread 2 to allow Thread 1 to start first
    sleep(3);

    do
    {
        // Indicate that Thread 2 wants to enter the critical section
        flag[1] = true;

        // Wait while Thread 1 wants to enter the critical section
        while (flag[0])
        {
            // Relinquish the critical section if Thread 1 is active
            flag[1] = false;

        retry_thread2:
            // Busy-wait until Thread 1 finishes
            if (flag[0])
            {
                goto retry_thread2;
            }

            // Reassert that Thread 2 wants to enter the critical section
            flag[1] = false;
        }

        // Enter the critical section
        criticalSection();

        // Print the current value of the shared variable
        printf("thread 2 : %d \n", x);

        // Simulate some work in the critical section
        sleep(1);

        // Indicate that Thread 2 has exited the critical section
        flag[1] = false;
    } while (1); // Infinite loop
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