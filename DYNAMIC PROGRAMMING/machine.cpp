#include<bits/stdc++.h>


using namespace std;
const int N = 2e6 + 2;


int n;
int X[N][2];
int L[N]; // longest subsegment left-side of index i
int R[N]; //                    right



void INPUT()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> X[i][1] >> X[i][2];
    }
}

void PRESUB()
{
    for(int i = 1; i <= n; i++)
    {
        int s = X[i][1];
        int t = X[i][2];
        L[i] = 0; R[i] = 0;
        L[t] = max(L[t], t - s);
        R[s] = max(R[s], t - s);
    }

    for(int i = 1; i < n; i++)
    {
        L[i+1] = max(L[i+1], L[i]);
    }

    for(int i = n; i > 1; i--)
    {
        R[i] = max(R[i], R[i-1]);
    }
}

void SOLVE()
{
    int tmp = 0;
    for(int i = 1; i <= n; i++)
    {
        tmp = max(tmp, L[i] + R[i]);
    }
    cout << tmp;
}

int main()
{
    INPUT();
    PRESUB();
    SOLVE();
}