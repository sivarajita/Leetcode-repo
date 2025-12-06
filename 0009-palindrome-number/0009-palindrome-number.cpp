class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        if(x!=0 && x%10==0){
            return false;
        }
        double reverse = 0,num = x;
        while(x>0){
            reverse = (reverse*10) + (x%10);
            x = x/10;
        }
        return reverse == num;
    }
};