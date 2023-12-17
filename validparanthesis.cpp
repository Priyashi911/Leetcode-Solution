#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if (st.empty())
                    return false;
                else {
                    if ((st.top() == '(' && s[i] == ')') ||
                        (st.top() == '[' && s[i] == ']') ||
                        (st.top() == '{' && s[i] == '}'))
                        st.pop();
                    else
                        return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    
    // Test cases
    std::cout << std::boolalpha; // to print 'true' or 'false' instead of '1' or '0'
    std::cout << solution.isValid("()") << std::endl;        // true
    std::cout << solution.isValid("()[]{}") << std::endl;    // true
    std::cout << solution.isValid("(]") << std::endl;         // false
    std::cout << solution.isValid("([)]") << std::endl;       // false
    std::cout << solution.isValid("{[]}") << std::endl;       // true

    return 0;
}
