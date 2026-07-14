class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        // Brute force: ith missing int = k+(no of elements present in the given
        // array)
        /*
        int missingNum =k;
        int n = arr.size();
        for(int i=0; i < n; i++){
            if(arr[i] <= missingNum){
                missingNum++;
            }else break;
        }
        return missingNum;
        */

        int n = arr.size();
        int low = 0, high =n-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            int missing = arr[mid]-(mid+1);
            if(missing<k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        } 
        return low+k;

        
/*Kth Missing Positive Number (Binary Search)

1. Missing numbers before index i:
   missing = arr[i] - (i + 1)

   Why?
   Total numbers till arr[i] = arr[i]
   Present numbers = i + 1
   Missing = arr[i] - (i + 1)

2. Binary Search:
   Find the first index where
   missing >= k

   After the loop:
   low  = first index with missing >= k
   high = low - 1

3. Answer Derivation:
   Answer = arr[high] + (k - missing)
          = arr[high] + k - (arr[high] - (high + 1))
          = high + 1 + k
          = low + k

Final Formula:
    return low + k;

Example:
arr = [2,3,4,7,11], k = 5

Index   : 0 1 2 3 4
Value   : 2 3 4 7 11
Missing : 1 1 1 3 6

Binary Search → low = 4
Answer = low + k = 4 + 5 = 9
*/

        


    }
};