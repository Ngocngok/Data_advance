#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
const int MAX = 100000;

ull N, K;
ull a[MAX];
ull countSol;

void input()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
}

int binarySearch(ull L, ull R, ull Y)
{
    if (L > R)
        return 0;
    if (L == R)
    {
        if (a[L] == Y)
            return 1;
        else
            return 0;
    }
    ull M = (L + R) / 2;
    if (a[M] == Y)
        return 1 + binarySearch(L, M - 1, Y) + binarySearch(M + 1, R, Y);
    else if (a[M] < Y)
        return binarySearch(M + 1, R, Y);
    else
        return binarySearch(L, M - 1, Y);
}

void solve()
{
    sort(&a[1], &a[N + 1]);
    for (ull i = 1; i <= N - 2; i++)
    {
        for (ull j = i + 1; j <= N - 1; j++)
        {
            countSol += binarySearch(j + 1, N, K - a[i] - a[j]);
        }
    }

    cout << countSol << endl;
}

int main()
{
    input();
    solve();
}