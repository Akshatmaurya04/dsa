class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxi = INT_MIN;

        for(int i = n-1; i >= 0; i--){
            if(colors[0] != colors[i]) maxi = max(maxi,i);
        }
        for(int i = 0; i < n; i++){
            if(colors[n-1] != colors[i]) maxi = max(maxi,n-i-1);
        }
        return maxi; 
    }
};