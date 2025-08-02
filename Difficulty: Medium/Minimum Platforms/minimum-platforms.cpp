class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 1, j = 0;
        int res = 1, cnt = 1;
        
        while(i<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }else {
                cnt--;
                j++;
            }
            res = max(res, cnt);
        }
        
        return res;
    }
};
