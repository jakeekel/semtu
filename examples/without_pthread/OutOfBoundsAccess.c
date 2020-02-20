//Out of bounds access example
#include <stdio.h>
int a,b;

void thread1()
{
	a=20;
}

void thread2() 
{
	if(a!=20)
    {
		b=10;
    }
	else
	{
	    b=5;
    }

    if(a==20)
    {
        int c[5] = {1,2,3,4,5};
        for (int i = 0; i < b; i++)
        {
            printf("%d\n", c[i]);            
        }
    }
}

int main()
{
  thread1();
  thread2();

  return 0;
}
