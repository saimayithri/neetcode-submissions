class Solution {
public:
    string decodeString(string s) {

        stack<char> st;
        stack<int> num;
        string ans = "";

        int number = 0;

        for (auto c : s) {

            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            }

            else if (c == '[') {
                num.push(number);
                number = 0;
                st.push(c);
            }

            else if (c == ']') {

                string temp = "";

                while (st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }

                st.pop(); // remove '['

                reverse(temp.begin(), temp.end());

                int i = num.top();
                num.pop();

                string decode = "";

                while (i--) {
                    decode += temp;
                }

                for (char ch : decode) {
                    st.push(ch);
                }
            }

            else {
                st.push(c);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};