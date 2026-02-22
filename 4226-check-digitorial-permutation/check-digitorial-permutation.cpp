class Solution {
public:
    bool digitorial(int a){
        int temp = a;
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
        return sum == a;
    }
    bool isDigitorialPermutation(int n) {
        bool flag = false;
        // Convert to string to treat digits as elements
        string s = to_string(n);
        
        // Sort to start from the smallest permutation (123)
        sort(s.begin(), s.end());
        do { 
            if(s[0] !='0' && digitorial(stoi(s))){
                flag = true;
                break;
            }
        } while (next_permutation(s.begin(), s.end()));

        return flag;
        
    }
};