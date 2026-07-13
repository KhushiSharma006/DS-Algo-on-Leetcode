class Solution {
public:

    long long sumByD(vector<int>& nums, int mid){
       long long sum =0;
        for(int i =0; i<nums.size(); i++){
            sum += ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        if (nums.size() > threshold) return -1;

        int low = 1;//divisor cant be 0
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low+(high-low)/2;

            if(sumByD(nums, mid) <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
        
    }
};