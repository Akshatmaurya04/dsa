class Solution {
public:
    
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        int count = 0;
        for(string& s: words){
            if(s.size() >= k) mp[s.substr(0,k)]++;
        }
        for(auto& a:mp){
            if(a.second > 1) count++;
        }
        return count;















        // int count = 0;
        // int freq = 0;
        // int n = words.size();
        // vector<bool>grouped(n,false);
        // for(int i = 0; i<n; i++){
        //     string str = words[i].substr(0,k);
        //     for(int j = i; j<n; j++){
        //         if(!grouped[j] && words[j].substr(0,k) == str){
        //             freq++;
        //             grouped[j] = true;
        //         }
        //     }
        //     if(freq>1) count++;
        //     freq = 0;
        // }
        // return count;
    }
};