// 看电影
#include<iostream>
#include<vector>
#include<map>
#include<algorithm> 
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    
	int n = 0;
	cin>>n;
	map<int,int> mp; 
	for(int i = 0;i<n;i++)
	{
		int language;
		cin>>language;
		mp[language]++;
	}
	int m = 0;
	cin>>m;
	vector<int> audio(m);
	vector<int> subtitle(m);
	for(int i = 0;i<m;i++) cin>>audio[i];
	for(int i = 0;i<m;i++) cin>>subtitle[i];
	int happy = -1;
	int satis = -1;
	vector<int> best;
	for(int i = 0;i<m;i++)
	{
		int curr1 = mp[audio[i]];
		int curr2 = mp[subtitle[i]];
		if(curr1>happy)
		{
			happy = curr1;
			satis = curr2;
			best = {i + 1};
		}
		else if(curr1==happy)
		{
			if(curr2>satis)
			{
				satis = curr2;
				best = {i + 1};
			}
			else if(curr2==satis)
			{
				best.push_back(i+1);
			}
		}
	}
	if(happy==0&&satis==0)
		cout<<"unsatisfied";
	else
	{
		sort(best.begin(),best.end());
		for(int i : best)
		{
			cout<<i<<" ";
		}
	}
}
