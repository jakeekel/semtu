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
void test_func1_case_1()
{
	int pointer_value_1 = 0;
	func1(25,&pointer_value_1,0);
}
void test_func1_case_2()
{
	int pointer_value_1 = 50;
	func1(0,&pointer_value_1,0);
}
void test_func1_case_3()
{
	int pointer_value_1 = 0;
	func1(0,&pointer_value_1,0);
}
void test_func1_case_4()
{
	int pointer_value_1 = 0;
	func1(0,&pointer_value_1,100);
}
