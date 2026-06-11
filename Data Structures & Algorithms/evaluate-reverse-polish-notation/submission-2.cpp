class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int>st; int ans;

        for(string c: tokens)
        {
            int t1,t2;
            if(c=="+")
            {
                t1=st.top();
                st.pop();
                t2=st.top();st.pop();

                
                st.push(t2+t1);
            }
            else if(c=="-")
            {
                t1=st.top();
                st.pop();
                t2=st.top();st.pop();

               
                st.push(t2-t1);
            }           
            else if(c=="*")
            {
                t1=st.top();
                st.pop();
                t2=st.top(); st.pop();

                
                st.push(t2*t1);
            }
            else if(c=="/")
            {
                t1=st.top();
                st.pop();
                t2=st.top();st.pop();

                
                st.push(t2/t1);
            }
            else
            {
                st.push(stoi(c));
            }

        }

        ans=st.top();
        return ans;
        
        
    }
};
