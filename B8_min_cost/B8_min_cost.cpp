#include "stdafx.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
vector <int> section;

void cut(int n)
{
	int dp [100][100]={0};
	for(int k=0;k<n;k++)         
		for(int l=k-2;l>=0;l--)
		{
			int min = INT_MAX;  
			int a = section[k]-section[l];
			for(int m=l+1;m<k;m++)
  			min = a + dp[l][m] + dp[m][k] < min ? a+dp[l][m] + dp[m][k]: min;
			dp[l][k]=min;
		}
		cout<< dp[0][n-1]<<endl;
		section.clear();
}


int main()
{
	int n,length,dec;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		
		cin>>length;
		section.push_back(0);
		while(1)
		{
			cin>>dec;
			if(dec>0)
			{
				section.push_back(dec);
			}
			else
				break;
		}
		section.push_back(length);
		cut(section.size());
			
	}
	return 0;
}


