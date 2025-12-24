class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for (int x : apple) sum += x;

        sort(capacity.begin(), capacity.end(), greater<int>());

        int ans = 0;
        for (int c : capacity) {
            sum -= c;
            ans++;
            if (sum <= 0) return ans;
        }

        return ans;
    }
};
