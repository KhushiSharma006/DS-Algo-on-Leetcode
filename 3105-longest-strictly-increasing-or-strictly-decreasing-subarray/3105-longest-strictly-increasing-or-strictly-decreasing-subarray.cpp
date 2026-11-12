class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        /*
        Approach: Single Traversal (O(n))
 
        Maintain two counters:
        inc – length of the current strictly increasing subarray.
        dec – length of the current strictly decreasing subarray.
        */
        
        int inc =1, dec =1;
        int ans =1;

        for(int i =1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                inc++;
                dec =1;
            }
            else if(nums[i] < nums[i-1]){
                dec++;
                inc = 1;
            }
            else{
                inc = 1;
                dec =1;
            }
            ans = max(ans, max(inc, dec));
        }
        return ans;
    }
};