class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
       unordered_map<int, int> rowMasks;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << col);
            }
        }

        // Each row without any relevant reservations can fit 2 families
        int maxFamilies = (n - rowMasks.size()) * 2;

        int leftMask   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); // seats 2, 3, 4, 5
        int rightMask  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9); // seats 6, 7, 8, 9
        int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); // seats 4, 5, 6, 7

        for (auto& [row, mask] : rowMasks) {
            bool leftFree   = (mask & leftMask) == 0;
            bool rightFree  = (mask & rightMask) == 0;
            bool middleFree = (mask & middleMask) == 0;

            if (leftFree && rightFree) {
                maxFamilies += 2;
            } else if (leftFree || rightFree || middleFree) {
                maxFamilies += 1;
            }
        }

        return maxFamilies; 
    }
};