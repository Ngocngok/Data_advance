#include<bits/stdc++.h>

using namespace std;

int x[10][10];
bool mr[10][10];
bool mc[10][10];
bool mrc[4][4][10];
bool found;

bool solution()
{
  found = true;
  for(int i = 1; i <= 9; i++){
    for(int j = 1; j <= 9; j++){
      cout << x[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
}

bool check(int v, int r, int c)
{
  return !mr[r][v] && ! mc[c][v] &&! mrc[(r-1)/3+1][(c-1)/3+1][v];
  //return !mr[r][v] && ! mc[c][v] &&! mrc[r/3 + r%3][(c-1)/3+1][v];
}

void TRY(int r, int c){
  if(found) return;
  for(int v = 1; v <= 9; v++){
    if(check(v, r, c)){
      x[r][c] = v;
      mr[r][v] = true;
      mc[c][v] = true;
      mrc[(r-1)/3+1][(c-1)/3+1][v] = true;

      if(r == 9 && c == 9){
	solution();break;
      }
      else{
	if(c==9) TRY(r+1,1);
	else TRY(r, c+1);
      }
      mr[r][v] = false;
      mc[c][v] = false;
      mrc[(r-1)/3+1][(c-1)/3+1][v] = false;
    }
  }
}


int main()
{
  TRY(1, 1);
}
