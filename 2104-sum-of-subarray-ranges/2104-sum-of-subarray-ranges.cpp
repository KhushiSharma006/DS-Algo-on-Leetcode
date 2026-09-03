class Solution {
public:

/*
Sum of Ranges
      ↓
Sum of Maximums − Sum of Minimums
      ↓
Maximum → NGE + PGEE
Minimum → NSE + PSEE
      ↓
Contribution = nums[i] × left × right

Time: O(n)
Space: O(n)
*/

//  --------------------for sum of subarray min-----------------------

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


    long long sumSubarrayMins(vector<int>& nums) {

        // NSE, PSEE

        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);

        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            long long left = i - psee[i];
            long long right = nse[i] - i;

            sum += left * right * nums[i];
        }

        return sum;
    }


//  --------------------for sum of subarray max-----------------------

    vector<int> findNGE(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        return ans;
    }


    vector<int> findPGEE(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        return ans;
    }


    long long sumSubarrayMax(vector<int>& nums) {

        // NGE, PGEE

        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);

        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            long long left = i - pgee[i];
            long long right = nge[i] - i;

            sum += left * right * nums[i];
        }

        return sum;
    }


//  -----------------for sum of subarray ranges-----------------------

    long long subArrayRanges(vector<int>& nums) {

        // ∑ (subarray max) - ∑ (subarray min)

        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};




/*
class Solution {
public:
  
    
  // Brute force: O(n^2)

    long long subArrayRanges(vector<int>& nums) {
       
        long long sum =0;
        int n = nums.size();
        for(int i =0; i<n; i++){
            int smallest = nums[i];
            int largest = nums[i];

            for(int j =i+1; j<n; j++){
                smallest = min(smallest, nums[j]);
                largest = max(largest, nums[j]);
                sum = sum +(largest-smallest);
            }
        }

        return sum;
        
    }
    
};
*/