class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int idx = 0;
        for(auto& it: queries){
            idx = it[0];
            while(idx <= it[1]){
                nums[idx] = (1LL * nums[idx] * it[3]) % (int)(1e9+7);
                idx += it[2];
            }
        }
        int x = 0;
        for(auto& it: nums){
            x ^= it;
        }
        return x;
    }
};