class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0]=1;
        int xorr = 0;
        for(int i=0;i<n;i++){
            xorr ^= arr[i];
            cnt += mp[xorr^k];
            mp[xorr] += 1;
        }
        return cnt;
    }
};