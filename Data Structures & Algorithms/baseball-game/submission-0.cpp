class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string c:operations)
        {

            if(c=="+")
            {
                int temp1 =st.top();
                st.pop();
                int temp2 =st.top();
                

                
                st.push(temp1);
                st.push(temp1+temp2);
            }

            else if(c=="D")
            {
                int t=st.top();t=2*t; st.push(t);
            }
            else if(c=="C")
            {
                st.pop();
            }

            else
            {
                st.push(stoi(c));
            }
        }
        int sum=0;

        while(!st.empty())
        {
            sum+=st.top();st.pop();
        }
        return sum;


        
    }
};