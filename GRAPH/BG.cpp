#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 10;

vector<int> X[MAX];
int N, M;
int STATE[MAX]; // 0: unvisited
int C; // to assign value for the node
int ANS;

void INPUT()
{
    cin >> N >> M;
    int tmp1, tmp2;
    for(int i = 1; i <= M; i++)
    {
        cin >> tmp1 >> tmp2;
        X[tmp1].push_back(tmp2);
        X[tmp2].push_back(tmp1);
    }
}

void INIT()
{
    for(int i = 1; i <= N; i++)
    {
        STATE[i] = -1;
    }
    C = 0;
    ANS = 1;
}

void DFS(int k)
{
    STATE[k] = C%2;
    C++;
    for(int i = 0; i < X[k].size(); i++)
    {
        if(STATE[ X[k][i] ] == -1)
        {
            DFS(X[k][i]);
        }
        else
        {
            if( STATE[ X[k][i] ] == STATE[k])
                ANS = 0;
        }
    }
    C--;
}

int main()
{
    INPUT();
    INIT();
    DFS(1);
    cout << ANS;
}