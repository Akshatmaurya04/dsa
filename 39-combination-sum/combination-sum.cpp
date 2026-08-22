class Solution {
public:
    void helper(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& arr, int i, int sum, int target)
    {
        if(i >= candidates.size() || sum > target) return;
        if(sum == target)
        {
            ans.push_back(arr);
            return;
        }

        helper(candidates, ans, arr, i+1, sum, target);
        arr.push_back(candidates[i]);
        helper(candidates, ans, arr, i, sum + candidates[i], target);
        arr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        helper(candidates, ans, arr, 0, 0, target);
        return ans;
    }
};