#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int asteroid : asteroids) {
        bool destroyed = false;

        while (!st.empty() && asteroid < 0 && st.top() > 0) {
            if (st.top() < -asteroid) {
                st.pop();
                continue;
            } else if (st.top() == -asteroid) {
                st.pop();
            }
            destroyed = true;
            break;
        }

        if (!destroyed) {
            st.push(asteroid);
        }
    }

    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        result[i] = st.top();
        st.pop();
    }

    return result;
}

int main() {
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> result1 = asteroidCollision(asteroids1);
    for (int asteroid : result1) {
        cout << asteroid << " ";
    }
    cout << endl;

    vector<int> asteroids2 = {8, -8};
    vector<int> result2 = asteroidCollision(asteroids2);
    for (int asteroid : result2) {
        cout << asteroid << " ";
    }
    cout << endl;

    vector<int> asteroids3 = {10, 2, -5};
    vector<int> result3 = asteroidCollision(asteroids3);
    for (int asteroid : result3) {
        cout << asteroid << " ";
    }
    cout << endl;

    return 0;
}
