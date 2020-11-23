#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int j;

    vector<int> myInt;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> j;
        myInt.push_back(j);
    }

    sort(myInt.begin(), myInt.end());

    for(vector<int>::iterator it = myInt.begin(); it != myInt.end(); ++it)
    {
        cout << *it << ' ';
    }
    
    return 0;

}