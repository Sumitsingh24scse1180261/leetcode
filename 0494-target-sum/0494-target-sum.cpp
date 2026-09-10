class Solution {
public:

int helper(vector<int>& nums,int index,int sum,int target,vector<vector<int>>& dp,int total)
{
    if(index==nums.size())
    {
        if(sum==target)
            return 1;
        return 0;
    }

    int column=sum+total;

    if(dp[index][column]!=-1)
        return dp[index][column];

    int takePlus=helper(nums,index+1,sum+nums[index],target,dp,total);

    int takeMinus=helper(nums,index+1,sum-nums[index],target,dp,total);

    dp[index][column]=takePlus+takeMinus;

    return dp[index][column];
}

int findTargetSumWays(vector<int>& nums,int target)
{
    int total=0;

    for(int x:nums)
        total+=x;

    if(target>total || target<-total)
        return 0;

    vector<vector<int>> dp(nums.size(),vector<int>(2*total+1,-1));

    return helper(nums,0,0,target,dp,total);
}
};