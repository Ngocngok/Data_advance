#include <bits/stdc++.h>

using namespace std;

int check(char * arr)
{
    stack<char> Q;
    int index = 0;

    while(arr[index] != '\0')
    {
        if(arr[index] == '(' || arr[index] == '{' || arr[index] == '[')
        {
            Q.push(arr[index]);
            index++;
            continue;
        }

        if(arr[index] == ')')
        {
            if(Q.empty()) return 0;
            if(Q.top() == '(')
            {
                Q.pop();
                index++;
            }
            else return 0;
        }

        if(arr[index] == ']')
        {
            if(Q.empty()) return 0;
            if(Q.top() == '[')
            {
                Q.pop();
                index++;
            }
            else return 0;
        }

        if(arr[index] == '}')
        {
            if(Q.empty()) return 0;
            if(Q.top() == '{')
            {
                Q.pop();
                index++;
            }
            else return 0;
        }

    }

    if(!Q.empty())
    {
        return 0;
    }
    else return 1;

    
}
char * arr = new char[10000];
int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        memset(arr, '\0', 10000);
        cin >> arr;
        
        cout << check(arr) << endl;
    }
}