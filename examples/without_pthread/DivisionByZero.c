//Division by zero example
int a,b,c;

void thread1()
{
	a=10;
}

void thread2() 
{
	if(a!=10)
    {
		b=9;
    }
	else
	{
	    b=10;
    }

    if(a==10)
    {
        c=1/(b-9);
    }
}

int main()
{
  thread1();
  thread2();

  return 0;
}
