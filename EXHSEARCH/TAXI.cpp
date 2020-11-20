#include<iostream>

using namespace std;

typedef long long ull;
ull c[40][40];
int visited[40];
int current[40];

ull n;
ull f;
ull f_min;
ull min_cost;

void INPUT()
{
	cin >> n;
	for (int i = 0; i < 2 * n + 1; i++)
	{
		for (int j = 0; j < 2 * n + 1; j++)
		{
			cin >> c[i][j];
            if (c[i][j] < min_cost &&  c[i][j] != 0)
            min_cost = c[i][j]; 
		}
	}
}

bool allTransported()
{
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
			return false;
	}

	return true;
}

void SOLUTION(int i)
{
	if (f + c[i][i+n] + c[i+n][0] < f_min)
	{
		f_min = f + c[i][i + n] + c[i + n][0];
	}

}

void TRY(int k)
{
	for (int v = 1; v <= n; v++)
	{
		if (!visited[v])
		{
			visited[v] = 1;
			current[k] = v;
            if(k - 1 == 0)
                f = c[0][current[k]];
            else
			    f = f + c[current[k - 1]][current[k - 1] + n] + c[current[k-1] + n][current[k]];
			if (allTransported())
			{
				SOLUTION(v);
			}
			else
			{
                if((2*n + 1 - 2*k)*min_cost + f < f_min)
                {
                    TRY(k + 1);
                }
			}
			visited[v] = 0;

            if(k - 1 == 0)
                f = 0;
			else
                f = f - c[current[k - 1]][current[k - 1] + n] - c[current[k - 1] + n][current[k]];
		}
	}
}

void INIT()
{
	f_min = 1000000000;
    min_cost = 100000000;
	f = 0;
	for (int i = 0; i < 40; i++)
	{
		visited[i] = 0;
		current[i] = 0;
		for (int j = 0; j < 40; j++)
		{
			c[i][j] = 0;
		}
	}

}

void SOLVE()
{
	TRY(1);
	cout << f_min;
}

int main()
{
	INIT();
	INPUT();
	SOLVE();
}