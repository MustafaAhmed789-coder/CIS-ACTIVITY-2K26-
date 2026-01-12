#include <iostream>
using namespace std;

long long count_ways_to_summit(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    long long prev2 = 1;
    long long prev1 = 2; 
    long long curr;

    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;
    cout << count_ways_to_summit(n);
    return 0;
}
