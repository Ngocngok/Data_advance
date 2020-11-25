#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;

PII X[50002];
int N;

void INPUT()
{
    cin >> N;
    int x, y;
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        X[i] = make_pair(x, y);
    }
}

float CALC(PII i, PII j)
{
    return sqrt((i.first - j.first)*(i.first - j.first) + (i.second - j.second)*(i.second - j.second));
    
}

void SOLVE()
{
    int index1 = 0;
    int index2 = 0;
    float minVal = 1e6;

    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(CALC(X[i], X[j]) < minVal)
            {
                minVal = CALC(X[i], X[j]);
                index1 = i;
                index2 = j;
            }
        }
    }

    printf("%d %d %.6f", index1, index2, minVal);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    INPUT();
    SOLVE();
    return 0;
}