class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        int n = arr.size();
        int maxLen = 0;
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            
            if(sum==k){
                maxLen = max(maxLen, i+1);
            }
            
            if(mp.find(sum-k)!=mp.end()){
                maxLen = max(maxLen, i-mp[sum-k]);
            }
            
            if(mp.find(sum)==mp.end()){
                mp[sum] = i;
            }
        }
        
        return maxLen;
    }
};