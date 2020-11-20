#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull MOD = 1e9 + 7;

ull ADDMOD(ull a, ull b)
{
    return (a%MOD + b%MOD)%MOD;
}

ull MULMOD(unsigned long long a, unsigned long long b)
{
    if ( b == 1)
    return a * MOD;
    if (a == 1)
    return b % MOD;
    ull retval = 0;
    
    if (a < b) {
        unsigned long long tmp = a;
        a = b;
        b = tmp;
    }
        while(b> 0){
        if (b % 2 == 1)
        {
            retval = ADDMOD(retval,a);
        }
        b /= 2;
        a = ADDMOD(a,a);
        }
    
    return retval;
    
}

int main()
{
    ull n;
    cin >> n;
    ull tmp;
    ull tmp2;
    cin >> tmp;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> tmp2;
        tmp = MULMOD(tmp, tmp2);
    }
    cout << tmp;
}