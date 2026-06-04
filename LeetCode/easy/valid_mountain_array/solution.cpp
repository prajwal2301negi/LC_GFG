// Problem: Valid Mountain Array
// Difficulty: easy
// Runtime: 20 ms
// Memory: 26.2 MB

class Solution {
public:
    int bs(vector<int>& arr) {
        int low = 1;
        int high = arr.size() - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid] > arr[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    bool validMountainArray(vector<int>& arr) {
        int peak = bs(arr);

        if (peak == -1)
            return false;

        for (int i = 1; i <= peak; i++) {
            if (arr[i] <= arr[i - 1])
                return false;
        }

        for (int i = peak + 1; i < arr.size(); i++) {
            if (arr[i] >= arr[i - 1])
                return false;
        }
        return true;
    }
};