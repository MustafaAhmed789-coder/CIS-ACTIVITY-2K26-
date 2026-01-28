#include <bits/stdc++.h>
using namespace std;
vector<int> scrambled_keyword_search(string s, string p) {
    unordered_map<char, int> word_dict;
    unordered_map<char, int> search_dict;
    for (char c : p) {
        word_dict[c]++;
        if (!search_dict.count(c)) {
            search_dict[c] = 0;
        }
    }
    vector<int> result;
    int windowSize = p.length();
    for (int i = 0; i < s.length(); i++) {
        if (word_dict.count(s[i])) {
            search_dict[s[i]]++;
        }
        if (i >= windowSize) {
            char left_most = s[i - windowSize];
            if (search_dict.count(left_most)) {
                search_dict[left_most]--;
            }
        }
        if (i >= windowSize - 1) {
            if (search_dict == word_dict) {
                result.push_back(i - windowSize + 1);
            }
        }
    }
    return result;
}
int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> indices = scrambled_keyword_search(s, p);
    cout << "String: " << s << "\n";
    cout << "Pattern: " << p << "\n";
    cout << "Pattern found at: ";
    for (int idx : indices) {
        cout << idx << " ";}
    cout << "\n";return 0;
}
