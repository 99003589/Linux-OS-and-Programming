#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int arr[10]={2,4,6,8,10,12,14,16,18,20};

void* sum(void* p)
{
	int i=*(int*)p;
	printf("%d",arr[i]);
	free(p);
}

int main()
{
	pthread_t arr[10];
	for(int i=0; i<10; i++)
	{
		int* a=malloc(sizeof(int));
		*a=i;
		if(pthread_create(&arr[i],NULL,&sum,a)!=0)
		{
			perror("failed to create thread\n");
		}		
	}
	for(i=0; i<10; i++)
	{
		if(pthread_join(arr[i],NULL)!=0)
		{
			perror("failed to join thread\n");
		}
	}
	return 0;
}
