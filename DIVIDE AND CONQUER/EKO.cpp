#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;


int N;
ull M;
unsigned long X[1000002];

void INPUT()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> X[i];
}


ull CUT(int h)
{
    ull tmp = 0;
    for(int i = 1; i <= N; i++)
    {
        if(X[i] > h)
            tmp += (X[i] - h);
    }
    return tmp;
}

void SOLVE()
{
    int L = 0;
    int R = 1e9;
    int H;
    while(L<R)
    {
        H = (L+R)/2;

        if(CUT(H) >= M)
            L = H;
        else 
            R = H-1;
        
        if(L == (L+R)/2)
        {
            L = (L+R)/2;
            break;
        }
    }
    while(true)
    {
        if(CUT(L+1) < M)
        {
            break;
        }
        L = L + 1;
    }

    cout << L;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    INPUT();
    SOLVE();
    
    return 0;
}