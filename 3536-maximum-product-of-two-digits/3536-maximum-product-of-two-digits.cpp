class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while(n>0){
            digits.push_back(n%10);
            n/=10;
        }
        int max1=0,max2=0;
        for(int d : digits){
            if(d>max1){
                max2=max1;
                max1=d;
            }
            else if(d>max2){
                max2=d;
            }
        }
        return max1*max2;
    }
};