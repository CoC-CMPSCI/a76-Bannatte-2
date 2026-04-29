#include "main.hpp"
int main()
{
	string state[N];
	string gender[N];
	int year[N];
	string name[N];
	int count[N];
	int cnt;
	char starting = 'J';
	string stname = "TX";

	cnt = makeNameRecord(state, gender, year, name, count);
	printoutallrecords(cnt, state, gender, year, name, count);

	cnt = findNames(cnt, state, gender, year, name, count, starting, stname);
}