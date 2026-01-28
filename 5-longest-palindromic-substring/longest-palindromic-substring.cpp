class Solution {
public:
    bool checkPalindrome(string& s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string t = "";
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            int j = i;
            while(j < s.size()){
                if(checkPalindrome(s,i,j)){
                    string str = s.substr(i,j-i+1);
                    t = t.size() > str.size() ? t : str;
                }
                j++;
            }
            
        }
        return t;
    }
};