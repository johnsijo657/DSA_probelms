#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    unordered_set<char> chars;
    int maxLen = 0, left = 0, right = 0;

    while (right < n) {
        if (chars.find(s[right]) == chars.end()) {
            chars.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        } else {
            chars.erase(s[left]);
            left++;
        }
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << "Output: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}

