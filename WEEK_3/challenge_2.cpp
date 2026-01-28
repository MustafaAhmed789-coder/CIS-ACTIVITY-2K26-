#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> sorting_people(vector<pair<int,int>> people) {
    int length = people.size();

    for (int i = 0; i < length; i++) {
        int min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (people[j].first < people[min_index].first) {
                min_index = j;
            }
        }
        swap(people[i], people[min_index]);
    }
    return people;
}
pair<int, vector<pair<int,int>>> emergency_evacuation(
    vector<int>& weight,
    vector<int>& priority,
    int limit
) {
    vector<pair<int,int>> people;
    for (int i = 0; i < weight.size(); i++) {
        people.push_back({weight[i], priority[i]});
    }

    people = sorting_people(people);

    int l = 0, r = people.size() - 1;
    int result = 0;

    while (l <= r) {
        if (l < r &&
            people[l].first + people[r].first <= limit &&
            !(people[l].second == 1 && people[r].second == 1)) {
            l++;
            r--;
        } else {
            r--;
        }
        result++;
    }

    return {result, people};
}
string canpair(int x, int y,
               vector<int>& weight,
               vector<int>& priority,
               int limit) {
    if (weight[x] + weight[y] <= limit &&
        !(priority[x] == 1 && priority[y] == 1)) {
        return "Yes";
    }
    return "No";
}
int remaining(int B, vector<pair<int,int>> people, int limit) {
    sort(people.begin(), people.end());

    int l = 0, r = people.size() - 1;
    vector<int> boats;

    while (l <= r) {
        if (l < r &&
            people[l].first + people[r].first <= limit &&
            !(people[l].second == 1 && people[r].second == 1)) {
            boats.push_back(2);
            l++;
            r--;
        } else {
            boats.push_back(1);
            r--;
        }
    }

    sort(boats.begin(), boats.end(), greater<int>());

    int max_evacuated = 0;
    for (int i = 0; i < min(B, (int)boats.size()); i++) {
        max_evacuated += boats[i];
    }

    return people.size() - max_evacuated;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q, limit;
    cin >> N >> Q >> limit;

    vector<int> weight(N), priority(N);
    for (int i = 0; i < N; i++) cin >> weight[i];
    for (int i = 0; i < N; i++) cin >> priority[i];

    auto res = emergency_evacuation(weight, priority, limit);
    int boats = res.first;
    vector<pair<int,int>> sorted_people = res.second;

    cout << "Minimum boats = " << boats << "\n";

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CANPAIR") {
            int X, Y;
            cin >> X >> Y;
            cout << canpair(X, Y, weight, priority, limit) << "\n";
        }
        else if (query == "REMAINING") {
            int B;
            cin >> B;
            cout << remaining(B, sorted_people, limit) << "\n";
        }
    }

    return 0;
}
