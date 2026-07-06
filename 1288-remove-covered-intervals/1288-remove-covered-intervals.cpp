class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end(),[](const std::vector<int>& a,const std::vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];

            }
            return a[0]<b[0];
        });
        int remainingcount=0;
        int maxend=0;
        for(const auto& interval : intervals){
            if(interval[1]>maxend){
                remainingcount++;
                maxend=interval[1];
            }
        }
        return remainingcount;
    }
};