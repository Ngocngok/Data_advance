#include <stdio.h>

unsigned long long addMod(unsigned long long a, unsigned long long b, unsigned long long p)
{
    a = a%p;
    b = b%p;
    
    return (a + b) % p;

}


//a*b mod p
unsigned long long mulMod(unsigned long long a, unsigned long long b, unsigned long long p)
{
    if ( b == 1)
    return a * p;
    if (a == 1)
    return b % p;
    unsigned long long retval = 0;
    
    if (a < b) {
        unsigned long long tmp = a;
        a = b;
        b = tmp;
    }
        while(b> 0){
        if (b % 2 == 1)
        {
            retval = addMod(retval,a,p);
        }
        b /= 2;
        a = addMod(a,a,p);
        }
    
    return retval;
    
}

unsigned long long expmod(unsigned long long a, unsigned long long b, unsigned long long p) 
{
    unsigned long long retval = 1;
    a = a % p;
    if ( a == 0) return 0;
    while (b > 0) {
        if ( b & 1)
            retval = mulMod(retval, a, p);
        b = b >> 1; // b/2
        a = mulMod(a,a,p);

    }
    return retval;

}


int main()
{
    unsigned long long a, b, ans;
    unsigned long long p = 1e9 + 7;

    scanf("%llu %llu", &a, &b);
    
    ans = expmod(a, b, p);
    

    printf("%llu", ans);
}