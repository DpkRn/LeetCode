class Solution {
public:
    int getNumber(string str, int &index) {
        int number=0, temp;
        while (isdigit(str[index])) {
            temp = str[index] - '0';
            number *= 10;
            number += temp;
            index++;
        }
        return number;
    }
    string getName(string str, int &index) {
        string name = string(1, str[index]);
        index++;
        while (index < str.length() && 'a' <= str[index] && str[index] <= 'z') {
            name += str[index];
            index++;
        }
        return name;
    }
    map<string, int> solve(string formula) {
        int i=0;
        map<string, int> ans;
        while (i < formula.length()) {
            if (formula[i] == '(') {
                int left = i+1, right;
                int temp = 1;
                while (temp > 0) {
                    i++;
                    if (formula[i] == '(') temp++;
                    else if (formula[i] == ')') temp--;
                }
                right = i;
                i++;
                map<string, int> subAns = solve(formula.substr(left, (right-left)));
                int number = 1;
                if (isdigit(formula[i])) {
                    number = getNumber(formula, i);
                }
                for (auto el: subAns) {
                    ans[el.first] += (el.second*number);
                }
            }
            else if (isalpha(formula[i])) {
                string name = getName(formula, i);
                if (isdigit(formula[i])) {
                    int number = getNumber(formula, i);
                    ans[name] += number;
                } else {
                    ans[name]++;
                }
            }
        }
        return ans;
    }
    string countOfAtoms(string formula) {
        map<string, int> ansMap = solve(formula);
        string ans = "";
        for (auto el: ansMap) {
            if (el.second == 1) {
                ans += el.first;
            } else {
                ans += el.first + to_string(el.second);
            }
        }
        return ans;
    }
};