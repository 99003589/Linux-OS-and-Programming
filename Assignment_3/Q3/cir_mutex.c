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

int inp = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pno)
{   
    int item;
    for(int l = 0; l < MaxItems; l++) {
        item = rand(); // Produce a random item
        pthread_mutex_lock(&mutex);
        /* wait for space in buffer */
        while (((inp + 1) % BufferSize) == out)
        {
        /* put value item into the buffer */
           buffer[inp] = item;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[inp],inp);
           inp = (inp + 1) % BufferSize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *cno)
{   
    int item=0;
    for(int l = 0; l < MaxItems; l++) {
        pthread_mutex_lock(&mutex);
        /* wait for buffer to fill */
        while (inp == out) 
        {
        /* take one unit of data from the buffer */
           item = buffer[out];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out); 
           out = (out + 1) % BufferSize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{   

    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);

    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int l = 0; l < 5; l++) {
        pthread_create(&pro[l], NULL, (void *)producer, (void *)&a[l]);
    }
    for(int l = 0; l < 5; l++) {
        pthread_create(&con[l], NULL, (void *)consumer, (void *)&a[l]);
    }

    for(int l = 0; l < 5; l++) {
        pthread_join(pro[l], NULL);
    }
    for(int l = 0; l < 5; l++) {
        pthread_join(con[l], NULL);
    }

    pthread_mutex_destroy(&mutex);
    
    return 0;
}
