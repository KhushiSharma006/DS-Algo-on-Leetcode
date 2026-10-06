class Solution {
public:

    int atmost(vector<int>&nums, int k){
         int l =0, r = 0;
        int count =0;
        map<int, int>mpp;

        while(r<nums.size()){
            mpp[nums[r]]++;

            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] ==0){
                    mpp.erase(nums[l]);
                }
                l = l+1;
            }
            count = count +(r-l+1);
            r++;
        }
        return count;
    } 
    

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k)- atmost(nums, k-1);

       
      
      /*
        //Brute Force using map:
        // T.C. = O(n^2), S.C. =O(n)

        int cnt = 0;
        int n =nums.size();
        
        for(int i =0; i<n; i++){
            map<int, int>mpp;

            for(int j =i; j<n; j++){
                mpp[nums[j]]++;
                if(mpp.size() == k){
                    cnt =cnt+1;
                }
                else if(mpp.size() > k){
                    break;
                }
            }
            
        }
        return cnt;
        */
    }
};