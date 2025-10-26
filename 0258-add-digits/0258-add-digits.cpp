class Solution {

    int get_digit_sum(int n){
        int d_sum=0;
        while(n>0){
            int r = n%10;
            d_sum += r;
            n=n/10;
        }
        return d_sum;
    }
public:
    int addDigits(int num) {
        while(num>9){
            num = get_digit_sum(num);
        }
        return num;
    }
};