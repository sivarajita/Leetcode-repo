class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initialOnes = 0;
        for (char c : s) {
            if (c == '1') initialOnes++;
        }

        // Form augmented string t = '1' + s + '1'
        std::string t = "1" + s + "1";

        // Decompose t into alternating segments of 0s and 1s
        // Store pairs: {character ('0' or '1'), length}
        std::vector<std::pair<char, int>> segments;
        int n = t.length();
        int i = 0;
        
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) {
                j++;
            }
            segments.push_back({t[i], j - i});
            i = j;
        }

        int maxDelta = 0;

        // Look for 1-segments surrounded by 0-segments on both sides
        // i.e., segments[i] is '1', segments[i-1] is '0', and segments[i+1] is '0'
        for (int idx = 1; idx < (int)segments.size() - 1; ++idx) {
            if (segments[idx].first == '1') {
                if (segments[idx - 1].first == '0' && segments[idx + 1].first == '0') {
                    int delta = segments[idx - 1].second + segments[idx + 1].second;
                    maxDelta = std::max(maxDelta, delta);
                }
            }
        }

        return initialOnes + maxDelta;
    }
};