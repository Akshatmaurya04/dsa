class Solution {
public:
    int minPartitions(string n) {
        char maxDigit = '0';
        for (char c : n) {
            // Find the highest digit in the string
            if (c > maxDigit) {
                maxDigit = c;
            }
            // If we find a '9', we can stop early (it's the max possible)
            if (maxDigit == '9') break;
        }
        // Convert char to int
        return maxDigit - '0';
    }
};