#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> mn, mx;

    SegTree(vector<int>& a) {
        n = a.size();
        mn.resize(4 * n);
        mx.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, vector<int>& a) {
        if (l == r) {
            mn[node] = mx[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
    }

    int getMin(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return INT_MAX;
        if (ql <= l && r <= qr) return mn[node];
        int mid = (l + r) / 2;
        return min(getMin(node * 2, l, mid, ql, qr),
                   getMin(node * 2 + 1, mid + 1, r, ql, qr));
    }

    int getMax(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return INT_MIN;
        if (ql <= l && r <= qr) return mx[node];
        int mid = (l + r) / 2;
        return max(getMax(node * 2, l, mid, ql, qr),
                   getMax(node * 2 + 1, mid + 1, r, ql, qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    SegTree st(t);
    vector<int> alert(n, -1);
    for (int i = 0; i < n; i++) {
        int lo = i + 1, hi = n - 1, ans = -1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int mn = st.getMin(1, 0, n - 1, i + 1, mid);
            int mx = st.getMax(1, 0, n - 1, i + 1, mid);

            if (mx >= t[i] + k || mn <= t[i] - k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        alert[i] = ans;
    }

    // Prefix sum for COUNT queries
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + (alert[i] != -1);

    // Queries
    while (q--) {
        string op;
        cin >> op;

        if (op == "NEXT") {
            int x;
            cin >> x;
            if (alert[x] == -1)
                cout << "No Alert\n";
            else
                cout << alert[x] << "\n";
        } else {
            int l, r;
            cin >> l >> r;
            cout << pref[r + 1] - pref[l] << "\n";
        }
    }

    return 0;
}
