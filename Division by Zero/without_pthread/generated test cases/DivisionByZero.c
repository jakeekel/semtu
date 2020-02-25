//Division by zero example
int a,b,c;

void thread1()
{
	a=25;
}

void thread2() 
{
	if(a!=25)
    {
		b=15;
    }
	else
	{
	    b=30;
    }

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
void test_thread2_case_1()
{
	a = 25;
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
	//ON_DEMAND_SHARED_VARIABLE_CHANGE,20,a,25
	thread2();
}
void test_thread2_case_4()
{
	a = 25;
	//ON_DEMAND_SHARED_VARIABLE_CHANGE,20,a,25
	thread2();
}
void test_thread1_case_1()
{
	thread1();
}

