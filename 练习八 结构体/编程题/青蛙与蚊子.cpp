// 青蛙与蚊子
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct frog
{
	int place;
	int long_eat;
	int rank;
	int eat_time;
};
struct disfrog
{
	int place;
	int weight;
	bool be_eat;
};
int main()
{
	int n,m;
	cin>>n>>m;
	vector<frog> Frogs(n);
	for (int i=0;i<n;i++)
	{
		cin>>Frogs[i].place>>Frogs[i].long_eat;
		Frogs[i].rank=i;
		Frogs[i].eat_time=0;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (Frogs[i].place>Frogs[j].place)
			{
				frog tem=Frogs[i];
				Frogs[i]=Frogs[j];
				Frogs[j]=tem;
			}
		}
	}
	/*sort(Frogs.begin(),Frogs.end(),[](const frog& f1,const frog& f2){
		return f1.place > f2.place;
	});*/
	vector<disfrog> DisFrogs(m);
	int time=1;
	for (int i=0;i<m;i++)
	{
		cin>>DisFrogs[i].place>>DisFrogs[i].weight;
		DisFrogs[i].be_eat=false;
		for (int j=0;j<time;j++)
		{
			if (DisFrogs[j].be_eat)
			{
				continue;
			}
			for (int l=0;l<n;l++)
			{
				if (DisFrogs[j].place-Frogs[l].place>=0 && DisFrogs[j].place-Frogs[l].place<=Frogs[l].long_eat)
				{
					DisFrogs[j].be_eat=true;
					Frogs[l].long_eat+=DisFrogs[j].weight;
					Frogs[l].eat_time++;
					break;
				}
			}
		}
		time++;
	}
	bool flag=true;
	while(flag)
	{
		flag=false;
		for (int j=0;j<m;j++)
		{
			if (DisFrogs[j].be_eat)
			{
				continue;
			}
			for (int l=0;l<n;l++)
			{
				if (DisFrogs[j].place-Frogs[l].place>=0 && DisFrogs[j].place-Frogs[l].place<=Frogs[l].long_eat)
				{
					DisFrogs[j].be_eat=true;
					Frogs[l].long_eat+=DisFrogs[j].weight;
					Frogs[l].eat_time++;
					flag=true;
					break;
				}
			}
		}	
	} 
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (Frogs[i].rank>Frogs[j].rank)
			{
				frog tem=Frogs[i];
				Frogs[i]=Frogs[j];
				Frogs[j]=tem;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		cout<<Frogs[i].eat_time<<" "<<Frogs[i].long_eat<<endl;
	}
}
