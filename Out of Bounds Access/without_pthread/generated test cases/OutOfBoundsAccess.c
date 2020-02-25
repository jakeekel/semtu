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
            i+=2;          
        }
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
	a = 20;
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
    //ON_DEMAND_SHARED_VARIABLE_CHANGE,21,a,20
	thread2();
}
void test_thread2_case_4()
{
	a = 20;
    //ON_DEMAND_SHARED_VARIABLE_CHANGE,21,a,20
	thread2();
}
void test_thread1_case_1()
{
	thread1();
}

