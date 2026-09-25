class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int l = 0;
        int maxi = 0;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;

            while(mp[s[i]] > 1 ){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            int len = mp.size();
            maxi = max(maxi, len);
        }
        return maxi;
    }
};