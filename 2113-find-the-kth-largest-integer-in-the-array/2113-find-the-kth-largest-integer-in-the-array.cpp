class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
         auto cmp = [](const string& a, const string& b) {
        if (a.size() == b.size()) {
            return a > b; // Smaller numbers come first lexicographically
        }
        return a.size() > b.size(); // Compare based on length
    };

    // Min-heap with the custom comparator
    priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

    for (const string& num : nums) {
        pq.push(num);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
    }
};