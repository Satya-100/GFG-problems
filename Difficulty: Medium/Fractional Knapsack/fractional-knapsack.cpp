// class implemented

struct Item{
    int val;
    int wt;
};


class Solution {
    bool static comparator(Item a, Item b){
        double au = (double) a.val / (double) a.wt;
        double bu = (double) b.val / (double) b.wt;
        return au>bu;
    }
    
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        Item arr[n];
        
        for(int i=0;i<n;i++){
            arr[i].val = val[i];
            arr[i].wt = wt[i];
        }
        
        sort(arr, arr+n, comparator);
        
        double max_total = 0;
        double cur_wt = 0;
        
        for(int i=0;i<n;i++){
            if(cur_wt + arr[i].wt <= capacity){
                cur_wt += arr[i].wt;
                max_total += arr[i].val;
            } else{
                double remain = capacity - cur_wt;
                max_total += (arr[i].val / (double) arr[i].wt) * (double) remain;
                break;
            }
        }
        
        return max_total;
    }
};
