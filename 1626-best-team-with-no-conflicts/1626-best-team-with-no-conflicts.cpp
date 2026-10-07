class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players;
        for (int i = 0; i < n; i++) {
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end());
        vector<int> dp(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = players[i].second;
            for (int j = i + 1; j < n; j++) {
                if (players[i].second <= players[j].second) {
                    dp[i] = max(dp[i],
                                players[i].second + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};