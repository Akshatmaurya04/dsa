class Solution {
public:
    int repeatedStringMatch(string a, string b) 
    {
        int count = 1;
        string copy = a;
        while(copy.size() < b.size())
        {
            count++;
            copy += a;
        }
        if(copy.find(b) != string::npos) return count;
        copy += a;
        if(copy.find(b) != string::npos) return count + 1;
        return -1;
    }
};