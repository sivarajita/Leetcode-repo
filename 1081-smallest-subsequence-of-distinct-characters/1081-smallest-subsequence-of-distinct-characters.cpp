class Solution {
public:
    string smallestSubsequence(string s) {
        std::vector<int> count(26, 0);
        std::vector<bool> inStack(26, false);
        std::string result = "";
        
        // Step 1: Count total occurrences of each character
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Step 2: Iterate through the string
        for (char c : s) {
            // Decrement the remaining count for the current character
            count[c - 'a']--;
            
            // If character is already included in our result, skip it
            if (inStack[c - 'a']) {
                continue;
            }
            
            // Greedily pop characters that are larger than 'c' 
            // AND will appear again later in the string
            while (!result.empty() && result.back() > c && count[result.back() - 'a'] > 0) {
                inStack[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add the current character to our result
            result.push_back(c);
            inStack[c - 'a'] = true;
        }
        
        return result;
    }
};