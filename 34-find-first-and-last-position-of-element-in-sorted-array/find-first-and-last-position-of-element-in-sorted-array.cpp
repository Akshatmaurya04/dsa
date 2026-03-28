class Solution {
public:
int end(vector<int>& nums, int s, int e, int target){
        int rightmost = -1;
        while(s<=e){
            int mid = s+((e-s)/2);
            if(target == nums[mid]){
                rightmost = mid;
                s = mid+1;
            }
            else if(target > nums[mid]) s = mid+1;
            else e = mid - 1;
        }
        return rightmost == -1 ? -1 : rightmost;
    }
    int start(vector<int>& nums, int s, int e, int target){
        int leftmost = -1;
        while(s<=e){
            int mid = s+((e-s)/2);
            if(target == nums[mid]){
                leftmost = mid;
                e = mid-1;
            }
            else if(target > nums[mid]) s = mid+1;
            else e = mid - 1;
        }
        return leftmost == -1 ? -1 : leftmost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int startpos = start(nums,0,n-1,target);
        int endpos = end(nums,0,n-1,target);
        return {startpos,endpos};
    }
};