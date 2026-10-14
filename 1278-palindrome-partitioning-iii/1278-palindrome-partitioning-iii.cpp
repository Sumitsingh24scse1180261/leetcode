
class Solution {
public:
    int cost(string &s, int i, int j) {
        int ans = 0;
        while (i < j) {
            if (s[i] != s[j]) {
                ans++;
            }
            i++;
            j--;
        }
        return ans;
    }
    int solve(int i, int k, string &s,
              vector<vector<int>> &dp) {
        int n = s.size();
        if (k == 1) {
            return cost(s, 0, i - 1);
        }
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        int ans = INT_MAX;
        for (int j = k - 1; j < i; j++) {
            int left = solve(j, k - 1, s, dp);
            int right = cost(s, j, i - 1);
            ans = min(ans, left + right);
        }
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, -1)
        );
        return solve(n, k, s, dp);
    }
};
