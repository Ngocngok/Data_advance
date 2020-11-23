#include<bits/stdc++.h>

using namespace std;

int x, y, m, n;

int maze[900][900]; // 0 is traversable
//bool visited[899][899];

queue<pair<int, int> > Q;
map<pair<int, int>, int> M;


bool isValid(int x, int y)
{
    return(!(maze[x][y]));// || visited[x][y]));
}

int solve()
{
    /*
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = false;
    */
    int cr[4] = {-1, 1, 0, 0};
    int cc[4] = {0, 0, -1, 1};


    pair<int, int> current = pair<int, int>(x, y);
    if(x == 0 || x == m-1 || y == 0 || y == n-1)
    {
        return 1;
    }

    Q.push(current);
    M[current] = 1;

    while(!Q.empty())
    {
        current = Q.front();
        Q.pop();

        

        for(int i = 0; i < 4; i++)
        {
            if(isValid(current.first + cr[i], current.second + cc[i]))
            {
                if(current.first + cr[i] == 0 || current.first + cr[i] == m-1 || current.second + cc[i] == 0 || current.second + cc[i] == n-1)
                {
                    return M[pair<int, int>(current.first, current.second)] + 1;
                }
                M[pair<int, int>(current.first + cr[i], current.second + cc[i])] = M[pair<int, int>(current.first, current.second)] + 1;
                Q.push(pair<int, int>(current.first + cr[i], current.second + cc[i]));
                maze[current.first + cr[i]][current.second + cc[i]] = 1;
            }
    
        }

    }

    return -1;



}

int main()
{
    cin >> m >> n >> x >> y;
    x--;
    y--;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    

    cout << solve() ;
    
}