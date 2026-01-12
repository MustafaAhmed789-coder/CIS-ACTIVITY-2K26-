#include <bits/stdc++.h>
using namespace std;

bool can_balance_scales(vector<int>& arr) {
    int total = 0;
    for (int x : arr) total += x;

    if (total % 2 != 0)
        return false;

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int weight : arr) {
        for (int j = target; j >= weight; j--) {
            dp[j] = dp[j] || dp[j - weight];
        }
    }
    return dp[target];
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (can_balance_scales(arr))
        cout << "True";
    else
        cout << "False";

    return 0;
}
