class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result="";
        for (const string& word : words) {
            long long total_weight = 0;
            
            // Step 1: Calculate total weight of the current word
            for (char c : word) {
                total_weight += weights[c - 'a'];
            }
            
            // Step 2: Take modulo 26
            int remainder = total_weight % 26;
            
            // Step 3: Map to reverse alphabetical character
            char mapped_char = 'z' - remainder;
            
            // Append the mapped character to our final result
            result += mapped_char;
        }
        
        return result;
    
    }
};