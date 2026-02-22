class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        bool active = true;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i%6 == 5){
                active = !active;
            }
            if(nums[i] & 1){
                active = !active;
            }
            active ? count1 += nums[i] : count2 += nums[i];
        }
        return count1-count2;
    }
};