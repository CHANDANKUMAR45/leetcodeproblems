class Solution {
public:
      vector<int>solve(string s)
      {
        vector<int>result;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='*' || s[i]=='-' || s[i]=='+')
            {
                vector<int>result_left=solve(s.substr(0,i));
                vector<int>result_right=solve(s.substr(i+1));
                
                for(auto &x:result_left)   
                for(auto &y:result_right)
                {
                    if(s[i]=='+')
                    result.push_back(x+y);
                    
                    else if(s[i]=='-')
                    result.push_back(x-y);
                    
                   else //if(s[i]=='*')
                    result.push_back(x*y);
                }

            }
        }
                if(result.empty()) 
            result.push_back(stoi(s));
        

        return result;
      }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};