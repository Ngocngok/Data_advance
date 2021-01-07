#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5+2;
int N;
vector<int> X[MAX];
char COLOR[MAX];
int PARENT[MAX];

void INPUT()
{
    cin >> N;
    int tmp1, tmp2;
    for(int i = 1; i <= N-1; i++)
    {
        cin >> tmp1 >> tmp2;
        X[tmp1].push_back(tmp2);
        X[tmp2].push_back(tmp1);
    }
}

void INIT()
{
    for(int i = 0; i <= N; i++)
    {
        COLOR[i] = 'W';
        PARENT[i] = 0;
    }
        
}

void DFS(int k)
{
    
    for(int i = 0; i < X[k].size(); i++)
    {
        if(COLOR[X[k][i]] == 'W')
        {
            
            COLOR[ X[k][i] ] = 'B';
            PARENT[X[k][i]] = k;
            // cout << "DFS " << k << X[k][i]; 
            DFS(X[k][i]);
        }
    }
}

int main()
{
    INPUT();
    INIT();
    COLOR[1] = 'B';
    DFS(1);

    for(int i = 2; i <= N; i++)
        cout << PARENT[i] << " ";
}