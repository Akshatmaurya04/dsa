class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int temp = n;
        int sum = 0;
        while(temp){
            int b = temp%10;
            int result = 1;
            if(b != 0){
                for(int i = 1; i <= b; i++){
                    result *= i;
                }
            }
            sum += result;
            temp /= 10;
        }
        string s = to_string(n);
        sort(s.begin(),s.end());
        do{
            if(s[0] != '0' && sum == stoi(s)) return true;
        }while(next_permutation(s.begin(),s.end()));
        return false;
    }
};