/*Given an array of integers nums and an integer target,
return indices of the two numbers such that they
add up to target. */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((nums[i] + nums[j]) == target) {
                    indexes.push_back(i);
                    indexes.push_back(j);
                }
            }
        }
        return indexes;
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    if (result.size() == 2) {
        cout << "Indices of the two numbers that add up to " << target << " are: "
                  << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No such indices found." << endl;
    }

    return 0;
}
