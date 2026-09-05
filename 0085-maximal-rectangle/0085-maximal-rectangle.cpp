class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Stack stores indices of bars in increasing height order
        stack<int> st;
        int maxArea = 0;

        // Sentinel 0 forces remaining bars in stack to be processed
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {

            // Current bar is smaller, so calculate areas of previous bars
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                // Width extends from the next smaller bar on left to current
                // index
                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        // Empty matrix has no rectangle
        if (matrix.empty())
            return 0;

        int m = matrix[0].size();

        // Converts each row into a histogram
        vector<int> height(m, 0);
        int maxArea = 0;

        for (auto& row : matrix) {

            // Build histogram heights for the current row
            for (int i = 0; i < m; i++) {
                if (row[i] == '1')
                    height[i]++;
                else
                    height[i] = 0;
            }

            // Find largest rectangle in current histogram
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};