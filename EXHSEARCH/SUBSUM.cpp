#include<bits/stdc++.h>

using namespace std;

int N;
int B;
int X[10000];
int S[10000];
int SUM;
int CNT;

void SOLUTION()
{
    if(SUM == B)
    {
        CNT++;
    }
    
}

void INPUT()
{
    cin >> N >> B;
    for (int i = 1; i <= N; i++)
        cin >> X[i];
}

void TRY(int k)
{
    SUM += X[k];
    S[k] = 1;
    if(k == N)
        SOLUTION();
    else
    {
        
        TRY(k+1);
    }
        


    SUM -= 2 * X[k];
    S[k] = -1;
    if(k == N)
        SOLUTION();
    else
        TRY(k+1);

    SUM += X[k];
}




int main()
{
    INPUT();
    SUM = X[1];
    TRY(2);
    cout << CNT;
}