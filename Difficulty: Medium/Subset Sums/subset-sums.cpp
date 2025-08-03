class Solution {
    void helper(int i, int n, int sum, vector<int>& res, vector<int>& arr){
        if(i>=n){
            res.push_back(sum);
            return ;
        }
        
        helper(i+1, n, sum+arr[i], res, arr);
        helper(i+1, n, sum, res, arr);
    }
    
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;
        helper(0, arr.size(), 0, res, arr);
        return res;
    }
};