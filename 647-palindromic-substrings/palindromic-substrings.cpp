class Solution {
public:
    void expand(string s, int i, int j, int& count){
        while(i >=0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
            count++;
        }

    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            //for even leagth
            expand(s,i,i+1,count);
            //for odd length
            expand(s,i,i,count);
        }
        return count;
    }
};