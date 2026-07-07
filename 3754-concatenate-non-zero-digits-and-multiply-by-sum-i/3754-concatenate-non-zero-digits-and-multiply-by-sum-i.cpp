class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)
        return 0;
        long long x=0;
        long long digit_sum=0;
        long long place_value=1;
         while(n>0){
            int digit=n%10;
            if(digit!=0){
                digit_sum+=digit;
                x+=digit*place_value;
                place_value*=10;
            }
            n/=10;
         }
         return x*digit_sum;
    }
};