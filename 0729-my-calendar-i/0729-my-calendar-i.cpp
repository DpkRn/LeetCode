class MyCalendar {
private:
    set<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
         pair<int, int> event{start, end};
         auto nextEvent = calendar.lower_bound(event);
        if (nextEvent != calendar.end() && nextEvent->first < end) {
            return false;
        }
        
        if(nextEvent !=calendar.begin()){
            nextEvent--;
            if(start<nextEvent->second) return false;
        }
        calendar.insert(event);
        return true;
    }
};