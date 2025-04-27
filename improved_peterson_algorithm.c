#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

// Shared variable between threads
int x = 0;

// Flags to indicate if a thread wants to enter the critical section
bool flag[2];

// Variable to indicate whose turn it is to enter the critical section
bool turn;

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

        // Wait while Thread 2 wants to enter the critical section
        while (flag[1])
        {
            // If it's Thread 2's turn, relinquish the critical section
            if (turn == 1)
            {
                flag[0] = false;
            };

        wait_for_turn1:
            // Busy-wait until it's Thread 1's turn
            if (turn == 1)
            {
                goto wait_for_turn1;
            };

            // Reassert that Thread 1 wants to enter the critical section
            flag[0] = true;
        }

        // Enter the critical section
        criticalSection();

        // Print the current value of the shared variable
        printf("thread 1 : %d \n", x);

        // Simulate some work in the critical section
        sleep(1);

        // Give turn to Thread 2
        turn = 1;

    } while (1); // Infinite loop
}

// Thread 2 function
void *Thread2(void *arg)
{
    do
    {
        // Indicate that Thread 2 wants to enter the critical section
        flag[1] = true;

        // Wait while Thread 1 wants to enter the critical section
        while (flag[0])
        {
            // If it's Thread 1's turn, relinquish the critical section
            if (turn == 0)
            {
                flag[1] = false;
            };

        wait_for_turn2:
            // Busy-wait until it's Thread 2's turn
            if (turn == 0)
            {
                goto wait_for_turn2;
            };

            // Reassert that Thread 2 wants to enter the critical section
            flag[1] = true;
        }

        // Enter the critical section
        criticalSection();

        // Print the current value of the shared variable
        printf("thread 2 : %d \n", x);

        // Simulate some work in the critical section
        sleep(1);

        // Give turn to Thread 1
        turn = 0;

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

    // Normal program termination
    return 0;
}