class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> count(26, 0);
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            // Include the current character in the window
            count[s[right] - 'a']++;
            
            // If the character count exceeds 2, shrink the window from the left
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }
            
            // Update the maximum length found so far
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};