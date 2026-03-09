class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[n-1] > nums[0]) return nums[0];
        int s = 0;
        int ans = INT_MAX;
        int e = n-1;
        while(s < e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= nums[0]) s = mid + 1;
            else{
                ans = nums[mid];
                e = mid;
            }
        }
        return nums[s];
    }
};