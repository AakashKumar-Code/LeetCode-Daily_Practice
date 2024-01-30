class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (isdigit(tokens[i][0]) || (tokens[i].size() > 1 && (isdigit(tokens[i][1]) || tokens[i][1] == '-'))) {
                st.push(stoi(tokens[i]));
            } else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                switch (tokens[i][0]) {
                    case '+':
                        st.push(num1 + num2);
                        break;
                    case '-':
                        st.push(num1 - num2);
                        break;
                    case '*':
                        st.push(num1 * num2);
                        break;
                    case '/':
                        if (num2 == 0) {
                            // Handle division by zero
                            return 0; // You can modify this part based on your requirements
                        }
                        st.push(num1 / num2);
                        break;
                }
            }
        }
        return st.top();
    }
};
