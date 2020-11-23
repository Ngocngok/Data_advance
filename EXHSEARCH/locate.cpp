#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin >> a;
    for(int b = 0; b < a; b++)
    {
        int m, n, i, j;
        cin >> m >> n;

        int arr1[m][n];
        int arr2[m][n];



        for(i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> arr1[i][j];
            }
        }

        for(i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> arr2[i][j];
            }
        }


        int tmpM;// = m*-1;
        int tmpN;// = n*-1;
        int tmpI;
        int maxCount = 0;
        int tmpCount = 0;
        for(tmpM = (m-1)*-1; tmpM < m; tmpM++)
            for(tmpN = (n-1)*-1; tmpN < n; tmpN++)
            {
                tmpCount = 0;
                tmpI = 0;
                for(i = 0; i < m; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        if((i+tmpM) < 0 || (i+tmpM) > m-1 || (j+tmpN) < 0 || (j+tmpN) > n-1 )
                        {
                            continue;
                        }
                        if((1 == arr1[i+tmpM][j+tmpN]) && (arr2[i][j] == 1))
                        {
                            tmpCount++;
                            tmpI++;
                            if(tmpI > 10000) break;
                        }
                    }
                    
                }
                if(tmpI > 10000) break;
                if(tmpCount > maxCount) maxCount = tmpCount;

            }
            if(tmpI > 10000) break;

        cout << maxCount << endl;
    }
}