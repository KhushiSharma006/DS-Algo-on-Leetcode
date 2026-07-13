class Solution {
public:

    bool possible(vector<int>&bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int cnt =0;
        int bouquets =0;
        for(int i =0; i<n; i++){
            if(bloomDay[i] <= day){
                cnt++;
                if(cnt == k){
                    bouquets++;
                    cnt=0;
                }
            }
            else{
                cnt =0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        long long total = 1LL * m* k;

        int min = *min_element(bloomDay.begin(), bloomDay.end());
        int max = *max_element(bloomDay.begin(), bloomDay.end());

        if(total > bloomDay.size()) return -1;
         
        int low =min, high = max;
        int result =-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(bloomDay, mid, m, k)){
               result = mid;
                high =mid-1;
                
            }else{
                low = mid+1;
            }
        
        }
        return result;

        
    }
};