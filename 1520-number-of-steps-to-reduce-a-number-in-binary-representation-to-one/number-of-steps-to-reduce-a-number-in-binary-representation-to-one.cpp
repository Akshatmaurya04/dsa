class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // Start from right (LSB) and move left
        for (int i = s.size() - 1; i > 0; i--) {
            if ((s[i] - '0' + carry) % 2 == 1) {
                // Odd → add 1 then divide
                steps += 2;
                carry = 1;
            } else {
                // Even → just divide
                steps += 1;
            }
        }
        
        // If carry remains, add one more step
        return steps + carry;
    }
};