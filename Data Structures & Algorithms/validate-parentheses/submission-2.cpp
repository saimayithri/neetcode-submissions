class Solution {
public:
    bool isValid(string s) {

        if (s.size()<=1)
            return false;

        stack<char> st;
        for(char c:s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else if(c==')')
            {
                if (!st.empty() &&st.top()=='('){
                    st.pop();

                }
                else
                    return false;
            }
            else if(c=='}')
            {
                if (!st.empty() &&st.top()=='{'){
                    st.pop();

                }
                else
                    return false;
            }
            else if(c==']')
            {
                if (!st.empty() &&st.top()=='['){
                    st.pop();

                }
                else
                    return false;
            }

        }

        if(st.empty())
            return true;
        else
            return false;

        
    }
};
