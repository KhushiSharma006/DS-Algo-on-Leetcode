class Solution {
public:
    int maxProduct(vector<int>& nums) {
    // optimal solution1:
     /*Algorithm:
        1. Traverse the array from both directions simultaneously.
        2. Maintain:
             - prefix = product from left to right
             - suffix = product from right to left
        3. If the running product becomes 0, reset it to 1 because
           any subarray after 0 starts a new product.
        4. Why scan from both sides?
             - If the array has an even number of negative numbers,
               the entire product is positive.
             - If it has an odd number of negative numbers,
               the maximum product is obtained by excluding either:
                 a) the prefix up to the first negative, or
                 b) the suffix after the last negative.
             - Prefix scan handles one case, suffix scan handles the other.
        5. At every step, update the maximum product found.
     */
    int n = nums.size();
    int prefix=1, suffix =1;
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        if(prefix == 0) prefix =1;
        if(suffix == 0) suffix =1;
        prefix = prefix*nums[i];
        suffix = suffix*nums[n-i-1];
        ans = max(ans, max(prefix,suffix));
        
    }
    
     return ans;
        
    }
};