// 火星人足球赛
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct player
{
	string team;
	int xvhao;
	int y;
	bool r;
	int time;
	void print()
	{
		cout<<team<<" "<<xvhao<<" "<<time<<endl;
	}
};
vector<player> ans;
void faxia(player& a)
{
	if(a.y==2||a.r)
	ans.push_back(a);
}
int main()
{
	ans.clear();
	string team_a,team_b;
	cin>>team_a>>team_b;
	vector<player> team1(100,{team_a,0,0,false,0});
	vector<player> team2(100,{team_b,0,0,false,0});
	for(int i = 1;i<100;i++)
	{
		team1[i].xvhao = i;
		team2[i].xvhao = i;
	}
	int n = 0;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		int time = 0;
		char team;
		int xv = 0;
		char card;
		cin>>time>>team>>xv>>card;
		if(team=='h')
		{
			team1[xv].time = time;
			if(card=='y')
			{
				team1[xv].y++;
				faxia(team1[xv]);
			}
			if(card=='r')
			{
				team1[xv].r=true;
				faxia(team1[xv]);
			}
		}
		if(team=='a')
		{
			team2[xv].time = time;
			if(card=='y')
			{
				team2[xv].y++;
				faxia(team2[xv]);
			}
			if(card=='r')
			{
				team2[xv].r=true;
				faxia(team2[xv]);
			}
		}
	}
	sort(ans.begin(),ans.end(),[&](const player& a1,const player& a2)
		{
			if(a1.time!=a2.time)
			return a1.time < a2.time; 
			if(a1.team!=a2.team)
			return a1.team == team_a;
			return a1.xvhao > a2.xvhao;
		});
		if(ans.empty())
		{
			cout<<"No Red Card";
			return 0;
		}
		for(player i : ans)
		{
			i.print();
		}
		return 0;
}
