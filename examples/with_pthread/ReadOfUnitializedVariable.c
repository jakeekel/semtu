//Read of unitialized variable example
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool x;
int a;
pthread_t tid[2];
pthread_mutex_t lock_thread1,lock_thread2;

void* thread1(void *arg)
{
    pthread_mutex_lock(&lock_thread1);
    a = 100;
    pthread_mutex_unlock(&lock_thread1);
}

void* thread2(void *arg)
{
    int y;
    pthread_mutex_lock(&lock_thread2);
    if(a!=100)
    {
        y = 0;
    }
	else
	{
        x = true;
    }
    pthread_mutex_unlock(&lock_thread2);

    pthread_mutex_lock(&lock_thread2);
    if(a==100)
    {
        if (x == true)
            y=1;
        else if (x == false)
            y=2;
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
    if(x == NULL)
    {
        printf("Error!\n");
        printf ("x = %d\n",x);
    }

    return 0;
}
