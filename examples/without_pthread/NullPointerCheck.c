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
	if(a!=50)
    {
        c = 5;
    }
	else
	{
        b = 'b';
    }

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

  printf("b = %c",b);
  return 0;
}
