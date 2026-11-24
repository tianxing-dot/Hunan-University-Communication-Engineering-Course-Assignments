// 评委打分
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct contest
{
	string name;
	int score;
};
bool compare(const contest& a,const contest& b)
{
	return a.score>b.score;
}
int main()
{
	int n;
	cin>>n;
	vector<contest> contests(n);
	for (int i=0;i<n;i++)
	{
		string name;
		int scores[7];
		cin>>name;
		int sum=0,max_score=0,min_score=101;
		for (int j=0;j<7;j++)
		{
			cin>>scores[j];
			sum+=scores[j];
			if (scores[j]>max_score) max_score=scores[j];
			if (scores[j]<min_score) min_score=scores[j];
		}
		int end_score=sum-min_score-max_score;
		contests[i]={name,end_score};
	}
	sort(contests.begin(),contests.end(),compare);
	for (int i=0;i<n;i++)
	{
		const contest& c=contests[i];
		cout<<c.name<<" "<<c.score<<endl;
	}
}
