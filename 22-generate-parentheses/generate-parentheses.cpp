class Solution {
public:
    void solve(vector<string>& ans, string str, int opening, int closing){
        if(opening == 0 && closing == 0) ans.push_back(str);
        
        if(opening > 0) solve(ans,str+'(',opening-1,closing);
        if(closing>opening) solve(ans,str+')',opening,closing-1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        int closing = n; 
        int opening = n;
        solve(ans,str,opening,closing);
        return ans;
    }
};