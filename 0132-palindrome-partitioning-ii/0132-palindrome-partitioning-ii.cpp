class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPalindrome(s, j, i - 1)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};