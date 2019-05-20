/*
Given a string, find the length of longest palindromic sub-sequence

Optimal complxity:
    Time: O(n*2)
    Space: O(n*2)
*/

#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> m;
map<pair<int, int>, int> mLcss;

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

Theory:
    Double looping is required to solve this problem. Here's analysis of recurrence and looping:

    Recurrence:
        F(length, starting_idx, ending_idx) = 
                1, if starting and ending indices are same
                2 + F(length-2, starting_idx+1, ending_idx-1), if value at starting index and value at ending index are same
                Otherwise, max(F(length-1, starting_index+1, ending_index), F(length-1, starting_index, ending_index-1))

        IMPORTANT: We do need not pass both starting and ending indices, as we can get all three using any two.

    Looping:
        Analysis of traditional 2 loop system:
            i: 0 .. len
                j: i+1 .. len
                    // Do something
        The above loop will not help us in getting the subsequence, why? Lack of OPTIMAL SUBSTRUCTURE.
        Considering we are dealing with string endpoints, the above problem gives indices of strings like:
            0 to 1: length = 1
            0 to 2: length = 2
            .
            .
            0 to n: length = n
        Hence for the iteration, we have:
            1 to 2: length = 1
            1 to 3: length = 2
            .
            .
            1 to n: length = n-1
        and so on..

        Trying to build a recursive solution fails with this approach because the OPTIMAL SUBSTRUCTURE operates around the length of
        substrings for this problem. While calculating answer for some arbitrary recurrence (length, starting_index) all possible values
        of (length-1, strating_index) SHOULD be calculated.
        
    Hence, to solve this, we need to iterate over possible LENGTHS and STARTING_INDEX and NOT STARTING_INDEX and ENDING_INDEX.
*/
int lengthOfLPSSIter(const string &s)
{
    const int length = s.length();
    int d[length][length] = {0};
    for (int i = 0; i < length; i++)
        fill(d[i], d[i] + length + 1, 0);

    for (int len = 1; len <= length; len++)
    {
        for (int idx = 0; idx < length - len + 1; idx++)
        {
            auto str_end = idx + len - 1;
            if (idx == str_end)
            {
                d[idx][idx] = 1;
            }
            else if (s[idx] == s[str_end])
            {
                d[idx][str_end] = 2 + d[idx + 1][str_end - 1];
            }
            else
            {
                d[idx][str_end] = max(d[idx][str_end - 1], d[idx + 1][str_end]);
            }
        }
    }

    return d[0][length - 1];
}

/*
Solution using Longest Common Sub-sequence problem.

Observation:
    Longest palindromic subsequence of a string/sequence is same as longest common subsequence of the string with it's reversed string.

    Example:
        String: ABSFSDEQBA (Length of LPSS = 7 (ABSDSBA))
        Reversed string: ABQEDSFSBA

        Length of LCSS = 7 (ABSDSBA) = Length of LPSS
*/

/*
Longest Common Sub-sequence problem.

Recursive solution:
    Time: O(n*m) (Worst: O(n*m))
    Space: O(n*m) (Worst: O(n*m))
*/
int lengthOfLPSSUsingLCSSWorker(const string &s, const string &t, int idx1, int idx2)
{
    if (idx1 == s.length() || idx2 == t.length())
    {
        return 0;
    }
    else if (mLcss.find(make_pair(idx1, idx2)) != mLcss.end())
    {
        return mLcss[make_pair(idx1, idx2)];
    }
    else if (s[idx1] == t[idx2])
    {
        return mLcss[make_pair(idx1, idx2)] = 1 + lengthOfLPSSUsingLCSSWorker(s, t, idx1 + 1, idx2 + 1);
    }
    else
    {
        return mLcss[make_pair(idx1, idx2)] = max(lengthOfLPSSUsingLCSSWorker(s, t, idx1 + 1, idx2), lengthOfLPSSUsingLCSSWorker(s, t, idx1, idx2 + 1));
    }
}

int lengthOfLPSSUsingLCSS(const string &s)
{
    string reversedS = s;
    reverse(reversedS.begin(), reversedS.end());
    return lengthOfLPSSUsingLCSSWorker(s, reversedS, 0, 0);
}

/*
Longest Common Sub-sequence problem. 

Iterative solution:
    Time: O(n*m) (Worst: O(n*m))
    Space: O(n*m) (Worst: O(n*m))
*/
int lengthOfLPSSUsingLCSSIterWorker(const string &s, const string &t)
{
    int d[s.length() + 1][t.length() + 1 + 1] = {0};
    for (int i = 0; i <= s.length(); i++)
        fill(d[i], d[i] + t.length() + 1, 0);
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < t.length(); j++)
        {
            if (s[i] == t[j])
            {
                d[i + 1][j + 1] = 1 + d[i][j];
            }
            else
            {
                d[i + 1][j + 1] = max(d[i][j + 1], d[i + 1][j]);
            }
        }
    return d[s.length()][t.length()];
}
int lengthOfLPSSUsingLCSSIter(const string &s)
{
    string reversedS = s;
    reverse(reversedS.begin(), reversedS.end());
    return lengthOfLPSSUsingLCSSIterWorker(s, reversedS);
}

/*
Demo
*/
int main()
{
    const string value = "we need to find length of longest palindromic sub-sequence for this string in n square time and space";

    cout << "Using LPSS (recursive): " << lengthOfLPSS(value, 0, value.length()) << endl;
    cout << "Using LPSS (iterative): " << lengthOfLPSSIter(value) << endl;
    cout << "Using LCSS (recursive): " << lengthOfLPSSUsingLCSS(value) << endl;
    cout << "Using LCSS (iterative): " << lengthOfLPSSUsingLCSSIter(value) << endl;
}