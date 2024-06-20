#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    
    for (string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
        } else {
            st.push(stoi(token));
        }
    }
    
    return st.top();
}

int main() {
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    
    cout << "Result 1: " << evalRPN(tokens1) << endl; // Output: 9
    cout << "Result 2: " << evalRPN(tokens2) << endl; // Output: 6
    cout << "Result 3: " << evalRPN(tokens3) << endl; // Output: 22
    
    return 0;
}
