#include<iostream>
using namespace std;

class user
{
	int i;
	int sec[10];
	public: void readata(int);
};

void user::readata(int n)
{
	i=n;
}

int main()
{
	user u;
	cout<<"Enter the number of sections:";
	int n;
	cin>>n;
	u.readata(n);
}
