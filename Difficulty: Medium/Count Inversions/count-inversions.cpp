class Solution {
    int merge(vector<int>& arr, int l, int mid, int r){
        int low = l;
        int high = mid+1;
        int cnt = 0;
        vector<int> temp;
        
        while(low<=mid && high<=r){
            if(arr[low]<=arr[high]){
                temp.push_back(arr[low]);
                low++;
            }else{
                temp.push_back(arr[high]);
                high++;
                cnt += mid-low+1;
            }
        }
        
        while(low<=mid){
            temp.push_back(arr[low]);
            low++;
        }
        
        while(high<=r){
            temp.push_back(arr[high]);
            high++;
        }
        
        for(int i=l;i<=r;i++){
            arr[i] = temp[i-l];
        }
        
        return cnt;
    }
    
    int mergeSort(vector<int>& arr, int l, int r){
        int cnt = 0;
        if(l==r)    return cnt;
        int mid = (l+r)/2;
        
        cnt += mergeSort(arr, l, mid);
        cnt += mergeSort(arr, mid+1, r);
        cnt += merge(arr, l, mid, r);
        
        return cnt;
    }
    
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        return mergeSort(arr, 0, arr.size()-1);
    }
};