#include<bits/stdc++.h>

using namespace std;

int n;
int cnt;
int chars[20]; // icthustk
int assigned[20];


bool solution()
{
    if(chars[0] * 100 + chars[1] * 10 + chars[2] - chars[6]*100 - 62 + chars[3]*1000 + chars[4]*100 + chars[5]*10 + chars[2] == n)
    {
        cnt++;
    }
}

bool allAssigned()
{
    for(int i = 0; i < 7; i++)
    {
        if(chars[i] == 0)
            return false;
    }
    return true;
}

void INIT()
{
    for(int i = 0; i < 20; i++)
    {
        chars[i] = 0;
        assigned[i] = 0;
    }
    n = 0;
    cnt = 0;
}

void TRY(int k)
{
    for(int i = 1; i <= 9; i++)
    {
        if(chars[k] == 0 && !assigned[i])
        {
            assigned[i] = 1;
            chars[k] = i;
            if(allAssigned())
                solution();
            else 
                TRY(k+1);
            chars[k] = 0;
            assigned[i] = 0;
        }
    }
}

int main()
{
    INIT();
    cin >> n;
    TRY(0);
    cout << cnt;
}