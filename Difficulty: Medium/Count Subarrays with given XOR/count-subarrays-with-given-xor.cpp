class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        long res = 0;
        long xorr = 0;
        map<long, long> mp;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            xorr ^= arr[i];
            res += mp[xorr^k];
            mp[xorr]++;
        }
        return res;
    }
};