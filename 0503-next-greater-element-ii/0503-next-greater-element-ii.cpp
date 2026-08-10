class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // use hypothetical double array
        int n = nums.size();
        vector<int>nge(n);
        stack<int>st;

        for(int i = 2*n-1; i>=0; i--){
            int ind = i%n;

            while(!st.empty() &&  st.top() <= nums[ind]){
                st.pop();
            }

            if(i < n){
                if(st.empty()) nge[i] = -1;
                else nge[i] = st.top();
            }
            st.push(nums[ind]);

        }

        return nge;

        
    }
};