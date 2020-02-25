//Read of unitialized variable example
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool x;
int a;

void thread1()
{
    a = 100;
}

void thread2()
{
    int y;

    if(a!=100)
    {
        y = 0;
    }
	else
	{
        x = true;
    }

    if(a==100)
    {
        if (x == true)
            y=1;
        else if (x == false)
            y=2;
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
    //ON_DEMAND_SHARED_VARIABLE_CHANGE,26,a,100
	thread2();
}
void test_thread2_case_4()
{
	a = 20;
    //ON_DEMAND_SHARED_VARIABLE_CHANGE,26,a,100
	thread2();
}
void test_thread1_case_1()
{
	thread1();
}
