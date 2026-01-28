#include <bits/stdc++.h>
using namespace std;

int min_cancelled_bookings(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[1] < b[1];
         });

    int removals = 0;
    int last_end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < last_end) {
            removals++;
        } else {
            last_end = intervals[i][1];
        }
    }

    return removals;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    cout << min_cancelled_bookings(intervals);
    return 0;
}
