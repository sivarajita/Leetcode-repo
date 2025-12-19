class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
       for(string ops : operations){
        if(ops == "C"){
            scores.pop_back();
        }
        else if(ops == "D"){
          scores.push_back(2*scores.back());

        }
        else if(ops == "+"){
            int n=scores.size();
            scores.push_back(scores[n-1]+scores[n-2]);
        }
        else
        {
          scores.push_back(stoi(ops));  
        }
    
       }
       int sum=0;
       for(int s : scores)
       sum+=s;
       return sum;
    }
};