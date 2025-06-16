class Solution:
    def minMeetingRooms(self, start, end):
        start.sort()
        end.sort()
        
        res, count = 0, 0
        s, e = 0, 0
        
        while s < len(start):
            if start[s] < end[e]:
                count += 1
                s += 1
            else:
                e += 1
                count -= 1
            res = max(res, count)
        
        return res