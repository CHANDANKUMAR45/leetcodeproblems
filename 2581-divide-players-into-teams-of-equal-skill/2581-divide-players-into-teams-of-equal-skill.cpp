class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        sort(skill.begin(),skill.end());
        int start=0,end=skill.size()-1;
       long long sum=0,team=skill[start]+skill[end];;
           
        while(start<end)
        { 
            if(team!=skill[start]+skill[end])
            return -1;

            sum+=skill[start]*skill[end];
            end--;
            start++;
        }
        return sum;
    }
};