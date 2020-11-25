#include<bits/stdc++.h>

using namespace std;


signed long long last;
int cnt;
int t; // test case
int N; // stall
int C; // cow
unsigned long long maxD;


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
    sort(x+1, x+N+1);
}

int countCow(unsigned long long lambda)
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
    //cout << lambda << ": " << cnt << endl;
    return cnt;
}

void SOLVE(unsigned long long L, unsigned long long R, unsigned long long lambda)
{
    L = 0;
    R = 1e9;
    while(L < R)
    {
        lambda = (L+R)/2;
        cnt = countCow(lambda);
        if(cnt < C)
            R = lambda-1;
        
        else 
            L = lambda;
        if(L == (L+R)/2)
        {
            lambda = (L+R)/2;
            break;
        }
        /*
        else 
        {
            for(unsigned long long i = R; i >= L; i--)
            {
                int tmp = countCow(i);
                if(tmp >= C)
                {
                    lambda = i;
                    break;
                }
            }
        }
        */
    }
    
    while ((true))
    {
        if(countCow(lambda+1) >= C)
        {
            lambda++;
        }
        else break;
    }
    
    cout << lambda << endl;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        INPUT();
        SOLVE(0,0,0);
    }
    

    return 0;
}
