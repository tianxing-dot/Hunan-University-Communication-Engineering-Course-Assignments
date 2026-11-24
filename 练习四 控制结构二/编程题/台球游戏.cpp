// 台球游戏
#include <iostream>
using namespace std;

int main()
{
	int n = 0,score=0,t=0;
	char m;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>m;
		if (m=='r')
		{
			cin>>t;
			score += t;
		}
		else if (m=='y')
			score += 2;
		else if (m=='g')
			score += 3;
		else if (m=='c')
			score += 4;
		else if (m=='b')
			score += 5;
		else if (m=='p')
			score += 6;
		else if (m=='B')
			score += 7;
	}
	cout<<score;
}
