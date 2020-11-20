#include<bits/stdc++.h>

using namespace std;
bool appear[100];
int x[100];
int n;
void solution()
{
  for(int i = 0; i <= n; i++) cout << x[i] << " "; cout << endl; 
}

void TRY(int k)
{
  for(int v = 0; v <= n; v++){
    if(!appear[v]){
      appear[v] = true;
      x[k] = v;
      if(k == n) solution();
      else TRY(k+1);
      appear[v] = false;
    }
  }
}

int main()
{
  n = 4;
  TRY(0);
}
