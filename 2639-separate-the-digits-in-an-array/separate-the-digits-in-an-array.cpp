class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            string s = to_string(nums[i]);
            int j = 0;
            while(j < s.size()){
                ans.push_back(s[j] - '0');
                j++;
            }
        }
        return ans;
    }
};