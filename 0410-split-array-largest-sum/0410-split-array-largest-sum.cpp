class Solution {
public:
   
    int countPartitions(vector<int>&nums, int maxSum){
        int n = nums.size();
        int partition = 1;
        long long subArraySum =0;
        for(int i =0; i<n; i++){
            if(subArraySum + nums[i] <= maxSum){
                subArraySum+= nums[i];
            }
            else{
                partition++;
                subArraySum = nums[i];
            }
        }

        return partition;
    }
         
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low<=high){
            int mid = low+(high-low)/2;
            int partitions = countPartitions(nums, mid);
            if(partitions > k){ 
                // more than k partitions -> increase sum
                low = mid+1;
            } else{
                high= mid-1;
            }   
        }
        
        return low;
        
    }
};