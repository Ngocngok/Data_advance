#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5+2;
int M, N, CNT;
vector<int> X1[MAX]; //input map
vector<int> X2[MAX]; //reverse map
stack<int> S;

char COLOR[MAX];

void INPUT()
{
    cin >> N >> M;
    int tmp1, tmp2;
    for(int i = 1; i <= M; i++)
    {
        cin >> tmp1 >> tmp2;
        X1[tmp1].push_back(tmp2);
        X2[tmp2].push_back(tmp1);
    }
}

void DFS(int k)
{
    if(COLOR[k] == 'W')
    {
        COLOR[k] = 'B';
        
        for(int i = 0; i < X1[k].size(); i++)
        {
            DFS(X1[k][i]);
        }
        S.push(k);
    }
    
}

void DFS()
{
    for(int i = 1; i <= N; i++)
    {
        if(COLOR[i] == 'W')
        {
            DFS(i);
        }
    }
}

void DFS2(int k)
{
    if(COLOR[k] == 'W')
    {
        COLOR[k] = 'B';
        for(int i = 0; i < X2[k].size(); i++)
        {
            DFS2(X2[k][i]);
        }
    }
    
}

void DFS2()
{
    int i;
    while(!S.empty())
    {
        i = S.top();
        S.pop();
        if(COLOR[i] == 'W')
        {
            CNT++;
            DFS2(i);
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    INPUT();
    INIT();
    DFS();
    INIT();
    DFS2();
    cout << CNT;
}