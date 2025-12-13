class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    vector<string> validCoupons;
    map<string, int> businessOrder = {
        {"electronics", 0},
        {"grocery", 1},
        {"pharmacy", 2},
        {"restaurant", 3}
    };
    vector<tuple<int, string>> filtered;

    regex validCode("^[a-zA-Z0-9_]+$");

    for (int i = 0; i < code.size(); ++i) {
        if (!code[i].empty() && regex_match(code[i], validCode) &&
            businessOrder.count(businessLine[i]) && isActive[i]) {
            filtered.emplace_back(businessOrder[businessLine[i]], code[i]);
        }
    }

    sort(filtered.begin(), filtered.end());

    for (auto& entry : filtered) {
        validCoupons.push_back(get<1>(entry));
    }

    return validCoupons;
}
    
    };