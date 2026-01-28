#include <bits/stdc++.h>
using namespace std;

string suspicious_device(int length = -1) {
    vector<int> numbers;
    if (length != -1) {
        if (length % 2 != 0) {
            return "Length should be even";
        }

        numbers.resize(length);
        for (int i = 0; i < length; i++) {
            if (!(cin >> numbers[i])) {
                return "Insufficient numbers";
            }
        }
    }
    else {
        int x;
        while (cin >> x) {
            numbers.push_back(x);
        }
        length = numbers.size();
        if (length % 2 != 0) {
            return "Length should be even";
        }
    }
    unordered_set<int> seen;
    for (int num : numbers) {
        if (seen.count(num)) {
            return to_string(num);
        }
        seen.insert(num);
    }
    return "No repetition found";
}

int main() {
    cout << "Suspicious Number: " << suspicious_device() << "\n";

    return 0;
}
