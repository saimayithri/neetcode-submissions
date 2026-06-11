class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack <int>st;

        vector<int>results(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++)
        {
            while(!st.empty()&&temperatures[st.top()]<temperatures[i])
            {
                int prevInd=st.top();
                st.pop();
                results[prevInd]=i-prevInd;

            }
            st.push(i);
        }

        return results;
        
    }
};
