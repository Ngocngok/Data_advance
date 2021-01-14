#include <iostream>

using namespace std;

typedef unsigned long long ull;
const ull P = 1e9 + 7;

ull res;

bool check(int k, int v, int *a, int *id, int cnt)
{
    int count = 0;
    for (int i = 0; i < id[k]; i++)
    {
        if (a[i] == 1)
            count++;
        else
            count--;
    }
    if (v == 1)
        count++;
    else
        count--;
    return count >= 0;
}

void solution(int *a, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            cnt++;
        else if (a[i] == 2)
        {
            cnt--;
            if (cnt < 0)
                return;
        }
    }
    if (cnt == 0)
    {
        res++;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
    }
}

void TRY(int *a, int *id, int cnt, int n, int k)
{
    for (int i = 1; i <= 2; i++)
    {
        if (check(k, i, a, id, cnt))
        {
            a[id[k]] = i;
            if (k < (cnt - 1))
                TRY(a, id, cnt, n, k + 1);
            else
                solution(a, n);
            a[id[k]] = 0;
        }
    }
}

void input()
{
    string s;
    cin >> s;
    int n = s.length();
    int a[n + 5];
    int id[n + 5];
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case '(':
            a[i] = 1;
            break;
        case '?':
            a[i] = 0;
            id[cnt++] = i;
            break;
        case ')':
            a[i] = 2;
            break;
        default:
            break;
        }
    }cout << n << cnt;

    TRY(a, id, cnt, n, 0);

    cout << res % P << endl;
}

int main()
{
    ios::sync_with_stdio(false);

    input();
}