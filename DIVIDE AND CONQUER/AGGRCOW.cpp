#include<bits/stdc++.h>

using namespace std;


signed long long last;
unsigned long long cnt;
int t; // test case
int N; // stall
int C; // cow


unsigned long long x[100001];

void INIT()
{
    cnt = 0;
    last = - 1e9;
}

void INPUT()
{
    cin >> N >> C;
    for(int i = 1; i <= N; i++)
        cin >> x[i];
}

int countCow(int lambda)
{
    INIT();
    for(int i = 1; i <= N; i++)
    {
        if(x[i] - last >= lambda)
        {
            cnt++;
            last = x[i];   
        }
    }

    return cnt;
}

void SOLVE(unsigned long long L, unsigned long long R, int lambda)
{
    L = 0;
    R = 1e9;
    while(L < R -1)
    {
        lambda = (L+R)/2;
        cnt = countCow(lambda);
        if(cnt > C)
        {

        }
    }

}


int main()
