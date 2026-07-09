class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // find the mid and check which half of the array is sorted
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Edge case: all three are equal, we cannot determine which side is
            // sorted
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            // check if left half is sorted
            if (nums[low] <= nums[mid]) {
                // If target lies in the sorted left half, search there
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                // search in sorted right half
                else {
                    low = mid + 1;
                }
            }

            // right half is sorted
            else {
                // If target lies in the sorted right half, search there
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};