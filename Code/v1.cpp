#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

string city[100];
string country[100];
string pop[100];
string popd[100];
int n=0;

int extract()
{
	ifstream in;
	in.open("worldcities.csv");
	if (in.is_open()) 
	{
		while (!in.eof()) 
		{
    		getline(in, city[n], ',');
    		getline(in, country[n], ',');
    		getline(in, pop[n], ',');
    		getline(in, popd[n],'\n');
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

void display()
{
	cout << "File has been opened" << endl;
	for(int i=0;i<n;i++)
	{
		cout << "City: " << city[i] << "\n";
    	cout << "Country: " << country[i] << "\n";
    	cout << "Population: " << pop[i] << "\n";
    	cout << "Population Density: " << popd[i] << " people per square kilometer" << "\n";		
		cout << "-------------------" << '\n';
	}
}

int main()
{
	int c=extract();
	if(c==0)
	{
		display();
	}
	else
	{
		cout << "NO FILE HAS BEEN OPENED" << endl;
	}
	getch();
}
