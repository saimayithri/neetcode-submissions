class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int num : asteroids)
        {
            bool destroyed = false;

            // collision possible only when:
            // stack top is moving right (+)
            // current asteroid moving left (-)

            while(!st.empty() && st.top() > 0 && num < 0)
            {
                // equal size -> both explode
                if(st.top() == abs(num))
                {
                    st.pop();
                    destroyed = true;
                    break;
                }

                // top asteroid smaller -> top explodes
                else if(st.top() < abs(num))
                {
                    st.pop();
                }

                // current asteroid smaller -> current explodes
                else
                {
                    destroyed = true;
                    break;
                }
            }

            // if current asteroid survived
            if(!destroyed)
            {
                st.push(num);
            }
        }

        // convert stack to vector

        vector<int> ans(st.size());

        for(int i = st.size()-1; i >= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};