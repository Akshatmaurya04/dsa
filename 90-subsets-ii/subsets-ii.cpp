class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& result, vector<int>& ans, int idx){
        if(idx == nums.size()){
            result.push_back(ans);
            return;
        }

        // include
        ans.push_back(nums[idx]);
        helper(nums, result, ans, idx + 1);
        ans.pop_back();
        while(idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) idx++;
        // exclude
        helper(nums, result, ans, idx + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        helper(nums, result, ans, 0);
        return result;
    }
};