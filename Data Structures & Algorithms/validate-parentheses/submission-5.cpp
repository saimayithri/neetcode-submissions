class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(char x : s)
        {
            if(x == '(' || x == '{' || x == '[')
            {
                st.push(x);
            }

            else if(x == ')')
            {
                if(st.empty() || st.top() != '(')
                {
                    return false;
                }

                st.pop();
            }

            else if(x == '}')
            {
                if(st.empty() || st.top() != '{')
                {
                    return false;
                }

                st.pop();
            }

            else if(x == ']')
            {
                if(st.empty() || st.top() != '[')
                {
                    return false;
                }

                st.pop();
            }
        }

        if(!st.empty())
        {
            return false;
        }

        else
        {
            return true;
        }
    }
};