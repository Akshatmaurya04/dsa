class Solution {
public:
    string maxPalindrome(string& s, int l, int r, string& ans){
        if(l < 0 || r >= s.size()) return ans;
        if(s[l] == s[r]){
            ans = (r-l+1 > ans.size()) ? s.substr(l,r-l+1) : ans;
            return maxPalindrome(s,l-1,r+1,ans);
        }
        return ans;
    }

    string longestPalindrome(string s) {

        string ans = "";
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            string odd = maxPalindrome(s,i,i,ans);
            string even = maxPalindrome(s,i,i+1,ans);
            temp = (odd.size() > even.size()) ? odd : even;
            ans = (temp.size() > ans.size()) ? temp : ans;
        }
        return ans;
    }
};