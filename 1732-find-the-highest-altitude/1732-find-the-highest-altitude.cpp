class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int maxa=0;
       int curr=0;
       for(int i=0;i<gain.size();i++){
        curr+=gain[i];
        maxa=max(maxa,curr);
       }
       return maxa;

    }
};