class Solution {
    struct Data{
        int deadline;
        int profit;
    };
    
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        Data arr[n];
        
        for(int i=0;i<n;i++){
            arr[i].deadline = deadline[i];
            arr[i].profit = profit[i];
        }
        
        sort(arr, arr+n, [](Data a, Data b){return a.profit > b.profit;});
        
        int cnt = 0;
        int pro = 0;
        int maxDeadline = -1;
        for(int i=0;i<n;i++){
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        
        vector<int> hash(maxDeadline+1, -1);
        
        for(int i=0;i<n;i++){
            for(int j = arr[i].deadline; j>0;j--){
                if(hash[j]==-1){
                    hash[j] = 1;
                    cnt++;
                    pro += arr[i].profit;
                    break;
                    
                }
            }
        }
        
        return {cnt, pro};
    }
};