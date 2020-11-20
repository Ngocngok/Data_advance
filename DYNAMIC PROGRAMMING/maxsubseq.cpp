#include<bits/stdc++.h>

using namespace std;

int n;
int S[10002];
int SI[10002];
int sI;
int maxAns;


void INPUT()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> S[i];
}

int main()
{
    INPUT();
    SI[1] = 1;
    maxAns = SI[1];
    for(int i = 2; i <= n; i++)
    {
        SI[i] = 1;
        for(int j = 1; j <= i-1; j++)
        {
            if(S[j] < S[i])
            {
                if(SI[i] < SI[j+1])
                    SI[i] = SI[j+1];

                if(SI[i] > maxAns)
                    maxAns = SI[i]; 
            }
        }
    }
    

    cout << maxAns;
    
    return 0;
}