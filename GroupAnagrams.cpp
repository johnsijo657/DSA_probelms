#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;

    for (const string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagrams[sortedStr].push_back(str);
    }

    vector<vector<string>> result;
    for (const auto& pair : anagrams) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    cout << "Output:" << endl;
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << ",";
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            if (j > 0) cout << ",";
            cout << result[i][j];
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}

