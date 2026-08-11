class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break; // Sequence broken
            }
        }
        
        // Step 2: Store elements in a hash set for quick lookups
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        
        // Step 3: Find the smallest missing integer >= sum
        while (num_set.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};