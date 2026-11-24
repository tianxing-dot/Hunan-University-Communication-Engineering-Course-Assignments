// 公共钥匙盒
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义事件结构体
struct Event {
    int time;   // 事件发生的时间
    int type;   // 类型：0 代表取钥匙，1 代表还钥匙（1大于0，方便排序逻辑）
    int id;     // 钥匙编号

    // 重载比较运算符，建立优先级系统
    bool operator<(const Event& other) const {
        if (time != other.time) return time < other.time; // 时间升序
        if (type != other.type) return type > other.type; // 同一时间，还(1)优先于取(0)
        return id < other.id; // 同为还钥匙，编号小的优先
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> hooks(N + 1);
    for (int i = 1; i <= N; ++i) hooks[i] = i;
    vector<Event> events;
    for (int i = 0; i < K; ++i) 
	{
        int w, s, c;
        cin >> w >> s >> c;
        events.push_back({s, 0, w});     
        events.push_back({s + c, 1, w});
    }
    sort(events.begin(), events.end());
    for (auto& e : events) {
        if (e.type == 0) 
		{
            for (int i = 1; i <= N; ++i) 
			{
                if (hooks[i] == e.id) 
				{
                    hooks[i] = 0;
                    break;
                }
            }
        } else 
		{	
            for (int i = 1; i <= N; ++i) 
			{
                if (hooks[i] == 0) 
				{
                    hooks[i] = e.id;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << hooks[i] << (i == N ? "" : " ");
    }
    cout << endl;
    return 0;
}
