#include<bits/stdc++.h>
#include<vector>

using namespace std;

const int MAX = 1e6;

int N, M;
char COLOR[MAX];
vector<int> X1[MAX]; //list of adjancent nodes of node X[i]
vector<int> X2[MAX];

int ICC[MAX]; 
int NCC; //number of connected components

stack<int> STACK;

void INPUT()
{
    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        X1[tmp1].push_back(tmp2);
        X2[tmp2].push_back(tmp1);
    }
}

void DFS1(int u)
{
    COLOR[u] = 'O';
    ICC[u] = NCC;
    for(int i = 0; i < X1[u].size(); i++)
    {
        int v = X1[u][i];
        if(COLOR[v] == 'W')
            DFS1(v);
    }
    STACK.push(u);      
}

void DFS2(int u)
{
    COLOR[u] = 'O';
    ICC[u] = NCC;
    for(int i = 0; i < X2[u].size(); i++)
    {
        int v = X2[u][i];
        if(COLOR[v] == 'W')
            DFS2(v);
    }
    STACK.push(u);      
}

void DFS1()
{
    for(int v = 1; v <= N; v++)
    {
        COLOR[v] = 'W';
    }
    NCC = 0;
    for(int v = 1; v <= N; v++)
    {
        if(COLOR[v] == 'W')
        {
            NCC++;
            DFS1(v);
        }
    }
}

void DFS2()
{
    NCC = 0;
    for(int v = 1; v <= N; v++)
    {
        COLOR[v] = 'W';
    }
    while(!STACK.empty())
    {
        if(COLOR[STACK.top()] == 'W')
        {
            NCC++;
            DFS2(STACK.top());
        }
        STACK.pop();
    }
}




void SOLVE()
{
   DFS1();
   DFS2();
   cout << NCC;

}



int main()
{
    INPUT();
    SOLVE();
}