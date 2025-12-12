class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
         ranges::sort(events,{},[](auto& e){
            return pair(stoi(e[1]),e[0][2]);

        });
        vector<int> ans(numberOfUsers);
        vector<int> online(numberOfUsers);
        for(auto& e : events){
            int curr = stoi(e[1]);
            string& mention=e[2];
            if(e[0][0]=='O'){
                online[stoi(mention)] = curr + 60;
            }
            else if(mention[0]=='A'){
                for(int& v : ans){
                    v++;
                }
            }
            else if 
                (mention[0] == 'H'){
                    for(int i=0;i<numberOfUsers;i++){
                        if(online[i]<=curr){
                            ans[i]++;
                        }
                    }
                } 
                else{
                    for(const auto& part : mention | ranges::views::split(' ')){
                        string s(part.begin()+2,part.end());
                        ans[stoi(s)]++;
                    }
                }

            }
            return ans;
    }
};