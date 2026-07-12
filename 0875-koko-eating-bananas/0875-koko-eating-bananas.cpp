class Solution {
public:

    long long calTotalHours(vector<int>&piles, int hours){
        long long totalHr = 0;
        for(int bananas: piles){
            // totalHr += ceil((double)bananas/hours);
            totalHr += (bananas + hours - 1) / hours;
        }
        return totalHr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxpile = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxpile;
        int ans = maxpile;

        while(low <= high){
            int mid = low + (high-low)/2;
            long long totalHr = calTotalHours(piles,mid);
            if(totalHr <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
        
    }
};