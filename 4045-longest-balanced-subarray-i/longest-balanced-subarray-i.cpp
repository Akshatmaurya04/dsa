class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int len = 0;
        for(int i = 0; i < nums.size(); i++){
            unordered_set<int> even;
            unordered_set<int> odd;
            for(int j = i; j < nums.size(); j++){
                if(nums[j] & 1) odd.insert(nums[j]);
                else even.insert(nums[j]);
                if(odd.size() == even.size()) len = max(len, j-i+1);
            }
        }
        return len;
    }
};