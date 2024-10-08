class Solution {
public:
    int minSwaps(string s) {
        
        int st=0;

        for( char &ch:s)
        {
            if(ch=='[')
            st++;

            else if(st>0)
            st--;
        }
        return (st+1)/2;
        
    }
};