class Solution {
public:
    using pi = pair<int,int>;
    using pc = pair<char,int>;
    using pic = pair<pi,pc>;
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pic> arr;
        for(int i = 0; i < positions.size(); i++){
            arr.push_back({{positions[i],healths[i]},{directions[i],i}});
        }

        sort(begin(arr),end(arr));
        stack<pic> st;
        for(auto& it: arr){
            auto[pos, health] = it.first;
            auto[dir, i] = it.second;

            while(!st.empty() and st.top().second.first == 'R' and dir == 'L'){
                auto[tpos, thealth] = st.top().first;
                auto[tdir, tidx] = st.top().second;
                st.pop();
                
                if(health == thealth){
                    health = 0;
                    break;
                }  
                else if(thealth > health){
                    health = 0;
                    thealth--;
                    st.push({{tpos,thealth},{tdir,tidx}});
                    break;
                }
                else health--;
            }
            if(health != 0) st.push({{pos, health},{dir, i}});
        }
        vector<pair<int,int>> ans;
        while(!st.empty()){
            auto[pos, health] = st.top().first;
            auto[dir, i] = st.top().second;
            st.pop();
            ans.push_back({i,health});
        }
        sort(begin(ans),end(ans));
        vector<int>finalans;
        for(auto it: ans){
            finalans.push_back(it.second);
        }
        return finalans;
    }
};