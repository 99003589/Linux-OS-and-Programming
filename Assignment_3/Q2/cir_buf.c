#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

/*
This program provides a possible solution for producer-consumer problem using mutex and semaphore.
I have used 5 producers and 5 consumers to demonstrate the solution. You can always play with these values.
*/

#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

sem_t empty;
sem_t full;
int inp = 0;
int out = 0;
int buffer[BufferSize];

void *producer(void *pno)
{   
    int item;
    for(int k = 0; k < MaxItems; k++) {
        item = rand(); // Produce a random item
        sem_wait(&empty);
        /* wait for space in buffer */
        while (((inp + 1) % BufferSize) == out)
        {
        /* put value item into the buffer */
           buffer[inp] = item;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[inp],inp);
           inp = (inp + 1) % BufferSize;     
        }
        sem_post(&full);
    }
}
void *consumer(void *cno)
{   
    int item=0;
    for(int k = 0; k < MaxItems; k++) {
        sem_wait(&full);
        /* wait for buffer to fill */
        while (inp == out) 
        {
        /* take one unit of data from the buffer */
           item = buffer[out];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out); 
           out = (out + 1) % BufferSize;     
        }
        sem_post(&empty);
    }
}

int main()
{   

    pthread_t pro[5],con[5];
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int k = 0; k < 5; k++) {
        pthread_create(&pro[k], NULL, (void *)producer, (void *)&a[k]);
    }
    for(int k = 0; k < 5; k++) {
        pthread_create(&con[k], NULL, (void *)consumer, (void *)&a[k]);
    }

    for(int k = 0; k < 5; k++) {
        pthread_join(pro[k], NULL);
    }
    for(int k = 0; k < 5; k++) {
        pthread_join(con[k], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
