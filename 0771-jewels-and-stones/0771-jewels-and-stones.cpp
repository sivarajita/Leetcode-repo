class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        for(auto i:jewels)
         s.insert(i);
         int c=0;
         for(auto i:stones)
         if(s.find(i)!=s.end())
         c++;
         return c;
    }
};