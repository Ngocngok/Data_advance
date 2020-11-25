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
    /*
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
    */
    int TMPANS = -1e6;
    for(int i = 1; i <= n; i++)
    {
        if(S[i] > 0)
            break;
        if(S[i] > TMPANS)
            TMPANS = S[i];
        if(i == n)
        {
            cout << TMPANS;
            return 0;
        }
    }

    int ANS = 0;
    int CUR = 0;
    for(int i = 1; i <= n; i++)
    {
        if(CUR+S[i] > 0)
        {
            CUR += S[i];
            if(CUR > ANS)
                ANS = CUR;
        }
        else
            CUR = 0;
    }


    cout << ANS;

    

    //cout << maxAns;
    
    return 0;
}