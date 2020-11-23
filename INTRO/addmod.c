
#include <stdio.h>
 
int main()
{
    unsigned long long a, b, c;
 
    unsigned long long p = 1e9 + 7;
 
    scanf("%llu %llu", &a, &b);
 
    a = a%p;
    b = b%p;
    
    c = (a + b) % p;
 
    printf("%llu", c);
 
    return 0;
}