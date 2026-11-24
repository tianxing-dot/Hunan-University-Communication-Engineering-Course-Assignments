// 松雅的旅馆
#include<iostream>
using namespace std;

int main()
{
	int n,d;
	cin>>n>>d;
	int s[n]={0};
	for (int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	int sum=2,d1=0;
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			if(s[i]>s[j])
			{	
				d1=s[i];
				s[i]=s[j];
				s[j]=d1;
			}
		}
	}
	for (int i=0;i<n-1;i++)
	{
		if ((s[i]+d)<(s[i+1]-d))
		{
			sum++;
			sum++;
		}
		else if ((s[i]+d)==(s[i+1]-d))
		{
			sum++;
		}
	}
	cout<<sum;
}

/*
可选优化版本
// 题目保证坐标严格递增，只要依次比较相邻旅馆的距离。时间 O(n)，额外空间 O(1)。
#include <iostream>
using namespace std;

int main() {
    int n;
    long long d, previous;
    cin >> n >> d >> previous;
    int choices = 2;
    for (int i = 1; i < n; ++i) {
        long long current;
        cin >> current;
        long long gap = current - previous;
        if (gap == 2 * d) {
            ++choices;
        } else if (gap > 2 * d) {
            choices += 2;
        }
        previous = current;
    }
    cout << choices;
}
*/
