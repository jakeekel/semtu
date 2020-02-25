#include <klee/klee.h>
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

	klee_make_symbolic(&a, sizeof(a), "ReadOfUnitializedVariable:17:thread2:GLOBAL:INT:a");
    if(a!=100)
    {
        y = 0;
    }
	else
	{
        x = true;
    }

	klee_make_symbolic(&a, sizeof(a), "ReadOfUnitializedVariable:26:thread2:GLOBAL:INT:a");
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
