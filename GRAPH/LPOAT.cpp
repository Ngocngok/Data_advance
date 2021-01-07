#include<bits/stdc++.h>

using namespace std;

const int MAX = 100000 + 10;
int N;
vector< pair<int, int> > X[MAX]; // store both edge and weight of the edge
char COLOR[MAX];
int MAXW;
int TMPW;
int ENDP;


void INPUT()
{
    int tmp1, tmp2, w;
    cin >> N;
    for(int i = 1; i <= N-1; i++)
    {  
        cin >> tmp1 >> tmp2 >> w;
        X[tmp1].push_back(pair<int, int>(tmp2, w));
        X[tmp2].push_back(pair<int, int>(tmp1, w));
    }
}

void INIT()
{
    for(int i = 1; i <= N; i++)
    {
        COLOR[i] = 'W';
    }
    MAXW = 0;
    TMPW = 0;
}

void DFS(int k)
{
    for(int i = 0; i < X[k].size(); i++)
    {
        if(COLOR[ X[k][i].first ] == 'W')
        {
            
            COLOR[ X[k][i].first ] = 'B';
            TMPW += X[k][i].second;

            if(TMPW >= MAXW)
            {
                MAXW = TMPW;
                ENDP = X[k][i].first;
            }

            DFS(X[k][i].first);

            TMPW -= X[k][i].second;
        }
        
    }
    
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    INPUT();
    INIT();
    COLOR[1] = 'B';
    DFS(1);
    INIT();
    COLOR[ENDP] = 'B';
    DFS(ENDP);
    cout << MAXW;
}