class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minindex = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) minindex = min(minindex, abs(i - start));
        }
        return minindex;
    }
};