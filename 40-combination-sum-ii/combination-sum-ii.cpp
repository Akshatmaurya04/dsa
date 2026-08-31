class Solution {
public:
    void helper(vector<int>& candidates, vector<int>& ans, vector<vector<int>>& result, int index, int target)
    {
        if(target == 0)
        {
            result.push_back(ans);
            return;
        }
        for(int i = index; i < candidates.size(); i++)
        {
            if(candidates[i] > target) break;
            if(i > index && candidates[i] == candidates[i-1]) continue;
            ans.push_back(candidates[i]);
            helper(candidates, ans, result, i + 1, target - candidates[i]);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        helper(candidates, ans, result, 0, target);
        return result; 
    }
};