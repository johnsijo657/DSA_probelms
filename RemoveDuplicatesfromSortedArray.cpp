#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int k = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> nums1 = {1, 1, 2};
    cout << removeDuplicates(nums1) << ", nums = [";
    for (int i = 0; i < nums1.size(); i++) {
        if (i > 0) cout << ", ";
        cout << nums1[i];
    }
    cout << "]" << endl;

    return 0;
}

