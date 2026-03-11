class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> unique_ele(nums.begin(), nums.end());
        unordered_map<int,int> freq;
        int unique = unique_ele.size();
        int n = nums.size();
        int left = 0; 
        int right = 0;
        int completesub = 0;

        while(left < n){
            while(right < n && freq.size() != unique){
                freq[nums[right]]++;
                right++;
            }

            if(freq.size() < unique) break;
            completesub += (n-right+1);
            cout<< completesub << endl;
            freq[nums[left]]--;
            if(freq[nums[left]] == 0){
                freq.erase(nums[left]);
            }
            left++;
        }
        return completesub;
    }
};