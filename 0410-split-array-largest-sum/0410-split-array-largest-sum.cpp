
class Solution {
public:
    int solve(int i, int k, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (k == 1) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += nums[j];
            }
            return sum;
        }
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        int sum = 0;
        int ans = INT_MAX;
        for (int j = i - 1; j >= k - 1; j--) {
            sum += nums[j];
            int left = solve(j, k - 1, nums, dp);
            ans = min(ans, max(left, sum));
        }
        return dp[i][k] = ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, -1)
        );
        return solve(n, k, nums, dp);
    }
};
