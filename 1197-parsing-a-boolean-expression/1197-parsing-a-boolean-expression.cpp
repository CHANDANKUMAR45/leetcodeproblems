//Approach (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    char solveOp(char op, vector<char>& values) {
        if (op == '!') 
            return values[0] == 't' ? 'f' : 't';
    
        if (op == '&') 
          
        {
          for(auto &ch:values)
           if(ch=='f')
           return 'f';

            return 't';
        }
    
        if (op == '|') 
        {
           for(auto &ch:values)
           if(ch=='t')
           return 't';

           return 'f';


        }
           
           
        return 't'; // Unreachable
    }

    bool parseBoolExpr(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ',') continue;

            if (s[i] == ')') {
                vector<char> values;
                // Gather all values inside the parentheses
                while (st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();  // Remove '('
                char op = st.top();
                st.pop();  // Remove the operator
                st.push(solveOp(op, values));
            } else {
                st.push(s[i]);
            }
        }
        return (st.top() == 't');
    }
};
