class MyCalendar {
    map<int, int> booking_;
public:
    MyCalendar() {}
    
    inline bool book(int start, int end) {
        if (const auto it = booking_.upper_bound(start);
            it != booking_.end() && it->second < end) {
            return false;
        }

        booking_.emplace(make_pair(end,  start));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();