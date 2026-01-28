#include <bits/stdc++.h>
using namespace std;

int findSlot(int x, vector<int>& parent) {
    if (parent[x] == x)
        return x;
    return parent[x] = findSlot(parent[x], parent);
}

vector<int> maximize_freelance_profit(vector<int>& deadlines,
                                      vector<int>& profits) {
    int n = deadlines.size();

    vector<pair<int,int>> jobs;
    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        jobs.push_back({profits[i], deadlines[i]});
        maxDeadline = max(maxDeadline, deadlines[i]);
    }
    sort(jobs.begin(), jobs.end(), greater<>());
    vector<int> parent(maxDeadline + 1);
    for (int i = 0; i <= maxDeadline; i++)
        parent[i] = i;
    int jobCount = 0, totalProfit = 0;
    for (auto& job : jobs) {
        int profit = job.first;
        int deadline = job.second;

        int availableSlot = findSlot(deadline, parent);

        if (availableSlot > 0) {
            jobCount++;
            totalProfit += profit;
            parent[availableSlot] = findSlot(availableSlot - 1, parent);
        }
    }
    return {jobCount, totalProfit};
}

int main() {
    int n;
    cin >> n;

    vector<int> deadlines(n), profits(n);
    for (int i = 0; i < n; i++) cin >> deadlines[i];
    for (int i = 0; i < n; i++) cin >> profits[i];
    vector<int> result = maximize_freelance_profit(deadlines, profits);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
