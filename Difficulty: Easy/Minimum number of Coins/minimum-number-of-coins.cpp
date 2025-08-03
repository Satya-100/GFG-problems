// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int> currency = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int len = currency.size();
        vector<int> res;
        for(int i=len-1;i>=0;i--){
            while((N-currency[i])>=0){
                N -= currency[i];
                res.push_back(currency[i]);
            }
        }
        return res;
    }
};