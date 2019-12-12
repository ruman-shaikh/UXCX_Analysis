#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

int n1=12;

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

int find_max(int a, int b, int c, int d)
{
	int mu;
	int max, m1, m2;
	m1 = (a > b? a : b); 
	m2 = (c > d? c : d); 
	max = (m1 > m2? m1 : m2);
	if (max==a)
		mu=1;
	else if(max==b)
		mu=2;
	else if(max==c)
		mu=3;
	else if(max==d)
		mu=4;
	return mu;
}

class user
{
	public: int a;
			string g;
			string c;
			int s1, s2, s3, s4;
			void readata(int, char[]);
			void disinfo(int);
			void disusage(float);
};

void user::readata(int x, char ch[100])
{
	string age;
	string gender;
	string city;
	string sec1, sec2, sec3, sec4;
	int i;
	ifstream in;
	in.open(ch);
	if (in.is_open()) 
	{
		for(i=0;i<=x;i++)
		{
    		getline(in, age, ',');
    		getline(in, gender, ',');
    		getline(in, city,',');
    		getline(in, sec1,',');
    		getline(in, sec2,',');
    		getline(in, sec3,',');
    		getline(in, sec4,'\n');
		}
		in.close();
	}
	a=str_to_int(age);
	g=gender;
	c=city;
	s1=str_to_int(sec1);
	s2=str_to_int(sec2);
	s3=str_to_int(sec3);
	s4=str_to_int(sec4);
}

void user::disinfo(int x)
{
	cout<<"Age: "<<a<<"\tGender: "<<g<<"\tCity: "<<c<<"\n";
}

void user::disusage(float x)
{
	cout<<"Section 1: "<<s1<<"\tSection 2: "<<s2<<"\tSection 3: "<<s3<<"\tSection 4: "<<s4<<"\n";
}

class normal_user:public user
{
	public: int max_user;
			void analysis();
			void display();
			friend int grouping_age(normal_user);
			friend int grouping_gender(normal_user);
			friend int grouping_city(normal_user);
};

void normal_user::analysis()
{
	max_user=find_max(s1, s2, s3, s4);
}

void normal_user::display()
{
	cout<<"Maximum used section is: "<<max_user<<"\n\n";
}

int grouping_age(normal_user u)
{
	if(u.a<20)
		return 0;
	else if(u.a>=20 && u.a<=40)
		return 1;
	else
		return 2;
}

int grouping_gender(normal_user u)
{
	string temp="F";
	if(u.g==temp)
		return 0;
	else return 1;
}

int grouping_city(normal_user u)
{
	if(u.c=="Kolkata")
		return 0;
	else if(u.c=="Mumbai")
		return 1;
	else if(u.c=="Bengalore")
		return 2;
	else if(u.c=="Delhi")
		return 3;
}

class beta_user:public user
{
	public: int max_user;
			void analysis();
			void display();
			friend int beta_grouping_age(beta_user);
			friend int beta_grouping_gender(beta_user);
};

void beta_user::analysis()
{
	max_user=find_max(s1, s2, s3, s4);
}

void beta_user::display()
{
	cout<<"Maximum used section is: "<<max_user<<"\n\n";
}

int beta_grouping_age(beta_user u)
{
	if(u.a<20)
		return 0;
	else if(u.a>=20 && u.a<=40)
		return 1;
	else
		return 2;
}

int beta_grouping_gender(beta_user u)
{
	string temp="F";
	if(u.g==temp)
		return 0;
	else return 1;
}

void age_analysis(normal_user nu[])
{
	int i, f;
	int cs01, cs02, cs03, cs04;
	int cs11, cs12, cs13, cs14;
	int cs21, cs22, cs23, cs24;
	cs01=cs02=cs03=cs04=cs11=cs12=cs13=cs14=cs21=cs22=cs23=cs24=0;
	for(i=0;i<n1;i++)
	{
		int f=grouping_age(nu[i]);
		if(f==0)
		{
			if(nu[i].max_user==1)
				cs01++;
			else if(nu[i].max_user==2)
				cs02++;
			else if(nu[i].max_user==3)
				cs03++;
			else if(nu[i].max_user==4)
				cs04++;
		}
		else if(f==1)
		{
			if(nu[i].max_user==1)
				cs11++;
			else if(nu[i].max_user==2)
				cs12++;
			else if(nu[i].max_user==3)
				cs13++;
			else if(nu[i].max_user==4)
				cs14++;
		}
		else
		{
			if(nu[i].max_user==1)
				cs21++;
			else if(nu[i].max_user==2)
				cs22++;
			else if(nu[i].max_user==3)
				cs23++;
			else if(nu[i].max_user==4)
				cs24++;
		}
	}
	cout<<"The most used section used by age group below 20 is section "<<find_max(cs01, cs02, cs03, cs04)<<"\n";
	cout<<"The most used section used by age group between 20 and 40 is section "<<find_max(cs11, cs12, cs13, cs14)<<"\n";
	cout<<"The most used section used by age group above 40 is section "<<find_max(cs21, cs22, cs23, cs24)<<"\n";
}

void gender_analysis(normal_user nu[])
{
	int i, f;
	int cs01, cs02, cs03, cs04;
	int cs11, cs12, cs13, cs14;
	cs01=cs02=cs03=cs04=cs11=cs12=cs13=cs14=0;
	for(i=0;i<n1;i++)
	{
		int f=grouping_gender(nu[i]);
		if(f==0)
		{
			if(nu[i].max_user==1)
				cs01++;
			else if(nu[i].max_user==2)
				cs02++;
			else if(nu[i].max_user==3)
				cs03++;
			else if(nu[i].max_user==4)
				cs04++;
		}
		else
		{
			if(nu[i].max_user==1)
				cs11++;
			else if(nu[i].max_user==2)
				cs12++;
			else if(nu[i].max_user==3)
				cs13++;
			else if(nu[i].max_user==4)
				cs14++;
		}
	}
	cout<<"The most used section used by females is section "<<find_max(cs01, cs02, cs03, cs04)<<"\n";
	cout<<"The most used section used by males is section "<<find_max(cs11, cs12, cs13, cs14)<<"\n";
}

void city_analysis(normal_user nu[])
{
	int i, f;
	int cs01, cs02, cs03, cs04;
	int cs11, cs12, cs13, cs14;
	int cs21, cs22, cs23, cs24;
	int cs31, cs32, cs33, cs34;
	cs01=cs02=cs03=cs04=cs11=cs12=cs13=cs14=cs21=cs22=cs23=cs24=0;
	cs31=cs32=cs33=cs34=0;
	for(i=0;i<n1;i++)
	{
		int f=grouping_city(nu[i]);
		if(f==0)
		{
			if(nu[i].max_user==1)
				cs01++;
			else if(nu[i].max_user==2)
				cs02++;
			else if(nu[i].max_user==3)
				cs03++;
			else if(nu[i].max_user==4)
				cs04++;
		}
		else if(f==1)
		{
			if(nu[i].max_user==1)
				cs11++;
			else if(nu[i].max_user==2)
				cs12++;
			else if(nu[i].max_user==3)
				cs13++;
			else if(nu[i].max_user==4)
				cs14++;
		}
		else if(f==2)
		{
			if(nu[i].max_user==1)
				cs21++;
			else if(nu[i].max_user==2)
				cs22++;
			else if(nu[i].max_user==3)
				cs23++;
			else if(nu[i].max_user==4)
				cs24++;
		}
		else
		{
			if(nu[i].max_user==1)
				cs31++;
			else if(nu[i].max_user==2)
				cs32++;
			else if(nu[i].max_user==3)
				cs33++;
			else if(nu[i].max_user==4)
				cs34++;
		}
	}
	cout<<"The most used section used by people living in Kolkata is section "<<find_max(cs01, cs02, cs03, cs04)<<"\n";
	cout<<"The most used section used by people living in Mumbai is section "<<find_max(cs11, cs12, cs13, cs14)<<"\n";
	cout<<"The most used section used by people living in Bengalore is section "<<find_max(cs21, cs22, cs23, cs24)<<"\n";
	cout<<"The most used section used by people living in Delhi is section "<<find_max(cs31, cs32, cs33, cs34)<<"\n";
}

void beta_age_analysis(beta_user nu[])
{
	int i, f;
	int cs01, cs02, cs03, cs04;
	int cs11, cs12, cs13, cs14;
	int cs21, cs22, cs23, cs24;
	cs01=cs02=cs03=cs04=cs11=cs12=cs13=cs14=cs21=cs22=cs23=cs24=0;
	for(i=0;i<10;i++)
	{
		int f=beta_grouping_age(nu[i]);
		if(f==0)
		{
			if(nu[i].max_user==1)
				cs01++;
			else if(nu[i].max_user==2)
				cs02++;
			else if(nu[i].max_user==3)
				cs03++;
			else if(nu[i].max_user==4)
				cs04++;
		}
		else if(f==1)
		{
			if(nu[i].max_user==1)
				cs11++;
			else if(nu[i].max_user==2)
				cs12++;
			else if(nu[i].max_user==3)
				cs13++;
			else if(nu[i].max_user==4)
				cs14++;
		}
		else
		{
			if(nu[i].max_user==1)
				cs21++;
			else if(nu[i].max_user==2)
				cs22++;
			else if(nu[i].max_user==3)
				cs23++;
			else if(nu[i].max_user==4)
				cs24++;
		}
	}
	cout<<"The most used section used by age group below 20 is section "<<find_max(cs01, cs02, cs03, cs04)<<"\n";
	cout<<"The most used section used by age group between 20 and 40 is section "<<find_max(cs11, cs12, cs13, cs14)<<"\n";
	cout<<"The most used section used by age group above 40 is section "<<find_max(cs21, cs22, cs23, cs24)<<"\n";
}

void beta_gender_analysis(beta_user nu[])
{
	int i, f;
	int cs01, cs02, cs03, cs04;
	int cs11, cs12, cs13, cs14;
	cs01=cs02=cs03=cs04=cs11=cs12=cs13=cs14=0;
	for(i=0;i<10;i++)
	{
		int f=beta_grouping_gender(nu[i]);
		if(f==0)
		{
			if(nu[i].max_user==1)
				cs01++;
			else if(nu[i].max_user==2)
				cs02++;
			else if(nu[i].max_user==3)
				cs03++;
			else if(nu[i].max_user==4)
				cs04++;
		}
		else
		{
			if(nu[i].max_user==1)
				cs11++;
			else if(nu[i].max_user==2)
				cs12++;
			else if(nu[i].max_user==3)
				cs13++;
			else if(nu[i].max_user==4)
				cs14++;
		}
	}
	cout<<"The most used section used by females is section "<<find_max(cs01, cs02, cs03, cs04)<<"\n";
	cout<<"The most used section used by males is section "<<find_max(cs11, cs12, cs13, cs14)<<"\n";
}

void display_data(normal_user nu[])
{
	for(int i=0;i<n1;i++)
	{
		nu[i].disinfo(0);
		nu[i].disusage(0.0);
	}
}

void display_with_max(normal_user nu[])
{
	for(int i=0;i<n1;i++)
	{
		nu[i].disinfo(0);
		nu[i].disusage(0.0);
		nu[i].display();
	}
}

void full_analysis(normal_user nu[])
{
	cout<<"\nAnalysis as per Age:\n";
	age_analysis(nu);
	cout<<"\nDisplay Analysis as per Gender";
	gender_analysis(nu);
	cout<<"\nDisplay Analysis as per City:\n";
	city_analysis(nu);
}

void display_data(beta_user bu[])
{
	for(int i=0;i<10;i++)
	{
		bu[i].disinfo(0);
		bu[i].disusage(0.0);
	}
}

void display_with_max(beta_user bu[])
{
	for(int i=0;i<10;i++)
	{
		bu[i].disinfo(0);
		bu[i].disusage(0.0);
		bu[i].display();
	}
}

void full_analysis(beta_user bu[])
{
	cout<<"\nAnalysis as per Age:\n";
	beta_age_analysis(bu);
	cout<<"\nDisplay Analysis as per Gender";
	beta_gender_analysis(bu);
}

int main()
{
	normal_user nu[n1];
	int i;
	char f1[100]="userdata.csv";
	for(i=0;i<n1;i++)
	{
		nu[i].readata(i, f1);
		nu[i].analysis();
	}
	beta_user bu[10];
	char f2[100]="betauserdata.csv";
	for(i=0;i<10;i++)
	{
		bu[i].readata(i, f2);
		bu[i].analysis();
	}
	
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
			
			void (*fnptr2)(beta_user []);
			switch(ch)
			{
				case 1: fnptr2=display_data;
						fnptr2(bu);
						break;
				case 2: fnptr2=display_with_max;
						fnptr2(bu);
						break;
				case 3: fnptr2=full_analysis;
						fnptr2(bu);
						break;
			}
		}
		cout<<"\nWhich file do you want to analyse:";
		cout<<"\n1. Normal User Data";
		cout<<"\n1. Beta User Data";
		cout<<"\nAny number more than 3\n";
		cin>>f;
	}
}
