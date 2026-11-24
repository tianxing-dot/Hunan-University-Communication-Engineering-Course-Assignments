// 岁月留痕
#include <iostream>
using namespace std;

int main() 
{
    int common[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int common2[24],cl[24],lc[24];
    for (int i = 0; i < 12; ++i) 
	{
        common2[i] = common[i];
        common2[i + 12] = common[i];
        lc[i] = leap[i];
        lc[i + 12] = common[i];
        cl[i] = common[i];
        cl[i + 12] = leap[i];
    }
    int n;
    cin >> n;
    int a[24];
    for (int i = 0; i < n; ++i) 
	{
        cin >> a[i];
    }
    for (int i = 0; i <= 24 - n; ++i) 
	{
        bool match = true;
        for (int j = 0; j < n; ++j) 
		{
            if (common2[i + j] != a[j]) 
			{
                match = false;
                break;
            }
        }
        if (match) 
		{
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    
    for (int i = 0; i <= 24 - n; ++i) 
	{
        bool match = true;
        for (int j = 0; j < n; ++j) 
		{
            if (lc[i + j] != a[j]) 
			{
                match = false;
                break;
            }
        }
        if (match) 
		{
            cout << "Yes" << endl;
            return 0;
        }
    }
    for (int i = 0; i <= 24 - n; ++i) 
	{
        bool match = true;
        for (int j = 0; j < n; ++j) 
		{
            if (cl[i + j] != a[j]) 
			{
                match = false;
                break;
            }
        }
        if (match) 
		{
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
