class Solution {
public:

    // TC -> O(5N),  SC -> O(2N)
    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        return ans;
    }


    vector<int> findPSEE(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse  = findNSE(heights);
        vector<int> pse = findPSEE(heights);

        int maxi =0;
        int n =heights.size();

        for(int i =0; i<n; i++){
            maxi = max(maxi, heights[i] *(nse[i] - pse[i] -1));
        }

        return maxi;
        
    }
};