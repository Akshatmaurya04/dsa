class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>psum;
        mp[0]++;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            psum.push_back(sum);

            if(mp.find(sum - k) != mp.end()){
                count += mp[sum - k];
            }

            mp[sum]++;
        }
        return count;
    }
};