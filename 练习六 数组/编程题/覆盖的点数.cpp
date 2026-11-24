// 覆盖的点数
#include<iostream>
using namespace std;
int main()
{
	int n = 0;
	cin>>n;
	int a[600000] = {};
	int k = 0;
	for(int i = 0;i<n;i++)
	{
		int start = 0,end = 0;
		cin>>start>>end;
		if(k<end)
			k = end;
		for(int j = start;j<=end;j++)
		{
			a[j]+=1;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		int t = 0;
		for(int j = 0;j<=k;j++)
		{
			if(a[j]==i)
				t+=1;
		}
		cout<<t<<" ";
	}
}

/*
可选优化版本
// 闭区间在左端点开始覆盖，在右端点的下一个坐标结束覆盖。
// 一次前缀和即可统计每种覆盖次数。时间 O(n + R)，R 为最大右端点。
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, last = 0;
    cin >> n;
    vector<int> change(600002), count(n + 1);
    for (int i = 0; i < n; ++i) {
        int left, right;
        cin >> left >> right;
        ++change[left];
        --change[right + 1];
        last = max(last, right);
    }
    int active = 0;
    for (int point = 0; point <= last; ++point) {
        active += change[point];
        ++count[active];
    }
    for (int k = 1; k <= n; ++k) {
        cout << count[k] << ' ';
    }
}
*/
