#include<bits/stdc++.h>

using namespace std;

const long N = 1e6 + 10;
int s[N];
int a[N];

long long total;
int l, r, n;

void INPUT()
{
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    INPUT();
    deque<int> q;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && q.front() < i - r) //too far
        {
            q.pop_front();
        }
        if (i - l >= 1)
        {
            while (!q.empty() && s[q.back()] < s[i - l])
            {
                q.pop_back();
            }
            q.push_back(i - l);
        }

        s[i] = (q.empty() ? 0 : s[q.front()]) + a[i];

        ans = ans > s[i] ? ans : s[i];
    }
    cout << ans << endl;
}
