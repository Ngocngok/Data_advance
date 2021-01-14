#include<bits/stdc++.h>

using namespace std;

priority_queue<pair<pair<int, int>, int> > X;

int main()
{
    X.push(pair<pair<int, int>, int>(pair<int, int>(3 , 1) ,6));
    
    X.push(pair<pair<int, int>, int>(pair<int, int>(20 , 8) ,6));
    X.push(pair<pair<int, int>, int>(pair<int, int>(7 , 9) ,34));
    X.push(pair<pair<int, int>, int>(pair<int, int>(7 , 16) ,6));
    X.push(pair<pair<int, int>, int>(pair<int, int>(43 , 1) ,2));
    

    while(!X.empty())
    {
        cout << X.top().first.first << X.top().first.second << X.top().second << endl;
        X.pop();
    }

}