class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int R = r - l + 1;
        const int MOD = 1e9 + 7;
        
        // Helper lambda to compute total configurations for a given initial direction
        auto solve = [&](bool start_up) -> long long {
            // dp[x] stores the number of valid sequences ending with value x (1-indexed)
            std::vector<long long> dp(R + 1, 1);
            
            bool current_up = start_up;
            for (int i = 2; i <= n; ++i) {
                std::vector<long long> next_dp(R + 1, 0);
                
                if (current_up) {
                    // UP transition: next_dp[x] = sum(dp[1] ... dp[x-1])
                    long long prefix_sum = 0;
                    for (int x = 1; x <= R; ++x) {
                        next_dp[x] = prefix_sum;
                        prefix_sum = (prefix_sum + dp[x]) % MOD;
                    }
                } else {
                    // DOWN transition: next_dp[x] = sum(dp[x+1] ... dp[R])
                    long long suffix_sum = 0;
                    for (int x = R; x >= 1; --x) {
                        next_dp[x] = suffix_sum;
                        suffix_sum = (suffix_sum + dp[x]) % MOD;
                    }
                }
                
                dp = std::move(next_dp);
                current_up = !current_up; // Flip direction for the next element
            }
            
            long long total = 0;
            for (int x = 1; x <= R; ++x) {
                total = (total + dp[x]) % MOD;
            }
            return total;
        };
        
        // Total valid configurations is the sum of both start directions
        long long ans = (solve(true) + solve(false)) % MOD;
        return ans;
    }
};