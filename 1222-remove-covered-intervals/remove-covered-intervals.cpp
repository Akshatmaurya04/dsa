class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& a_next) {
            if (a[0] == a_next[0]) {
                return a[1] > a_next[1];
            }
            return a[0] < a_next[0];
        });
        
        int remainingCount = 0;
        int maxEnd = 0;
        
        for (const auto& interval : intervals) {
            // If the current end extends beyond the max end seen so far, it's not covered
            if (interval[1] > maxEnd) {
                remainingCount++;
                maxEnd = interval[1]; // Update the furthest boundary
            }
        }
        
        return remainingCount;
    }
};