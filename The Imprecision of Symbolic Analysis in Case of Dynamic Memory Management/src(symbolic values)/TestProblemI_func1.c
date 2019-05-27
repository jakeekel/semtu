#include <klee/klee.h>
//File name : TestProblemI.c
int a1,*b1,c1;

int func1(int a2,int *b2,int c2)
{
    b2 = &a2;
	klee_make_symbolic(&a2, sizeof(a2), "TestProblemI:7:func1:PARAMETER:INT:a2");
	b2 = malloc(4);
	klee_make_symbolic(b2,4, "TestProblemI:7:func1:PARAMETER:POINTER_INT:b2");
	klee_make_symbolic(&c2, sizeof(c2), "TestProblemI:7:func1:PARAMETER:INT:c2");
    if (a2 == 25 || *b2==50 || c2==100)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
    func1(a1,b1,c1);
}
