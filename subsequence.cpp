//Austin Farias
/* To make it more faster I could do instead of using n + 1 I could do (m + 1) 
/* * (n + 1 )*/

#include <iostream>
#include <vector>
using namespace std;

string longestCommonSubsequence(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m + 1,vector<int>(n + 1, 0));

    // Populating the LCS table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstructing the LCS
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    string lcs = longestCommonSubsequence(s1, s2);

    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
