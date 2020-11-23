#include<bits/stdc++.h>

using namespace std;

int n;
int x[10001];
int minVal = 10000;
int startP, endP;
bool noAnswer = true;
bool check = false;


void INPUT()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    x[n] = '\0';
}


void swap(int index1, int index2)
{
    int tmp = x[index1];
    x[index1] = x[index2];
    x[index2] = tmp;
}

void TRY(int k)
{
    for(int i = n-k; i < n; i++)
    {
        if(x[i] > x[n-k])
        {
            if(x[i] < minVal)
            {
                minVal = x[i];
                startP = n - k;
                endP = i;
                check = true;
                noAnswer = false;
            }
        }
    }
    if(check)
        return;

    if(k == n) 
        return;

    TRY(k+1);
}

void SOLVE()
{
    TRY(1);
    if(noAnswer)
        cout << -1;
    if(check)
    {
        swap(startP, endP);
        sort(x+startP+1, x+n);
        for(int i = 0; i < n; i++)
            cout << x[i] << " ";
    }
}

int main()
{
    INPUT();
    SOLVE();
}