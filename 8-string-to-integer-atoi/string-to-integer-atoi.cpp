class Solution {
public:
    int myAtoi(string s){
        long long num = 0;
        int l = 0;
        int sign = 1;

        while(l<s.size() && s[l] == ' ') l++;
        if(s[l] == '-' || s[l] == '+'){
            sign = (s[l] == '-')? -1 : 1;
            l++;
        }
        while(l<s.size() && s[l] == '0') l++;
        while(l<s.size() && isdigit(s[l]))
        {
            int temp = s[l] - '0';
            if(num * 10 > INT_MAX) return (sign == -1) ? INT_MIN : INT_MAX;
            num = num * 10 + temp;
            l++;

        }

        if(num * sign > INT_MAX) num = INT_MAX;
        else if(num * sign < INT_MIN) num = INT_MIN;
        return num * sign;
    }
};