class Solution {
public:
const int M = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long product = 1;
        long long prefix = 1;
        
        vector<vector<int>> suffix(n,vector<int>(m,1));
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--){
                suffix[i][j] = product;
                product = (product * (grid[i][j]%M)) % M;
                cout<<suffix[i][j]<<endl;
            }
        }
        
        vector<vector<int>> ans(n,vector<int>(m,1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = (suffix[i][j] * prefix) % M;
                prefix = (prefix * (grid[i][j]%M)) % M;
            }
        }
        return ans;
    }
};