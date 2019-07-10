/*
   Given the share prices for 'n' days, determine the max possible profit
   after doing at max K transactions.
*/
#include <bits/stdc++.h>

using namespace std;

/*
    Iterative solution:
    Time: O(n*n*k)
    Space: O(n*k)
    Profit on d'th day and t'th transaction can be given by:
        profit[k][d] = max | profit[k][d-1] // Profit on previous day,
                           | price[d] - price[x] + profit[k-1][x], for some x in [0, i), 
                           |    i.e. Today's price - price of some day (x) + profit made by t-1 transactions on x'th day
*/
int nSquareIntoKTime(const int x[1000], int n, int k)
{
    int profit[k + 1][n + 1] = {0};
    fill(profit[0], profit[0] + n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        profit[0][i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int mx = INT_MIN;
            for (int o = 0; o < i; o++)
            {
                mx = max(mx, x[i] - x[o] + profit[j - 1][o]);
            }
            profit[j][i] = max(profit[j][i - 1], mx);
        }
    }
    return profit[k][n - 1];
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n, k, x[1000];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << nSquareIntoKTime(x, n, k) << endl;
}
