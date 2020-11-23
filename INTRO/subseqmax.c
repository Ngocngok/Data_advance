#include <stdio.h>

int main()
{
    long a;


    scanf("%li\n", &a);
    if(a <= 0)
    {
        return 0;
    }

    long long arr[a];
    for(long i = 0; i < a; i++)
    {
        scanf("%lld", &arr[i]);
    }

    long long max = arr[0];
    long long cur = arr[0];
    if(cur < 0)
    {
        cur = 0;
    }
    

    for(long j = 1; j < a; j++)
    {
        if(cur >=0)
        {
            if(cur + arr[j] >= 0)
            {
                cur += arr[j];
                if(cur > max)
                {
                    max = cur;
                }
                continue;
            }
            else
            {
                cur = 0;
            }
            
        }
        
        else
        {
            if(max < arr[j])
            {
                max = arr[j];
            }
            cur = 0;
            continue;
        }
    }

    printf("%lli", max);

    return 0;
}