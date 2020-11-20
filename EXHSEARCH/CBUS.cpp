#include<iostream>

using namespace std;

typedef long long ull;
ull c[40][40];
int visited[40];
int current[40];

ull n;
int k_max;
int k;
ull f;
ull f_min;
ull min_cost;

void INPUT()
{
	cin >> n >> k_max;
	for (int i = 0; i < 2 * n + 1; i++)
	{
		for (int j = 0; j < 2 * n + 1; j++)
		{
			cin >> c[i][j];
            if (c[i][j] < min_cost && c[i][j] != 0)
            min_cost = c[i][j]; 
		}
	}
}

bool check(int v)
{
    if(visited[v])
    {
        return false;
    }
    if(v <= n)
    {
        if(k_max >= 1)
        {
            k_max--;
            return true;
        }
        else
            return false;
    }

    if(v > n && v <= 2*n)
    {
        if(visited[v - n])
        {
            k_max++;
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void SOLUTION(int i)
{
	if (f + c[i][0] < f_min)
	{
		f_min = f + c[i][0];
	}

}

void TRY(int k)
{
	for (int v = 1; v <= 2*n; v++)
	{
		if (check(v))
		{
			visited[v] = 1;
			current[k] = v;
            f = f + c[current[k - 1]][current[k]];
			if (k == 2*n)
			{
				SOLUTION(v);
			}
			else
			{
                if((2*n + 1 - k)*min_cost + f < f_min)
                {
                    TRY(k + 1);
                }
			}

            if(v <= n) k_max++;
            else k_max--; 
			visited[v] = 0;
            f = f - c[current[k - 1]][current[k]];
            //current[k] = 0;
		}
	}
}

void INIT()
{
	f_min = 1000000000;
    min_cost = 100000000;
	f = 0;
    k = k_max;
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