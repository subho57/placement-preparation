int prime(double x)
    {
        int a=0; double i=0.0;
        for(i=2;i<=sqrt(x);i++)
        {
            if(x%i==0)
            a++;
        }
        if(a==0)
        return 1;
        else
        return 0;
    }
main()
    {
        double n=600851475143.0; double i=0.0;
        for(i=n;i>=1.0;i--)
        {
            if(n%i==0 && prime(i)==1)
            {
                printf("Largest Prime factor = %d%", i);
                break;
            }
            
        }
    }
