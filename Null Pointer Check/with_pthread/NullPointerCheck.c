//Null pointer check example
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a;
char b;
pthread_t tid[2];
pthread_mutex_t lock_thread1,lock_thread2;

void* thread1(void *arg)
{
    pthread_mutex_lock(&lock_thread1);
	a=50;
    pthread_mutex_unlock(&lock_thread1);
}

void* thread2(void *arg)
{
    int c;
    pthread_mutex_lock(&lock_thread2);
	if(a!=50)
    {
        c = 5;
    }
	else
	{
        b = 'b';
    }
    pthread_mutex_unlock(&lock_thread2);

    pthread_mutex_lock(&lock_thread2);
    if(a==50)
    {
        if (b != NULL)
            c= 10;
    }
    pthread_mutex_unlock(&lock_thread2);
}

int main()
{
    pthread_create(&(tid[0]), NULL, &thread1, NULL);
    pthread_create(&(tid[1]), NULL, &thread2, NULL);
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock_thread1);
    pthread_mutex_destroy(&lock_thread2);
    if(b == NULL)
    {
        printf("Error!\n");
        printf ("a = %d , b = %c\n",a,b);
    }
    return 0;
}
