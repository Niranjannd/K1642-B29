#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>
int arr[100];
int n;

 void child()
{
int i,x;
printf("Enter no,s in Fibbonacci Series:");
scanf("%d",&x);
if(x<0)
{	printf("Number not valid , Enter right no:");
}
else{
	
n=x;
arr[0]=0;
arr[1]=1;
for(i=2;i<n;i++)
{
	arr[i]=arr[i-1]+arr[i-2];
}
}
}
void parent()
{
sleep(5);
int i;
printf("Fibbonnacci  Series is: ");
for(i=0;i<n;i++)
{
	printf("%d \t",arr[i]);
}
}
void main()
{
pthread_t th1,th2;
pthread_create(&th1,NULL,child,NULL);
pthread_create(&th2,NULL,parent,NULL);
pthread_join(th1,NULL);
pthread_join(th2,NULL);
}
