#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

/*
This program provides a possible solution for producer-consumer problem using mutex and semaphore.
*/

#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

int inp = 0;
int out = 0;
int item=0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pno)
{   
    if(inp==BufferSize-1)
    {
        printf("Producer Stack is full \n");
    }
    else
    {
     for(int k = 0; k < MaxItems; k++) {
        item = rand(); // Produce a random item
        pthread_mutex_lock(&mutex);
        /* put value item into the buffer */
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[inp],inp);
        inp = (inp + 1) % BufferSize;     
        pthread_mutex_unlock(&mutex);
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
     for(int k = 0; k < MaxItems; k++) {
        pthread_mutex_lock(&mutex);
        /* take one unit of data from the buffer */
        item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out); 
        out = (out + 1) % BufferSize;     
        pthread_mutex_unlock(&mutex);
     }
    }
}

int main()
{   

    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);

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

    pthread_mutex_destroy(&mutex);

    return 0;
}
