class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                // Opening bracket
                st.push(str[i]);
            } else {
                // Closing bracket
                if (st.empty()) {
                    return false;
                }

                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']')) {
                    st.pop();
                } else {
                    // No match
                    return false;
                }
            }
        }

        return st.empty();
    }
};