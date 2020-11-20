#include<bits/stdc++.h>

using namespace std;

int n;
int a[10002];
int s[10002];
int maxAns;


void INPUT()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

int maxSi(int k)
{
    s[k] = 1;
    for(int i = 1; i < k; i++)
    {
        if(a[k] > a[i])
        {
            if(s[k] <= s[i])
            {
                s[k] = s[i] + 1;
            }
        }
    }

    return s[k];
}

void SOLVE()
{
    s[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        int tmp = maxSi(i);
        if(maxAns < tmp)
            maxAns = tmp;
    }

}

int main()
{
    INPUT();
    SOLVE();
    cout << maxAns;
    
    return 0;
}