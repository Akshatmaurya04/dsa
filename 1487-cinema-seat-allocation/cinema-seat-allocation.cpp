class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mp;
        for(auto& seats : reservedSeats){
            int u = seats[0];
            int v = seats[1];
            mp[u].push_back(v);
        }
        long long ans = (long long)(n-mp.size())*2;
        for(auto& rowEntry: mp){
            bool leftblocked = false;
            bool middleblocked = false;
            bool rightblocked = false;
            for(int seatNum: rowEntry.second){
                if(seatNum >= 2 and seatNum <=5) leftblocked = true;
                if(seatNum >= 4 and seatNum <= 7) middleblocked = true; 
                if(seatNum >= 6 and seatNum <=9) rightblocked = true;
            }
            if(!leftblocked and !rightblocked) ans += 2;
            else if(!leftblocked or !rightblocked or !middleblocked) ans += 1;
        }
        return ans;
    }
};