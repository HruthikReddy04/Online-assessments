#include <bits/stdc++.h>
using namespace std;

int minOperationsToDelete(const string &s) {
    if (s.empty()) return 0;

    // Step 1: run-length compress -> keep only distinct-run characters
    string c;
    c.push_back(s[0]);
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) c.push_back(s[i]);
    }

    int m = c.size();
    // dp[i][j] = min ops to delete c[i..j]
    vector<vector<int>> dp(m, vector<int>(m, 0));

    for (int i = 0; i < m; ++i) dp[i][i] = 1;

    // fill by increasing interval length
    for (int len = 2; len <= m; ++len) {
        for (int i = 0; i + len - 1 < m; ++i) {
            int j = i + len - 1;

            // baseline: delete c[i] alone, then solve rest
            dp[i][j] = dp[i + 1][j] + 1;

            // try merging c[i] with an equal later character c[k]
            for (int k = i + 1; k <= j; ++k) {
                if (c[k] == c[i]) {
                    int left = (k - 1 >= i + 1) ? dp[i + 1][k - 1] : 0;
                    dp[i][j] = min(dp[i][j], left + dp[k][j]);
                }
            }
        }
    }

    return dp[0][m - 1];
}

int main() {
    string s;
    cin >> s;                 // up to 500 lowercase letters
    cout << minOperationsToDelete(s) << endl;
    return 0;
}
