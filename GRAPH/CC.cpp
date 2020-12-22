#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
int M, N, CNT;
vector<int> X[MAX];
char COLOR[MAX];

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

void DFS(int k)
{
    if(COLOR[k] == 'W')
    {
        COLOR[k] = 'B';
        for(int i = 0; i < X[k].size(); i++)
        {
            DFS(X[k][i]);
        }
    }
    
}

void DFS()
{
    for(int i = 1; i <= N; i++)
    {
        if(COLOR[i] == 'W')
        {
            CNT++;
            DFS(i);
        }
    }
}

void INIT()
{
    CNT = 0;
    for(int i = 0; i <= N; i++)
        COLOR[i] = 'W';
}

int main()
{
    INPUT();
    INIT();
    DFS();
    cout << CNT;
}