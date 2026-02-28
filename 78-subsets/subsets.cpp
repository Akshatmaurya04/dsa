class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>curr, int pos){
        if(pos == nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        solve(nums,ans,curr,pos+1);
        curr.push_back(nums[pos]);
        solve(nums,ans,curr,pos+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>curr;
        solve(nums,ans,curr,0);
        return ans;
    }
};