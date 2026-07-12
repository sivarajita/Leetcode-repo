class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      vector<int> sorted_arr=arr;
      sort(sorted_arr.begin(),sorted_arr.end());
      unordered_map<int, int> rank_map;
      int rank=1;
      for(int num : sorted_arr){
        if(rank_map.find(num)==rank_map.end()){
            rank_map[num]=rank;
            rank++;
        }
      }
      vector<int> result;
      result.reserve(arr.size());
      for(int num:arr){
        result.push_back(rank_map[num]);
      }
      return result;

      
    }
};