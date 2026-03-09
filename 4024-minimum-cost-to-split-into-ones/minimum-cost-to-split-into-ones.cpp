class Solution {
public:
    int minCost(int n) {
        int count = 0;
        for(int i = 1; i < n; i++) count += i;
        return count;
    }
};