// 炸弹
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<int> row_cnt(n, 0);
    vector<int> col_cnt(m, 0);
    int total_walls = 0;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                row_cnt[i]++;
                col_cnt[j]++;
                total_walls++;
            }
        }
    }

    if (total_walls == 0) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int current_destroyed = row_cnt[i] + col_cnt[j];
            if (grid[i][j] == '*') {
                current_destroyed--; // 减去重叠计算的墙
            }
            if (current_destroyed == total_walls) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
