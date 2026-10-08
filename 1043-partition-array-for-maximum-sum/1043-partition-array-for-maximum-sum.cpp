class Solution {
public:
    int solve(vector<int>& arr, int i, int k, vector<int>& dp) {
        if (i == arr.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = 0;
        int maxi = 0;
        for (int j = i; j < min((int)arr.size(), i + k); j++) {
            maxi = max(maxi, arr[j]);
            int len = j - i + 1;
            int cost = len * maxi + solve(arr, j + 1, k, dp);
            ans = max(ans, cost);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, 0, k, dp);
    }
};