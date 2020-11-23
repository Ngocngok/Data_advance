#include<bits/stdc++.h>

using namespace std;

unsigned long long a[100];
unsigned long long c[100];

int n;
unsigned long long b;
unsigned long long tmpVal = 0;
unsigned long long totalVal = 0;
unsigned long long totalWeight = 0;



void TRY(int k)
{
    for(int i = k; i < n; i++)
    {
        if(totalWeight + a[i] <= b)
        {
            tmpVal += c[i];
            totalWeight += a[i];
            totalVal = totalVal < tmpVal ? tmpVal : totalVal; 
            TRY(i+1);
            tmpVal -= c[i];
            totalWeight -= a[i];
        }
    }
}


void INPUT()
{
    int cnt = 0;

    cin >> n >> b;
    for(cnt = 0; cnt < n; cnt++)
    {
        cin >> a[cnt] >> c[cnt];
    }
    return;
}


int main()
{
    INPUT();
    TRY(0);
    cout << totalVal;

    return 0;
}