#include <bits/stdc++.h>
using namespace std;

struct Message {
    int id;
    int sender;
    int content;
    bool critical;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q, K;
    cin >> N >> Q >> K;

    int message_id = 1;

    unordered_map<int, unordered_set<int>> follows;
    for (int i = 1; i <= N; i++) {
        follows[i] = unordered_set<int>();
    }

    vector<Message> messages; 
    unordered_map<int, deque<Message>> user_messages;
    for (int i = 1; i <= N; i++) {
        user_messages[i] = deque<Message>();
    }

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "B") {
            int u, m;
            cin >> u >> m;

            bool critical = (m % 3 == 0);
            Message msg = {message_id, u, m, critical};

            messages.push_back(msg);
            user_messages[u].push_back(msg);
            message_id++;

            if (user_messages[u].size() > K) {
                user_messages[u].pop_front();
            }
        }

        else if (cmd == "S") {
            int u, v;
            cin >> u >> v;
            follows[u].insert(v);
        }

        else if (cmd == "U") {
            int u, v;
            cin >> u >> v;
            follows[u].erase(v);
        }

        else if (cmd == "F") {
            int u;
            cin >> u;

            vector<int> feed_ids;
            for (int i = messages.size() - 1; i >= 0; i--) {
                Message &msg = messages[i];
                int sender = msg.sender;
                bool exists = false;
                for (auto &x : user_messages[sender]) {
                    if (x.id == msg.id) {
                        exists = true;
                        break;
                    }
                }

                if (!exists) continue;

                if (sender == u || follows[u].count(sender)) {
                    feed_ids.push_back(msg.id);
                }

                if (feed_ids.size() == 10) break;
            }

            if (feed_ids.empty()) {
                cout << "EMPTY\n";
            } else {
                for (int i = 0; i < feed_ids.size(); i++) {
                    if (i) cout << " ";
                    cout << feed_ids[i];
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
s