#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string, int> frequencies;

	frequencies["Hello"] = 1;

	map<string, int>::iterator it = frequencies.find("Hello");

	cout << it->second << endl;

	return 0;
}