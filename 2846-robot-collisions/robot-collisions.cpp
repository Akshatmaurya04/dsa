class Solution {
public:
    using ti = tuple<int,int,char , int>;
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<ti> arr;
        int n = positions.size();

        for(int i = 0; i < n; i++){
            arr.push_back({positions[i],healths[i],directions[i] , i});
        }

        sort(arr.begin(),arr.end());
        stack<ti>st;

        for(auto it : arr)
        {
            auto[pos , health , dir , i] = it;
            while(!st.empty() and (get<2>(st.top()) == 'R' and dir == 'L'))
            {
                auto[tpos , thealth , tdir , tidx] = st.top();
                st.pop();

                if(health == thealth)
                {
                    health = 0;
                    break;
                }
                else if(thealth > health)
                {
                    thealth--;
                    st.push({tpos , thealth , tdir , tidx});
                    health = 0;
                    break;
                }
                else health--;
            }
            if(health > 0) st.push({pos , health , dir, i});
        }

        vector<pair<int,int>>ans;
        while(!st.empty())
        {
            ans.push_back({get<3>(st.top()) , get<1>(st.top())});
            st.pop();
        }

        sort(begin(ans) , end(ans));
        vector<int>finalans;
        for(auto it: ans) finalans.push_back(it.second);
        return finalans;
    }
};