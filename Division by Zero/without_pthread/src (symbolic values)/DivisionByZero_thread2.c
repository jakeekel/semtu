#include <klee/klee.h>
//Division by zero example
int a,b,c;

void thread1()
{
	a=25;
}

void thread2() 
{
	klee_make_symbolic(&a, sizeof(a), "DivisionByZero:11:thread2:GLOBAL:INT:a");
	if(a!=25)
    {
		b=15;
    }
	else
	{
	    b=30;
    }

	klee_make_symbolic(&a, sizeof(a), "DivisionByZero:20:thread2:GLOBAL:INT:a");
    if(a==25)
    {
        c=45/(b-15);
    }
}

int main()
{
  thread1();
  thread2();

  return 0;
}
