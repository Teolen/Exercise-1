#include <vector>
#include <map>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <stdio.h>
using namespace std;
void func_cout(int a, vector<int>*v, map<int, int>*m);
int main()
{
	alpha:
	srand(time(NULL));
	char r;
	vector<int> v1;
	map <int, int> m1;
	map <int, int>::iterator it, m, end;
	int a, n, k=0;
	
	//1. fill vector and map by random numbers
	for (int i = 0; i < 20; i++)
		v1.push_back(rand() % 9 + 1);
	for (int i = 0; i < 20; i++)
		m1[i] = rand() % 9 + 1;
	
	func_cout(1, &v1, &m1);

	//2. remove a random number of elements from vector and map
	n = 19 - rand() % 15;
	for (int i = 20; i > n; i--)
		m1.erase(i);
	v1.erase(v1.begin() + (19 - rand() % 15), v1.begin() + 20);
	n = m1.size();

	func_cout(2, &v1, &m1);
	
	//3. remove items that are not present in both containers

	m = m1.begin();
	end = m1.end();
	
	while (m != end)
	{
		if (find(v1.begin(), v1.end(), (*m).second) == v1.end())
			m1.erase(m++);
		else
			m++;
	}
	for (int i = 0; i < v1.size(); i++)
	{
		for (it = m1.begin(); it != m1.end(); it++)
		{
			if (v1[i] == (*it).second) k++;
		};
		if (k == 0)
		{
			v1.erase(v1.begin() + i);
			k = 0;
			i--;
		}
		else k = 0;
	};

	func_cout(3,&v1,&m1);

	// for restart
	cout << "print another?(y/n)";
	cin >> r;
	if (r == 'y') { system("cls"); goto alpha; }
	else return 0;
}
void func_cout(int a, vector<int>*v, map<int,int>*m)
{
	cout << "Step "<<a<< endl<<endl;
	for (auto i = (*v).begin(); i != (*v).end(); ++i)
		cout << *i << ' ';
	cout << endl;
	for (auto i = (*m).begin(); i != (*m).end(); ++i)
	{
		//if ((*i).second != 0)
		cout << (*i).first << " : " << (*i).second << endl;
	}
	cout << endl;
}
