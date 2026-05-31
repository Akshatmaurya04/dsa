class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());

        for(int i = 0; i < n; i++){
            if(asteroids[i] >  mass) return false;
            if(mass > asteroids[n-1]) break;
            mass += asteroids[i];
        }
        return true;
    }
};