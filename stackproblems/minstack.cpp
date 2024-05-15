#include<iostream>
#include<stack>
using namespace std;
class minstack
{
private:
    stack<int> mainstack;
    stack<int> minstack;
public:
       void push(int val)
       {
        mainstack.push(val);
        if( minstack.empty() || val<=minstack.top())
        {
           minstack.push(val);
        }
       }
       void pop()
       {
        if(mainstack.top()==minstack.top())
        {
            minstack.pop();
        }
        mainstack.pop();
       }
       int top()
       {
        return mainstack.top();
       }
       int getmin()
       {
        return minstack.top();
       }

};
int main() {
    
    minstack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    
    std::cout << "Minimum element in the stack: " << minStack.getmin() << std::endl;

    
    minStack.pop();

    
    std::cout << "Top element of the stack: " << minStack.top() << std::endl;

    return 0;
}