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
  return 0;
}
void test_thread2_case_1()
{
	a = 50;
	a = 0;
	thread2();
}
void test_thread2_case_2()
{
	a = 0;
	a = 0;
	thread2();
}
void test_thread2_case_3()
{
	a = 0;
	//ON_DEMAND_SHARED_VARIABLE_CHANGE,25,a,50
	thread2();
}
void test_thread2_case_4()
{
	a = 50;
	//ON_DEMAND_SHARED_VARIABLE_CHANGE,25,a,50
	thread2();
}
void test_thread1_case_1()
{
	thread1();
}
