class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       int m=grid.size();
       int n=grid[0].size();
       int total=m*n;
       k=k%total;
       vector<vector<int>> result(m,vector<int>(n));
       for(int r=0;r<m;r++){
        for(int c=0;c<n;c++){
            int new1DIndex=(r*n+c+k)%total;
            int new_r=new1DIndex/n;
            int new_c=new1DIndex%n;
            result[new_r][new_c]=grid[r][c];
        }
       } 
       return result;
    }
};