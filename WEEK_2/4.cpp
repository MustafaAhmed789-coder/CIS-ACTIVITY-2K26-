#include <bits/stdc++.h>
using namespace std;

long long count_payment_combinations(vector<int>& coins, int total_sum) {
    vector<long long> dp(total_sum + 1, 0);
    dp[0] = 1; 
    for (int coin : coins) {
        for (int s = coin; s <= total_sum; s++) {
            dp[s] += dp[s - coin];
        }
    }
    return dp[total_sum];
}

int main() {
    int n, total_sum;
    cin >> n >> total_sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << count_payment_combinations(coins, total_sum);
    return 0;
}
