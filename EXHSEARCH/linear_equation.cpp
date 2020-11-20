#include<bits/stdc++.h>

using namespace std;

int M;
int x[100];
int n;
int T;

void solution()
{
  for(int i = 1; i <= n; i++) cout << x[i] << " ";cout << endl;
}

bool check(int v, int k)
{
  if(k < n) return true;
  return T + v == M;
}

void TRY(int k){
  for(int v = 0; v<= M - T - n + k; v++){
    if(check(v, k)){
      x[k] = v;
      T = T + v;
      if(k == n) solution();
      else{
	TRY(k+1);
      }
      T = T - v;
    }
  }
}

int main()
{
  n = 3; M = 5;
  T = 0;
  TRY(1);
}
