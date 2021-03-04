#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define max 10
#define Tmax 3

int a[max]={1,3,5,7,9,11,13,15,17,19};
int max_num[Tmax]={0};
int min_num[Tmax]={0};
int threadno=0;
void maximini(void* arg)
{
    int j, num=threadno++;
    int maxi=0,mini=0;
    for(j=num*(max/3);j<(num+1)*(max/3);j++)
    {
        if(a[j]>maxi)
            maxi=a[j];
        if(a[i]<maxi)
            mini=a[j];
    }
    max_number[num]=maxi;
    min_number[num]=mini;
}

int main()
{
    int maximum=0,minimum=0;
    int k;
    pthread_t threads[Tmax];
    for(k=0;k<Tmax;k++)
        pthread_create(&threads[k],NULL,|maximini,(void*)NULL);
    for (k=0;k<Tmax;k++)
        pthread_join(threads[k],NULL);
    for (k=0;k<Th_max;k++)
    {
        if (max_number[k]>maximum)
            maximum=max_number[k];
        if (min_number[k]<minimum)
            minimum=min_number[k];
    }
    printf("Maximum Element is : %d",maximum);
    printf("Minimum Element is : %d",minimum);
    return 0;
}
