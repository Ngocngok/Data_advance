#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int> A[N];
int n,m;
bool arti[N];// arti[v] = true indicates that v is an articulation point
int num[N], low[N]; //num is visited time
int t;// time-point variable
int root, numChild;
int nbArticulations, nbBridges;
void input(){
    cin >> n >> m;
    for(int i =1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void dfs(int u, int pu){// pu is the parent of u during DFS
    num[u] = low[u] = ++t;
    cout << "begin dfs(" << u << "), low, num = " << low[u] << "," << num[u] << endl;
    for(int i = 0; i < A[u].size(); i++)
    {
        int v = A[u][i];
        if(num[v] == -1)
        {// not visited
            if(u == root) numChild++;
            dfs(v,u);
            low[u] = min(low[u],low[v]);
           cout << "dfs(v = " << v << ") finished, low,num[" << v << "] = " << low[v] << "," << num[v];
            cout << " low,num[" << u << "] = " << low[u] << "," << num[u] << endl;
            if(low[v] >= num[u])
            {
                    arti[u] = true;
                cout << "FOUND ARTI " << u << endl;
            }
            if(low[v] == num[v]) nbBridges++;
        }else
        {
            if(v != pu){
                    low[u] = min(low[u],num[v]);
                cout << "visited " << v << " -> update low[" << u << "] = " << low[u] << endl;
            }
        }
    }
}
void solve(){
    for(int v = 1; v <= n; v++){
        num[v] = -1;
        arti[v] = false;
    }
    nbArticulations = nbBridges = 0;

    for(int v = 1; v <= n; v++)if(num[v] == -1){ //check root is arti
        root = v; numChild = 0;
        t = 0;
        dfs(v,-1);
        if(numChild <= 1) arti[root] = false;
    }

    for(int v = 1; v <= n; v++) if(arti[v]) nbArticulations++;
    cout << nbArticulations << " " << nbBridges;
}
int main(){
    input();
    solve();
}
