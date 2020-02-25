//Out of bounds access example
#include <stdio.h>
#include <pthread.h>
int a,b;
pthread_t tid[2];
pthread_mutex_t lock_thread1,lock_thread2;

void* thread1(void *arg)
{
    pthread_mutex_lock(&lock_thread1);
	a=20;
    pthread_mutex_unlock(&lock_thread1);
}

void* thread2(void *arg)
{
    pthread_mutex_lock(&lock_thread2);
	if(a!=20)
    {
		b=10;
    }
	else
	{
	    b=5;
    }
    pthread_mutex_unlock(&lock_thread2);

    pthread_mutex_lock(&lock_thread2);
    if(a==20)
    {
        int c[5] = {1,2,3,4,5};
        for (int i = 0; i < b; i++)
        {
            printf("%d\n", c[i]);            
        }
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
    if(b==10)
    {
        printf("Error!\n");
        printf ("b = %d \n",b);
    }
  return 0;
}
