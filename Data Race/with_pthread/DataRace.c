// Data race example
#include <stdio.h>
#include<pthread.h>

pthread_t tid[2];
pthread_mutex_t lock_thread1,lock_thread2;
int a,b,c;

void thread1()
{
    pthread_mutex_lock(&lock_thread1);
	a=150;
    b = 10;
    pthread_mutex_unlock(&lock_thread1);
}

void thread2() 
{
    int c=0;
    pthread_mutex_lock(&lock_thread2);
	if(a!=150)
    {
        c -=b;        
    }
	else
	{
        c +=b;
    }
    pthread_mutex_unlock(&lock_thread2);

    pthread_mutex_lock(&lock_thread2);
    if(a==150)
    {
        c +=b;
        //printf("c = %d\n",c);
    }
    pthread_mutex_unlock(&lock_thread2);
}

int main()
{
    a = 0;
    pthread_create(&(tid[0]), NULL, &thread1, NULL);
    pthread_create(&(tid[1]), NULL, &thread2, NULL);
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock_thread1);
    pthread_mutex_destroy(&lock_thread2);


    printf("c = %d\n",c);
    
    return 0;
}
