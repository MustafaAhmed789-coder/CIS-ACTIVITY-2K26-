#include<bits/stdc++.h>
using namespace std;

vector<int> teamImpact(const vector<int>& contro) {
    int n = contro.size();
    vector<int> impact(n, 1);
    int left_prod = 1;
    for (int i = 0; i < n; ++i) {
        impact[i] = left_prod;
        left_prod *= contro[i];}
    int right_prod = 1;
    for (int i = n - 1; i >= 0; --i) {
        impact[i] *= right_prod;
        right_prod *= contro[i];}
    return impact;
}
int main() {
    vector<int> contributions = {1, 2, 3, 4};
    vector<int> result = teamImpact(contributions);
    cout << "Impacts 1: ";
    for (int x : result){
        cout << x << " ";}
    cout << endl;
    vector<int> Arr = {-1, 1, 0, -3, 3};
    vector<int> res = teamImpact(Arr);
    cout << "Impact 2: ";
    for (int x : res){
        cout << x << " ";}
    cout << endl;
    return 0;
}

