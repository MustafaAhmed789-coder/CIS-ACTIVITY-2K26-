#include <bits/stdc++.h>
using namespace std;
string longest_mirrored_phrase(string s) {
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j]) {
                dp[i + 1][j + 1] = 1 + dp[i][j];
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    int i = n, j = m;
    string palindrome = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            palindrome += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return palindrome;
}
int main() {
    string s = "babad";

    cout << "String: " << s << "\n";
    cout << "Longest Palindrome Subsequence: "
         << longest_mirrored_phrase(s) << "\n";

    return 0;
}
