struct Node {
    int max_len = 0;
    int pref_len = 0;
    int suff_len = 0;
    char left_char = 0;
    char right_char = 0;
};

class Solution {
    vector<Node> tree; // Now 'Node' is recognized!

    Node merge(const Node& left, const Node& right, int left_sz, int right_sz) {
        Node res;
        res.left_char = left.left_char;
        res.right_char = right.right_char;

        res.max_len = max(left.max_len, right.max_len);
        if (left.right_char == right.left_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }

        if (left.pref_len == left_sz && left.left_char == right.left_char) {
            res.pref_len = left.pref_len + right.pref_len;
        } else {
            res.pref_len = left.pref_len;
        }

        if (right.suff_len == right_sz && right.right_char == left.right_char) {
            res.suff_len = right.suff_len + left.suff_len;
        } else {
            res.suff_len = right.suff_len;
        }

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len;
        }

        return ans;
    }
};