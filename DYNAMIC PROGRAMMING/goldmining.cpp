#include<bits/stdc++.h>

using namespace std;

const long N = 1e6 + 10;
int S[N];
int X[N];

long long total;
int L1, L2, n;

void INPUT()
{
    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; i++)
    {
        cin >> X[i];
    }
}

int MAXI(int k)
{
    int tmp = S[k-L1];

    for(int i = k-L1-1; i >= k-L2; i--)
    {
        if(S[i] >= tmp)
        {
            tmp = S[i];
        }
    }

    S[k] = tmp + X[k];

    return S[k];
}

void SOLVE()
{
    total = 0;
    for(int i = 1; i <= L1; i++)
    {
        S[i] = X[i];
    }

    for(int j = L1+1; j <= n; j++)
    {
        int tmp = MAXI(j);
        if(total < tmp)
        {
            total = tmp;
        }
    }

    cout << total;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    INPUT();
    SOLVE();
}