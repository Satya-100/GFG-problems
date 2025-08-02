class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    struct Data{
        int start;
        int end;
    };
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        Data arr[n];
        
        for(int i=0;i<n;i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
        }
        
        sort(arr, arr+n, [](Data a, Data b){return a.end < b.end;});
        
        int freeTime = arr[0].end;
        int cnt = 1;
        
        for(int i=1;i<n;i++){
            if(arr[i].start > freeTime){
                cnt++;
                freeTime = arr[i].end;
            }
        }
        
        return cnt;
    }
};