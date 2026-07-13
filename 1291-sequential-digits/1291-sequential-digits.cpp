class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        std::string digits = "123456789";
        
        // Determine the digit length boundaries
        int min_len = std::to_string(low).length();
        int max_len = std::to_string(high).length();
        
        // Iterate through all possible lengths
        for (int len = min_len; len <= max_len; ++len) {
            // Slide a window of size 'len' across the digits string
            for (int start = 0; start <= 9 - len; ++start) {
                std::string sub = digits.substr(start, len);
                int num = std::stoi(sub);
                
                // If it fits within our range, add it to the result
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};