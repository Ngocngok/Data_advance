#include <stdio.h>

unsigned long long addMod(unsigned long long a, unsigned long long b, unsigned long long p)
{
    a = a%p;
    b = b%p;
    
    return (a + b) % p;
 

}

int main()
{
    unsigned long long p = 1e9 + 7;
    unsigned long long ans = 0;
    long n;


    scanf("%ld\n", &n);
    if(n <= 0)
    {
        return 0;
    }

    unsigned long long arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%llu", &arr[i]);
    }

    ans = arr[0];

    for(int i = 1; i < n; i++)
    {
        ans = addMod(ans, arr[i], p);
    }

    printf("%llu", ans);



    return 0;
}