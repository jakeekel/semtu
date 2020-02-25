// Data race example
#include <stdio.h>

int a,b,c;

void thread1()
{
	a=150;
    b = 10;
}

void thread2() 
{
    int c=0;
	if(a!=150)
    {
        c -=b;        
    }
	else
	{
        c +=b;
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
	a = 150;
	thread2();
}
void test_thread2_case_2()
{
	a = 0;
	thread2();
}
void test_thread1_case_1()
{
	thread1();
}

