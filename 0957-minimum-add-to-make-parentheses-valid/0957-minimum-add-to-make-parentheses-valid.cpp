class Solution {
public:
    int minAddToMakeValid(string s) {
      int open = 0;   // Tracks unbalanced open parentheses '('
    int close = 0;  // Tracks unbalanced close parentheses ')'

    for (char c : s) {
        if (c == '(') {
            open++;  // Found an open parenthesis, so increment the open count
        } else {
            if (open > 0) {
                open--;  // Balanced one open parenthesis with a closing parenthesis
            } else {
                close++;  // No open parenthesis to balance, so increment close count
            }
        }
    }

    // The answer is the sum of unbalanced open and close parentheses
    return open + close;
    }
};