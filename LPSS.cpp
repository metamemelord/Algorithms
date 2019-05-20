/*
Given a string, find the length of longest palindromic sub-sequence

Optimal complxity:
    Time: O(n*2)
    Space: O(n*2)
*/

#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> m;

/*
Recursive solution:
    Time: O(n*2) (Worst: O(n*2))
    Space: O(n*2) (Worst: O(n*2))   
*/
int lengthOfLPSS(const string &s, int bg, int en)
{
    if (bg >= en)
    {
        return bg == en;
    }
    if (m.find(make_pair(bg, en)) != m.end())
    {
        return m[make_pair(bg, en)];
    }
    if (s[bg] == s[en])
        return m[make_pair(bg, en)] = 2 + lengthOfLPSS(s, bg + 1, en - 1);
    else
        return m[make_pair(bg, en)] = max(lengthOfLPSS(s, bg + 1, en), lengthOfLPSS(s, bg, en - 1));
}

/*
Iterative solution:
    Time: O(n*2) (Worst: O(n*2))
    Space: O(n*2) (Worst: O(n*2))   
*/
int lengthOfLPSSIter(const string &s)
{
    const int length = s.length();
    int d[length + 1][length + 1] = {0};
    for (int i = 0; i <= length; i++)
    {
        fill(d[i], d[i] + length + 1, 0);
        d[i][i] = 1;
    }
    // Iterate over possible lengths, for a particular length, find all possible endpoints. Build the answer recursively from smaller to larger.
    //
    //
    // // Find correct optimal sub-structure
    // // // abcdcsa
    // // 0 0 0 0 0 0 0 0
    // // 0 1 1 1 1 1 1 2
    // // 0 0 1 1 1 1 1 2
    // // 0 0 0 1 1 3 3 3
    // // 0 0 0 0 1 3 3 3
    // // 0 0 0 0 0 1 3 3
    // // 0 0 0 0 0 0 1 3
    // // 0 0 0 0 0 0 0 1

    // for (int i = 0; i < length; i++)
    // {
    //     for (int j = i + 1; j < length; j++)
    //     {
    //         if (s[i] == s[j])
    //         {
    //             d[i + 1][j + 1] = 2 + d[i][j];
    //         }
    //         else
    //         {
    //             d[i + 1][j + 1] = max(d[i][j + 1], d[i + 1][j]);
    //         }
    //     }
    // }

    // for (int i = 0; i <= length; i++)
    // {
    //     for (int j = 0; j <= length; j++)
    //     {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return d[length][length - 1];
}

int main()
{
    const string value = "abcdcsa";
    cout << lengthOfLPSS(value, 0, value.length()) << endl;
    cout << lengthOfLPSSIter(value);
}
