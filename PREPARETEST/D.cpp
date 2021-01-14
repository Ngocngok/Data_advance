#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e7;
int N;
int MAXH, MAXD;
int X[MAX];
int S[MAX]; //1 for U, 2 for D 

void INPUT()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> X[i];
}

void INIT()
{
    int tmp = X[0];
    for(int i = 1; i < N; i++)
    {
        if(X[i] > tmp)
            S[i] = 1;
        else if(X[i] < tmp)
            S[i] = -1;
        else 
            S[i] = 0;
        tmp = X[i];
    }
}

void SOLVE()
{
    int U = 0;
    int D = 0;
    int state = 0; 
    for(int i = 1; i < N; i++)
    {
        if(S[i] > 0)
        {
            if(state == 0)
            {
                state = 1;
                U++;
            }
            else if(state == 1)
                U++;
            else
            {
                state = 1;
                MAXH = max(MAXH, min(U, D));
                U = 1;
                D = 0;
            }
        }

        else if(S[i] < 0)
        {
            if(state == 0)
                continue;
            else if(state == -1)
                D++;
            else
            {
                state = -1;
                D++;
            }
        }
        else
        {
            if(state == 0)
                continue;
            else if(state == -1)
            {
                state = 0;
                MAXH = max(MAXH, min(U, D));
                U = 0;
                D = 0;
            }
            else
            {
                state = 0;
                U = 0;
                D = 0; 
            }
        }
    }
    MAXH = max(MAXH, min(U, D));

    
    U = 0;
    D = 0;
    state = 0; 
    for(int i = N-1; i > 0; i--)
    {
        if(S[i] > 0)
        {
            if(state == 0)
            {
                state = 1;
                U++;
            }
            else if(state == 1)
                U++;
            else
            {
                state = 1;
                MAXD = max(MAXD, min(U, D));
                U = 1;
                D = 0;
            }
        }

        else if(S[i] < 0)
        {
            if(state == 0)
                continue;
            else if(state == -1)
                D++;
            else
            {
                state = -1;
                D++;
            }
        }
        else
        {
            if(state == 0)
                continue;
            else if(state == -1)
            {
                state = 0;
                MAXD = max(MAXD, min(U, D));
                U = 0;
                D = 0;
            }
            else
            {
                state = 0;
                U = 0;
                D = 0; 
            }
        }
    }
    MAXD = max(MAXD, min(U, D));
}

int main()
{
    INPUT();
    INIT();
    SOLVE();
    cout << MAXH << " " << MAXD;
}