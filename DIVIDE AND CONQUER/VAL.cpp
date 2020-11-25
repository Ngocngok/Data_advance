#include<bits/stdc++.h>

using namespace std;

int N;
int L;
double X[10002];

void INPUT()
{
    cin >> N >> L;
    for(int i = 0; i < N; i++)
    {
        cin >> X[i];
    }
}

double MAXINTERVAL()
{
    double maxX = 0;
    for(int i = 0; i < N - 1; i++)
    {
        double tmp = X[i+1] - X[i];
        if(tmp > maxX)
            maxX = tmp;
    }

    if(X[0] * 2 > maxX)
        maxX = X[0] * 2;
    if((L - X[N-1]) * 2 > maxX)
        maxX = (L - X[N-1]) * 2;

    return maxX;
}

void SOLVE()
{
    sort(X, X+N);
    printf("%.9f", MAXINTERVAL() / 2);
}

int main()
{
    INPUT();
    SOLVE();
}