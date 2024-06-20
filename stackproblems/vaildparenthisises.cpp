#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    stack<char> stack;
    unordered_map<char, char> matchingBrackets = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char c : s) {
        if (matchingBrackets.find(c) != matchingBrackets.end()) {
            if (!stack.empty() && stack.top() == matchingBrackets[c]) {
                stack.pop();
            } else {
                return false;
            }
        } else {
            stack.push(c);
        }
    }

    return stack.empty();
}

int main() {
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";

    cout << isValid(s1) << endl; 
    cout << isValid(s2) << endl; 
    cout << isValid(s3) << endl; 

    return 0;
}
