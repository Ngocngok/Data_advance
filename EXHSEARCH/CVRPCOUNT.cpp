#include<bits/stdc++.h>

const int N = 30;
const unsigned long long sth = 1e9 + 7;
int n; //number of client
unsigned long long cnt;
int K; // K trucks
int Q; // Q capacity
int d[N]; // client's request
int load[N]; // load of truck i
bool assigned[N]; // truck K assigned
//bool delivered[N]; // client i delivered
int route[N][N]; // route of truck i; route[i][0] = number of assigned node



using namespace std;

void INPUT()
{
    cin >> n >> K >> Q;
    for(int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
}

void INIT()
{
    cnt = 0;
    for(int i = 0; i < N; i++)
    {
        load[i] = Q;
        assigned[i] = false;
        //delivered[i] = false;
        for(int j = 0; j < N; j++)
            route[i][j] = 0;
    }
}
/*
bool allDelivered()
{
    for(int i = 1; i <= n; i++)
    {
        if(!delivered[i])
            return false;
    }

    return true;
}
*/
bool allAssigned()
{
    for(int i = 1; i <= K; i++)
    {
        if(route[i][0] == 0)
            return false;
    }

    return true;
}

bool deliverable(int i, int k)
{
    if(load[i] - d[k] < 0)
        return false;


    /*
    if(delivered[k])
        return false;
    */

    return true;
}

int fac(int i)
{
    if(i == 0 || i == 1)
        return 1;

    else return i * fac(i-1);
}
void SOLUTION()
{
    //cout << "____________" << endl;
    unsigned long long tmp = 1;
    for(int i = 1; i <= K; i++)
    {
        tmp *= fac(route[i][0]);
        //for(int j = 1; j <= route[i][0]; j++)
        //    cout << route[i][j] << " ";
        
        //cout << endl;
    }
    cnt += tmp;
}

/*
void TRY(int k) // client k
{
    for(int i = 1; i <= K; i++) // truck i
    {
        if(deliverable(i, k))
        {
            assigned[i] = true;
            load[i] -= d[k];

            if(k == n)
            {
                if(allAssigned())
                    SOLUTION();
            }
            else
                TRY(k+1);
            assigned[i] = false;
            load[i] += d[k];
        }
    }
}
*/

void TRY(int k) // client k
{
    for(int i = 1; i <= K; i++) // truck i
    {
        if(deliverable(i, k))
        {
            //assigned[i] = true;
            route[i][0]++;
            route[i][route[i][0]] = k;

            load[i] -= d[k];

            if(k == n)
            {
                if(allAssigned())
                    SOLUTION();
            }
            else
                TRY(k+1);
            
            //assigned[i] = false;
            load[i] += d[k];

            route[i][route[i][0]] = 0;
            route[i][0]--;
            
        }
    }
}



int main()
{
    INPUT();
    INIT();
    TRY(1);

    cout << (cnt/fac(K) % sth);
}