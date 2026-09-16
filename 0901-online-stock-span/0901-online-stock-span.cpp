class StockSpanner {
public:
    int idx = -1;
    stack<pair<int, int>> st;

    StockSpanner() {
        idx = -1;
        while (!st.empty()) {
            st.pop();
        }
    }

    int next(int price) {
        idx++;

        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int ans = idx - (st.empty() ? -1 : st.top().second);

        st.push({price, idx});

        return ans;
    }
};