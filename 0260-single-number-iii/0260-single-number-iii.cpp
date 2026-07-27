class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        long xorr =0;//to avoid the memory exceed
        int n = nums.size();

        for(int i = 0; i<n; i++){
            xorr = xorr^nums[i];
        }

        // rightmost set bit
        int rightmost = (xorr&(xorr-1)^xorr);
        
        int b1 =0, b2 =0;
        for(int i =0; i<n; i++){
            // split the element on the basis of rightmost set bit
            if(nums[i] & rightmost){
                b1 = b1^nums[i];
            }else{
                b2 = b2^nums[i];
            }
        }
        return {b1, b2};
        
    }
};