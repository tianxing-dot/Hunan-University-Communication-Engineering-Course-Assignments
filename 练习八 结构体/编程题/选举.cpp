// 选举
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    // city_wins[i] 存储编号为 i 的候选人赢得了多少个城市
    vector<int> city_wins(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        long long max_votes = -1;
        int city_winner = 1;

        for (int j = 1; j <= n; ++j) {
            long long current_votes;
            cin >> current_votes;
            
            // 规则1：得票最多者获胜；若相等，编号小者获胜
            if (current_votes > max_votes) {
                max_votes = current_votes;
                city_winner = j;
            }
        }
        // 记录该候选人赢得一个城市
        city_wins[city_winner]++;
    }

    // 规则2：赢得城市最多者获胜；若相等，编号小者获胜
    int final_winner = 1;
    int max_cities = -1;
    for (int i = 1; i <= n; ++i) {
        if (city_wins[i] > max_cities) {
            max_cities = city_wins[i];
            final_winner = i;
        }
    }

    cout << final_winner << endl;

    return 0;
}
