class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       unordered_set<int> unique_nums_set(nums.begin(),nums.end());
       vector<int> unique_nums(unique_nums_set.begin(),unique_nums_set.end());
       const int MAX_VAL=2048;
       vector<bool> current_reachable(MAX_VAL,false);
       current_reachable[0]=true;
       for(int step=0;step<3;step++){
        vector<bool> next_reachable(MAX_VAL,false);
        for(int val=0;val<MAX_VAL;val++){
            if(current_reachable[val]){
                for(int num:unique_nums){
                    next_reachable[val^num]=true;
                }
            }
        }
        current_reachable=move(next_reachable);
       } 
       int count=0;
       for(int val=0;val<MAX_VAL;val++){
        if(current_reachable[val]){
            count++;
        }
       }
       return count;
    }
};