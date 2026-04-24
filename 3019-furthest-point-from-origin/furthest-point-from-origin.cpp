class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcount = 0;
        int rcount = 0;
        int count = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'L') lcount++;
            else if(moves[i] == 'R') rcount++;
            else count++;
        }
        
        return (lcount > rcount) ? (lcount-rcount)+count : (rcount-lcount)+count; 
    }
};