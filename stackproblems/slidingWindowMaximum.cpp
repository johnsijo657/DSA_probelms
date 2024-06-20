#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> deq;
    vector<int> result;
    
    for (int i = 0; i < nums.size(); ++i) {
        if (!deq.empty() && deq.front() == i - k) {
            deq.pop_front();
        }
        
        while (!deq.empty() && nums[deq.back()] < nums[i]) {
            deq.pop_back();
        }
        
        deq.push_back(i);
        
        if (i >= k - 1) {
            result.push_back(nums[deq.front()]);
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);
    
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
