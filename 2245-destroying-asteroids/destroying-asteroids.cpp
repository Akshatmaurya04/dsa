class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long temp = mass;
        int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());

        for(int i = 0; i < n; i++){
            if(asteroids[i] > temp) return false;
            if(temp > asteroids[n-1]) break;
            temp += asteroids[i];
        }
        return true;
    }
};