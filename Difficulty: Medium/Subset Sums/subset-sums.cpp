class Solution {
    void helper(int i, int n, int sum, vector<int>& res, vector<int> temp, vector<int>& arr){
        if(i>=n){
            res.push_back(sum);
            return ;
        }
        
        temp.push_back(arr[i]);
        helper(i+1, n, sum+arr[i], res, temp, arr);
        temp.pop_back();
        helper(i+1, n, sum, res, temp, arr);
    }
    
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;
        helper(0, arr.size(), 0, res, {}, arr);
        return res;
    }
};