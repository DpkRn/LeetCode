class MyCalendar(object):
    
    def __init__(self):
        self.cal=[]
        

    def book(self, start, end):
        for [s,e] in self.cal:
            if start<e and end>s:
                return False
        self.cal.append([start,end])
        return True
        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)