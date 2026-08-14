class Solution {
public:
   
    vector<int> findNSE(vector<int>&arr){
        int n =arr.size();

        stack<int>st;
        vector<int> ans(n);

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            ans[i] = !st.empty()? st.top() : n;
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSEE(vector<int> &arr){
        int n = arr.size();

        stack<int>st;
        vector<int>ans(n);

        for(int i =0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            ans[i] = !st.empty()? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        // NOTE> we need index of nse and psee to calculate the no of times an element repeated
        // NSE: next smallest element
        // PSEE: previous smallest or equal element

        vector <int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int mod = 1e9 + 7;

        int sum =0;

        for(int i =0; i<arr.size(); i++){
            int left = i-psee[i];
            int right = nse[i] -i;

            sum = (sum + (left*right*1LL * arr[i]) % mod) %mod;
           /* long long freq = left*right*1LL;
            
            // Contribution due to current element 
            int val = (freq*arr[i]*1LL) % mod;
            
            // Updating the sum
            sum = (sum + val) % mod;*/

        }
        return sum;


        /*
        // Brute force: T.C. = O(n^2)
        int mod = 1e9 + 7;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            int mini = arr[i];
            for (int j = i; j < arr.size(); j++) {
                mini = min(mini, arr[j]);
                sum = (sum + mini) % mod;
            }
        }

        return sum;
        */
    }
};