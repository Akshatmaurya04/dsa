class Solution {
public:
    string maximumXor(string s, string t) {
        unordered_map<char, int> mp;
        string result = "";
        string str = "";
        for(int i = 0; i<t.size(); i++){
            mp[t[i]]++;
        }
        for(int i = 0; i<t.size(); i++){
            if(s[i] == '0'){
                if(mp['1'] != 0){
                    str+='1';
                    mp['1']--;
                }
                else str+='0';
            }
            else{
                if(mp['0'] != 0){
                    str+='0';
                    mp['0']--;
                }
                else str+='1';
            }
        }
        for(int i = 0; i<t.size(); i++){
            if(s[i] == str[i]) result += '0';
            else result += '1';
        }
        return result;
    }
};