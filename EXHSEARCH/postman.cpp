#include<bits/stdc++.h>

using namespace std;

typedef long long ull;
ull k;

ull goForThePositive(vector<pair<ull, ull> >S)
{
    if(S.empty())
    {
        return 0;
    }
    ull currentK = S.back().second;
    ull remainK = 0;
    ull traveledDistance = -S.back().first;
    ull previousDistance;

    while(!S.empty())
    {
        previousDistance = S.back().first;
        currentK = S.back().second - remainK;
        if(currentK < 0)
        {
            remainK = -1 * currentK;
            S.pop_back();
            if(S.empty())
            {
                break;
            }
            traveledDistance += (previousDistance - S.back().first);
            continue;
        }
        ull i = currentK / k;

        if(currentK == i*k)
        {
            traveledDistance += 2*i * S.back().first;
            remainK = 0;
        }
        else
        {
            traveledDistance += 2*(i+1) * S.back().first;
            remainK = (i+1)*k - currentK;
        }
            
        S.pop_back();
        if(S.empty())
        {
            break;
        }
        traveledDistance += (previousDistance - S.back().first);
    }

    return traveledDistance + previousDistance;
}

ull goForTheNegative(vector<pair<ull, ull> >S)
{
    if(S.empty())
    {
        return 0;
    }
    ull currentK = S.back().second;
    ull remainK = 0;
    ull traveledDistance = -S.back().first;
    ull previousDistance;

    while(!S.empty())
    {
        previousDistance = S.back().first;
        currentK = S.back().second - remainK;
        if(currentK < 0)
        {
            remainK = -1 * currentK;
            S.pop_back();
            if(S.empty())
            {
                break;
            }
            traveledDistance += (previousDistance - S.back().first);
            continue;
        }
        ull i = currentK / k;

        if(currentK == i*k)
        {
            traveledDistance += 2*i * S.back().first;
            remainK = 0;
        }
        else
        {
            traveledDistance += 2*(i+1) * S.back().first;
            remainK = (i+1)*k - currentK;
        }
            
        S.pop_back();
        if(S.empty())
        {
            break;
        }
        traveledDistance += (previousDistance - S.back().first);
    }

    return traveledDistance + previousDistance;
}

int main()
{
    ull n;
    vector<pair<ull, ull> >V1;
    vector<pair<ull, ull> >V2;

    int curX, curK;
    cin >> n >> k;

    for(ull i = 0; i < n; i++)
    {
        cin >> curX >> curK;
        if(curX >= 0)
        {
            V1.push_back(pair<ull, ull>(curX, curK));
        }
        else
        {
            V2.push_back(pair<ull, ull>(curX * -1, curK));
        }
        
    }

    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());


    cout << (goForThePositive(V1) + goForTheNegative(V2));
    //cout << goForTheNegative(Q);
}