include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

/*
This program provides a possible solution for producer-consumer problem using mutex and semaphore.
*/

#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

sem_t empty;
sem_t full;
int inp = 0;
int out = 0;
int item=0;
int buffer[BufferSize];

void *producer(void *pno)
{   
    if(inp==BufferSize-1)
    {
        printf("Producer Stack is full \n");
    }
    else
    {
     for(int j = 0; j < MaxItems; j++) {
        item = rand(); // Produce a random item
        sem_wait(&empty);
        /* put value item into the buffer */
        buffer[inp] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[inp],inp);
        in = (inp + 1) % BufferSize;     
        sem_post(&full);
     }
    }
}
void *consumer(void *cno)
{   
    if(out==BufferSize-1)
    {
        printf("Consumer Stack is full\n");
    }
    else
    {
     int item=0;
     for(int j = 0; j < MaxItems; j++) {
        sem_wait(&full);
        /* take one unit of data from the buffer */
        item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out); 
        out = (out + 1) % BufferSize;     
        sem_post(&empty);
     }
    }
}

int main()
{   

    pthread_t pro[5],con[5];
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);

    int a[10] = {1,2,3,4,5,6,7,8,9,10}; //Just used for numbering the producer and consumer

    for(int j = 0; j < 5; j++) {
        pthread_create(&pro[j], NULL, (void *)producer, (void *)&a[j]);
    }
    for(int j = 0; j < 5; j++) {
        pthread_create(&con[j], NULL, (void *)consumer, (void *)&a[j]);
    }

    for(int j = 0; j < 5; j++) {
        pthread_join(pro[j], NULL);
    }
    for(int j = 0; j < 5; j++) {
        pthread_join(con[j], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
