class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int maxLen = 0;
        int prefixSum = 0;
        
        for(int i=0;i<n;i++){
            prefixSum += arr[i];
            
            if(prefixSum==k){
                maxLen = max(maxLen, i+1);
            }
            
            if(mp.find(prefixSum-k)!=mp.end()){
                maxLen = max(maxLen, i-mp[prefixSum-k]);
            }
            
            if(mp.find(prefixSum)==mp.end()){
                mp[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
};