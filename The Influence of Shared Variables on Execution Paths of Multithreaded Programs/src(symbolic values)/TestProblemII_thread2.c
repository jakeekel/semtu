//File name : TestProblemII.c
#include <klee/klee.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a,b,c;
pthread_mutex_t lock;

void* thread1(void* arg)
{
	a=10;
}

void* thread2(void* arg)
{
    pthread_mutex_lock(&lock);
	klee_make_symbolic(&a, sizeof(a), "TestProblemII:17:thread2:GLOBAL:INT:a");
	if(a!=10)
    {
		b=9;
    }
	else
	{
	    b=10;
    }
    pthread_mutex_unlock(&lock);

    pthread_mutex_lock(&lock);
	klee_make_symbolic(&a, sizeof(a), "TestProblemII:28:thread2:GLOBAL:INT:a");
    if(a==10)
    {
        c=1/(b-9);
    }
    pthread_mutex_unlock(&lock);
}

int main()
{
	pthread_t t[2];
	pthread_mutex_init(&lock, NULL);

	//pthread_create( &t[0], NULL, &thread1, NULL);
	//pthread_create( &t[1], NULL, &thread2, NULL);

    //pthread_join(t[0], NULL);
    //pthread_join(t[1], NULL);
    pthread_mutex_destroy(&lock);
	return 0;
}