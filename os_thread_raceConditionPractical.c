#include <pthread.h>  // Provides functions for creating and managing threads
#include <stdio.h>    // Provides printf() for displaying output
#include <unistd.h>   // Provides sleep() to pause a thread

void *fun1(void *arg);  // Declaration of Thread 1 function
void *fun2(void *arg);  // Declaration of Thread 2 function

int shared = 1;  // Global variable shared by both threads; initial value is 1

int main()
{
    pthread_t thread1, thread2;  // Variables to store the thread identifiers

    // Create Thread 1 and execute the fun1() function
    pthread_create(&thread1, NULL, fun1, NULL);

    // Create Thread 2 and execute the fun2() function
    pthread_create(&thread2, NULL, fun2, NULL);

    // Wait for Thread 1 to finish execution
    pthread_join(thread1, NULL);

    // Wait for Thread 2 to finish execution
    pthread_join(thread2, NULL);

    // Display the final value of the shared variable
    printf("Final value of shared is %d\n", shared);

    return 0;  // End the main() function successfully
}

// Function executed by Thread 1
void *fun1(void *arg)
{
    int x;  // Declare a local variable for Thread 1

    x = shared;  // Read the current value of the shared variable
    printf("Thread1 reads the value of shared variable as %d\n", x);

    x++;  // Increment the local copy of the value by 1
    printf("Local updation by Thread1: %d\n", x);

    sleep(1);  // Pause Thread 1 for approximately one second

    shared = x;  // Write Thread 1's local value into the shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);

    return NULL;  // Finish Thread 1
}

// Function executed by Thread 2
void *fun2(void *arg)
{
    int y;  // Declare a local variable for Thread 2

    y = shared;  // Read the current value of the shared variable
    printf("Thread2 reads the value of shared variable as %d\n", y);

    y--;  // Decrement the local copy of the value by 1
    printf("Local updation by Thread2: %d\n", y);

    sleep(1);  // Pause Thread 2 for approximately one second

    shared = y;  // Write Thread 2's local value into the shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);

    return NULL;  // Finish Thread 2
}