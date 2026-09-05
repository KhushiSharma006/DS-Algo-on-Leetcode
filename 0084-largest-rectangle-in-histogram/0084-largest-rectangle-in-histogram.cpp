class Solution {
public:
    // T.C. = O(n)+O(n), S.C = O(n) 
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; //stores the index
        int n =heights.size();
        int maxArea = 0; 
        int nse, pse, element;

        for(int i =0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
               element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, heights[element] * (nse - pse -1));

            }

            st.push(i);
            
        }

        // if last 2 element left in the stack

        while(!st.empty()){
            nse = n;
            element  = st.top();
            st.pop();

            pse = st.empty() ? -1 : st.top();

            maxArea = max( maxArea, heights[element] * (nse-pse-1));

        }

        return maxArea;
    }





    /*
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
    */
};