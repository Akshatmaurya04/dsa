class Solution {
public:
    int countMonobit(int n) {
        int count = 0;
        for(int i = 0; i <= n; i++){
            string str = bitset<32>(i).to_string();

            //remove leading zeros
            int pos = str.find('1');
            if(pos != string::npos){
                str = str.substr(pos);
            }
            else str = '0';

            bool flag = false;
            for(int j = 0; j < str.size(); j++){
                if(str[j] != str[0]) flag = true;
            }
            if(flag == false) count++;
        }
        return count;
    }
};