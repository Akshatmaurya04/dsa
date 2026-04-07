class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int x = 0, y = 0; // starting from origin
        int direction = 0; // starting from North

        // putting obstracles into set to access faster
        set<pair<int,int>> st;
        for(auto& it: obstacles){
            st.insert({it[0],it[1]});
        }

        int maxDissq = 0;

        for(auto& cmd: commands){
            if(cmd == -2) direction = ((direction + 3) % 4);
            else if(cmd == -1) direction = ((direction + 1) % 4);
            else{ // we have to move forward k units
                for(int i = 0; i < cmd; i++){
                    int nextX = x + dx[direction];
                    int nextY = y + dy[direction];

                    if(st.find({nextX,nextY}) != st.end()) break;

                    x = nextX;
                    y = nextY;
                    maxDissq = max(maxDissq, ((x*x) + (y*y)));
                }
            }    
        }
        return maxDissq;
    }
};