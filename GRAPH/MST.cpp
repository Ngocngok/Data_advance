#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 2;
priority_queue< pair< int, pair<int, int> > > Q;
int P[MAX]; // check loop in graph
int M, N;
int W;

void INPUT()
{
    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int tmp1, tmp2, w;
        cin >> tmp1 >> tmp2 >> w;
        Q.push(pair<int, pair<int, int> >(-w, pair<int, int>(tmp1, tmp2)));
    }
}

void INIT()
{
    for(int i = 1; i <= N; i++)
        P[i] = -1;
}

bool ISCYCLE(int a, int b)
{
    int PA, PB;
    int tmp1 = a;
    while (true)
    {
        if(P[tmp1] == -1)
        {
            PA = tmp1;
            break;
        } 
        tmp1 = P[tmp1];
        if(tmp1 == b) return true;
    }

    tmp1 = b;
    while (true)
    {
        if(P[tmp1] == -1) 
        {
            PB = tmp1;
            break;
        }
        tmp1 = P[tmp1];
        if(tmp1 == a) return true;
    }

    if(PA == PB)
        return true;
    else
    {
        P[PA] = b;
        return false;
    }
    


}

void SOLVE()
{
    int cnt = 0;
    int tmp1, tmp2, w;
    while (cnt != N-1)
    {
        tmp1 = Q.top().second.first;
        tmp2 = Q.top().second.second;
        w = -Q.top().first;
        Q.pop();
        if(!ISCYCLE(tmp1, tmp2))
        {
            W += w;
            cnt++;
        }    
    }
    cout << W;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    INPUT();
    INIT();
    // while (!Q.empty())
    // {
    //     cout << Q.top().first << Q.top().second.first <<  Q.top().second.second;
    //     Q.pop();
    // }
    SOLVE();
    
    return 0;
}