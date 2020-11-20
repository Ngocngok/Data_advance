#include<bits/stdc++.h>

using namespace std;

int X[100];
int n;
int cnt;

bool check(int x, int y)
{
  return true;
}

void solution(){
  cnt++;
  cout << "solution: " << cnt << ": ";
  for(int i = 1; i <= n; i++) cout << X[i] << " "; cout << endl; 
}

void TRY(int k){
  for(int y= 0; y <=1; y++) 
    if(check(y, k)){
      X[k] = y;
      if(k == n) solution();
      else TRY(k+1);
    }
    
}

int main(){
  n = 10;
  cnt = 0;
  TRY(1);
}

