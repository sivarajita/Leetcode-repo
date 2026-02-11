class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
         vector<int> count(1001, 0);
        vector<int> result;
        
        // Count frequency of elements in arr1
        for (int num : arr1) {
            count[num]++;
        }
        
        // Place elements according to arr2 order
        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        
        // Add remaining elements in ascending order
        for (int i = 0; i <= 1000; i++) {
            while (count[i] > 0) {
                result.push_back(i);
                count[i]--;
            }
        }
        
        return result;
    }
};