/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 * public:
 * int get(int index);
 * int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        // Step 1: Find the summit of the mountain
        int peakIndex = findPeak(mountainArr, n);
        
        // Step 2: Search the left side (strictly ascending)
        // We do this first because the problem asks for the minimum index
        int leftResult = binarySearchAscending(target, mountainArr, 0, peakIndex);
        if (leftResult != -1) {
            return leftResult; 
        }
        
        // Step 3: Search the right side (strictly descending)
        // Only executes if the target wasn't found on the left
        return binarySearchDescending(target, mountainArr, peakIndex + 1, n - 1);
    }

private:
    // Helper to find the peak index
    int findPeak(MountainArray &mountainArr, int n) {
        int l = 0;
        int r = n - 1; 
        
        while (l < r) {
            int mid = l + (r - l) / 2; 
            
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1; // Climbing up, peak is to the right
            } else {
                r = mid;     // Falling down (or at peak), peak is mid or to the left
            }
        }
        return l; 
    }

    // Helper for standard binary search (Ascending)
    int binarySearchAscending(int target, MountainArray &mountainArr, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = mountainArr.get(mid);
            
            if (midVal == target) {
                return mid;
            } else if (midVal < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }

    // Helper for reverse binary search (Descending)
    int binarySearchDescending(int target, MountainArray &mountainArr, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = mountainArr.get(mid);
            
            if (midVal == target) {
                return mid;
            } 
            // Notice the flipped logic here compared to ascending
            else if (midVal > target) {
                l = mid + 1; 
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};