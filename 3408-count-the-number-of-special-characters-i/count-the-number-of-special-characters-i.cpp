class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        
        // Track seen characters
        for (char c : word) {
            if (islower(c)) {
                lower[c - 'a'] = true;
            } else if (isupper(c)) {
                upper[c - 'A'] = true;
            }
        }
        
        // Count matching pairs
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (lower[i] && upper[i]) {
                count++;
            }
        }
        
        return count;
    }
};