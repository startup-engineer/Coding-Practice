#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int highest_below(int n, set<int>& digits)
{
	int current_max = -1;
	for(int i : digits)
		for(int j : digits) 
			if(10*i + j < n && 10*i + j > current_max)
				current_max = 10*i + j;
	return current_max;
}

string latest_time(string in) {
	size_t idx = 0;
	int h = stoi(in, &idx);
	int m = stoi(in.substr(idx + 1));

	if(h > 23 || m > 59)
		return "";

	set<int> digits;
	digits.insert(h%10);
	digits.insert(h/10);
	digits.insert(m%10);
	digits.insert(m/10);

	//check if there is a minute that is lower available
	int highest_minute = highest_below(m, digits);
	if(highest_minute != -1)
	{
		ostringstream str;
		str << h << ":" << highest_minute;
		return str.str();
	} 

	//if not then check if there is a lower hour available and maximize the minute
	int highest_hour = highest_below(h, digits);
	if(highest_hour != -1)
	{
		ostringstream ostr;
		ostr << highest_hour << ':' << highest_below(60, digits);
		return ostr.str();
	}

	//if not then return the same time
	return in;
}

int main() {
	cout << latest_time("11:20") << endl;
	return 0;
}