#include<bits/stdc++.h>

using namespace std;

const double PI = 3.141592654;
int N;
int F;
int R[10001];

void INPUT()
{
    cin >> N >> F;
    for(int i = 0; i < N; i++)
    {
        cin >> R[i];
    }
}

void SOLVE()
{
    double vol = 0;
    for(int i = 0; i < N; i++)
    {
        vol += PI*R[i]*R[i];
    }
    
    printf("%.6f\n", vol / F);

}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        INPUT();
        SOLVE();
    }
}