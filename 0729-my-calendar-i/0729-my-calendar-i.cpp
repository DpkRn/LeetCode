class MyCalendar {
    vector<vector<int>> cal;
public:
    MyCalendar() {  }

    bool book(int start, int end) {
        for (auto it : cal) {
            if (it[0] <= start && start < it[1] ||
                it[0] < end && end <= it[1] || start<=it[0]&&it[1]<=end) {
                return false;
            }
        }
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */