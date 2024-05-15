#include <vector>
#include <unordered_map>
#include <stack>
#include<iostream>
class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> nextGreater;
        std::stack<int> stack;

        
        for (int i = nums2.size() - 1; i >= 0; --i) {
            
            while (!stack.empty() && stack.top() <= nums2[i]) {
                stack.pop();
            }
            
            if (!stack.empty()) {
                nextGreater[nums2[i]] = stack.top();
            } else {
                nextGreater[nums2[i]] = -1;
            }
            
            stack.push(nums2[i]);
        }

        
        std::vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};
int main()
{
    std::vector<int> nums1 = {4, 1, 2};
    std::vector<int> nums2 = {1, 3, 4, 2};
    Solution solution;
    std::vector<int> result = solution.nextGreaterElement(nums1, nums2);

    
    std::cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}