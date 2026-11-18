class Solution {
public:
    vector<vector<int>>dp;

    int solve(vector<int>& nums, int& target, int i, int sum){
        if(sum == target) return 0;
        if(sum > target) return INT_MIN;
        if(i >= nums.size()) return INT_MIN;
        if(dp[i][sum] != -1) return dp[i][sum];

        int take = 1 + solve(nums, target, i+1, sum + nums[i]);
        int nottake = solve(nums, target, i+1, sum);

        return dp[i][sum] = max(take , nottake);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n+1, vector<int>(target+1, -1));
        
        int ans = solve(nums, target, 0, 0);
        return ans < 0 ? -1 : ans;
    }
};