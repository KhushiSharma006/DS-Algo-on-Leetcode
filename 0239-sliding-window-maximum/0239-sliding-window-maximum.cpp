class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       // Deque to store indices of useful elements in the current windo
        deque<int>dq;

        vector<int>result;

        for(int i =0; i< nums.size(); i++){
            // Remove elements from the front if they are out of this window's range
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            // Remove all elements from the back that are smaller than current element
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            
            // Once the first window is completed, add front element to result
            if(i >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }

        return result;





        
        /*
        vector<int>ans;
        int n =nums.size();

        for(int i =0; i<n-k+1; i++){
            int maxi = nums[i];
            for(int j = i; j < i+k; j++){
                maxi = max(nums[j], maxi);
                
            }
            ans.push_back(maxi);
        }

        return ans;
        */
        
    }
};