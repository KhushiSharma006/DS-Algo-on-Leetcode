class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);  // score of current level

        for (char ch : s) {
            if (ch == '(') {
                st.push(0);  // new nested level
            } 
            else {
                int inner = st.top();
                st.pop();

                // "()" -> 1, "(A)" -> 2*A
                int score = (inner == 0) ? 1 : 2 * inner;

                // Add score to previous level
                st.top() += score;
            }
        }

        return st.top();
    }
};