class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_cost=0;
        for(int cost:costs){
            max_cost=max(max_cost,cost);
       }
       vector<int> freq(max_cost+1,0);
       for(int cost:costs){
        freq[cost]++;
       }
       int icecreamcount=0;
       for(int cost=1;cost<=max_cost;cost++){
        if(freq[cost]==0)
        continue;
        if(coins<cost)
        break;
        int countTobuy=min(freq[cost],coins/cost);
        icecreamcount+=countTobuy;
        coins-=countTobuy*cost;
       }
       return icecreamcount;
    }
};