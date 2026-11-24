// 小希练打字
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

// 判断字符属于哪只手：0为左，1为右
int get_hand(char c) {
    static string left = "qwertasdfgzxcvbQWERTASDFGZXCVB";
    if (left.find(c) != string::npos) return 0;
    return 1;
}

void solve() {
    int n;
    while (cin >> n) {
        unordered_map<string, int> dict; // 记录单词及其初次输入的耗时
        long long total_time = 0;

        for (int i = 0; i < n; ++i) {
            string word;
            cin >> word;

            // 如果已经练过这个词，直接加一半时间
            if (dict.count(word)) {
                total_time += dict[word] / 2;
            } else {
                // 初次计算耗时
                int current_word_time = 2; // 第一个字母 0.2s
                for (int j = 1; j < word.length(); ++j) {
                    if (get_hand(word[j]) == get_hand(word[j-1])) {
                        current_word_time += 4; // 同侧 0.4s
                    } else {
                        current_word_time += 2; // 异侧 0.2s
                    }
                }
                dict[word] = current_word_time;
                total_time += current_word_time;
            }
        }
        cout << total_time << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
