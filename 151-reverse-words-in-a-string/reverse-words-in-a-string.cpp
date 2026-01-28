class Solution {
public:
    string reverseWords(string str) {
        vector<string> v;
        string ans = "";
        int i = 0;
        int s = 0;
        int e = 0;
        while(i < str.length()){
            string n = "";
            while(i < str.length() && str[i] == ' '){
                i++;
            }
            if(i >= str.length()) break;
            s = i;
            while(i < str.length() && str[i] != ' '){
                i++;
            }
            e = i-1;
            n = str.substr(s,e-s+1);
            v.push_back(n);
        }
        for(int j = v.size()-1; j >= 0; j--){
            ans = ans + v[j];
            if(j != 0) ans += " ";
        }
        return ans;
    }
};