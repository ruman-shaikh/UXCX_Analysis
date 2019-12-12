#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

string age[100];
string gender[100];
string city[100];
string sec1[100];
string sec2[100];
string sec3[100];
string sec4[100];
int n=0;

int str_to_int(string str)
{
	int n, num = 0;
	for(int i=0;i<str.length() ;i++)
	{
		n=str[i]-48;
		num += n;
		num *= 10;
	}
	num /= 10;
	return num;
}

class user
{
	int a;
	string g;
	string c;
	int s1, s2, s3, s4;
	public: void readata(int);
			void disdata(int);
};

void user::readata(int x)
{
	a=str_to_int(age[x]);
	g=gender[x];
	c=city[x];
	s1=str_to_int(sec1[x]);
	s2=str_to_int(sec2[x]);
	s3=str_to_int(sec3[x]);
	s4=str_to_int(sec4[x]);
}

void user::disdata(int x)
{
	cout<<"Age: "<<a<<"\tGender: "<<g<<"\tCity: "<<c<<"\n";
	cout<<"Section 1: "<<s1<<"\tSection 2: "<<s2<<"\tSection 3: "<<s3<<"\tSection 4: "<<s4<<"\n";
}

int extract()
{
	ifstream in;
	in.open("userdata.csv");
	if (in.is_open()) 
	{
		cout<<"File found\n";
		while (!in.eof()) 
		{
    		getline(in, age[n], ',');
    		getline(in, gender[n], ',');
    		getline(in, city[n],',');
    		getline(in, sec1[n],',');
    		getline(in, sec2[n],',');
    		getline(in, sec3[n],',');
    		getline(in, sec4[n],'\n');
    		n++;
		}
		in.close();
		return 0;
	}
	else 
	{
		in.close();
		return 1;
	}
}

int main()
{
	user u[10];
	int i;
	extract();
	for(i=0;i<n;i++)
	{
		u[i].readata(i);
	}
	for(i=0;i<n;i++)
	{
		u[i].disdata(i);
	}
}
