#include <bits/stdc++.h>
using namespace std;

int calculate_minimum_speed(vector<int>& piles, long long k) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int answer = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long hours = 0;
        for (int bananas : piles) {
            hours += (bananas + mid - 1) / mid;
        }
        if (hours <= k) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    cout << calculate_minimum_speed(piles, k) << endl;
    return 0;
}
