#User function Template for python3
class Solution:
    def canAttend(self,arr):
        # Your Code Here
        arr.sort(key = lambda i: i[0])
        
        for i in range(1, len(arr)):
            end = arr[i-1][1]
            start = arr[i][0]
            
            if end > start:
                return False
        
        return True