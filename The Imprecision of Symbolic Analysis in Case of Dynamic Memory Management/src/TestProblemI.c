//File name : TestProblemI.c
int a1,*b1,c1;

int func1(int a2,int *b2,int c2)
{
    b2 = &a2;
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
