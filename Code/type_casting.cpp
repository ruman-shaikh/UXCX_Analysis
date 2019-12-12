#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	int n, num = 0;
	for(int i=0;i<str.length() ;i++)
	{
		n=str[i]-48;
		num += n;
		num *= 10;
		//cout<<"\n"<<num;
	}
	num /= 10;
	cout<<"\n"<<num;
}
