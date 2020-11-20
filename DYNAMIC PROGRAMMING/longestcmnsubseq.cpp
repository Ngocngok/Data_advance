#include<bits/stdc++.h>

using namespace std;

int m, n;
int X[10002];
int Y[10002];
int S[10002][10002];
int MAX;
int trace[10][10];

int cur[10002];
void INPUT()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> X[i];
    for(int j = 1; j <= m; j++)
        cin >> Y[j];
}

void CHECK(int i, int j)
{
    if(X[i] == Y[j])
    {
        S[i][j] = S[i-1][j-1] + 1;
    }
         
    else
    {
        if(S[i][j-1] > S[i-1][j])
            S[i][j] = S[i][j-1];
        else
            S[i][j] = S[i-1][j];
        
    }

    if (S[i][j] >= MAX)
        MAX = S[i][j];
    
}

void SOLVE()
{

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            CHECK(i, j);
        }

    cout << MAX;
}

int main()
{
    INPUT();
    SOLVE();
}