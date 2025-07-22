class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int cnt = 0;
        int prefixSum = 0;
        map<int, int> mp;
        mp[0] = 1;
        
        for(int i=0;i<n;i++){
            prefixSum += arr[i];
            cnt += mp[prefixSum-k];
            mp[prefixSum] += 1;
        }
        
        return cnt;
    }
};