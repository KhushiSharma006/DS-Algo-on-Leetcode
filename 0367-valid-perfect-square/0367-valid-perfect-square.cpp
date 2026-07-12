class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 1) return num;
        int low = 0, high = num/2;

        while(low <= high){
            long long mid = low + (high-low)/2; 
            if(mid*mid == num){
                return true;
            }else if(mid*mid < num){
                low = mid+1;
            }else{
                high = mid-1;
            }
        } 
        return false;
    }
};