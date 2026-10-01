class Solution {
public:
    int solve(vector<int>& nums, int curr, int d,
              vector<unordered_map<int, int>>& dp) {
        if(dp[curr].find(d) != dp[curr].end()) {
            return dp[curr][d];
        }
        int best = 0;
        for(int k = curr + 1; k < nums.size(); k++) {
            if(nums[k] - nums[curr] == d) {
                best = max(best, 1 + solve(nums, k, d, dp));
            }
        }
        return dp[curr][d] = best;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int answer = 2;
        vector<unordered_map<int, int>> dp(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];
                answer = max(answer,
                             2 + solve(nums, j, diff, dp));
            }
        }
        return answer;
    }
};