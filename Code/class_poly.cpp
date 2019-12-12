#include<iostream>
using namespace std;

int main()
{
	
	int ch, f;
	cout<<"Which file do you want to analyse:";
	cout<<"\n1. Normal User Data";
	cout<<"\n1. Beta User Data";
	cout<<"\nAny number more than 3\n";
	cin>>f;
	while(f<3)
	{
		if(f==1)
		{
			cout<<"Enter your choice:";
			cout<<"\n1. Display all data";
			cout<<"\n2. Display Max Used Sections";
			cout<<"\n3. Display Analysis\n";
			cin>>ch;
			void (*fnptr1)(normal_user []);
			switch(ch)
			{
				case 1: fnptr1=display_data;
						fnptr1(nu);
						break;
				case 2: fnptr1=display_with_max;
						fnptr1(nu);
						break;
				case 3: fnptr1=full_analysis;
						fnptr1(nu);
						break;
			}
		}
		else
		{
			cout<<"Enter your choice:";
			cout<<"\n1. Display all data";
			cout<<"\n2. Display Max Used Sections";
			cout<<"\n3. Display Analysis\n";
			cin>>ch;
			
			
		}
		cout<<"Which file do you want to analyse:";
		cout<<"\n1. Normal User Data";
		cout<<"\n1. Beta User Data";
		cout<<"\nAny number more than 3\n";
		cin>>f;
	}
}
