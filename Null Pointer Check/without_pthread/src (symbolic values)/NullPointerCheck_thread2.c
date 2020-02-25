#include <klee/klee.h>
//Null pointer check example
#include <stdio.h>
#include <stdlib.h>

int a;
char b;

void thread1()
{
	a=50;
}

void thread2() 
{
    int c;
	klee_make_symbolic(&a, sizeof(a), "NullPointerCheck:16:thread2:GLOBAL:INT:a");
	if(a!=50)
    {
        c = 5;
    }
	else
	{
        b = 'b';
    }

	klee_make_symbolic(&a, sizeof(a), "NullPointerCheck:25:thread2:GLOBAL:INT:a");
    if(a==50)
    {
        if (b != NULL)
            c= 10;
    }
}

int main()
{
  thread1();
  thread2();
  return 0;
}
