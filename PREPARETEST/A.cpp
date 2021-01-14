#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int MAX = 1000+5;
int N;
int T;
ll RES;
priority_queue<ll> Q1;
priority_queue<ll> Q2;

void INPUT()
{
    cin >> N;
    int tmp;
    for(int i = 1; i <= N; i++)
    {
        cin >> tmp;
        Q1.push(-tmp);
    }
    for(int j = 1; j <= N; j++)
    {
        cin >> tmp;
        Q2.push(tmp);
    }

}

void CALC()
{
    ll tmp1, tmp2;
    while(!Q1.empty())
    {
        tmp1 = Q1.top();
        tmp1 = -tmp1;

        tmp2 = Q2.top();

        Q1.pop(); Q2.pop();

        RES += tmp1*tmp2;
    }
}

int main()
{
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        INPUT();
        CALC();
        cout << "Case #" << i << ": " << RES << endl;
        RES = 0;

    }
}