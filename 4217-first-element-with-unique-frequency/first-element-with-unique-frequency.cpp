class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> freqc;
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        for(auto &a: freq){
            freqc[a.second]++;
        }
        for(int i = 0; i<nums.size(); i++){
            if(freqc[freq[nums[i]]]==1) return nums[i];
        }
        return -1;
    }
};