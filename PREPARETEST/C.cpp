#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e7;
int N, m, M;
int SUM = 0;
int ANS = 0;
int CNT = 0;
int X[MAX];
int S[MAX];

void INPUT()
{
    cin >> N >> m >> M;
    for(int i = 1; i <= N; i++)
    {
        cin >> X[i];
    }
}




void SOLVE()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j <= N; j++)
        {
            SUM += X[j];
            if(SUM >= m && SUM <= M)
            {
                ANS++;
            }
        }
        SUM = 0;
    }
}

int main()
{
    INPUT();
    SOLVE();
    cout << ANS;
}