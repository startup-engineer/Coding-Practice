#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b)
{
	vector<int>::iterator it_a = a.begin();
	vector<int>::iterator it_b = b.begin();

	vector<int> result;

	while(it_a != a.end() && it_b != b.end()) {
		if(*it_a < *it_b){
			result.push_back(*it_a);
			it_a++;
		}else{
			result.push_back(*it_b);
			it_b++;
		}

		if(it_a == a.end() && it_b != b.end())
			while(it_b != b.end())
				result.push_back(*(it_b++));
		else if(it_b == b.end() && it_a != a.end())
			while(it_a != a.end())
				result.push_back(*(it_a++));
	}

	// for(int i : a)
	// 	cout << i << " ";
	// cout << endl;
	
	return result;
}

vector<int> merge_sort(vector<int> a)
{
	if(a.size() == 1)
		return a;

	vector<int>::iterator beginning = a.begin();
	vector<int>::iterator mid = a.begin() + a.size() / 2;
	vector<int>::iterator end = a.end();

	vector<int> first(beginning, mid);
	vector<int> second(mid, end);

	// for(int i : first)
	// 	cout << i << " ";
	// cout << " ";

	// for(int i : second)
	// 	cout << i << " ";
	// cout << endl;

	vector<int> f = merge_sort(first);
	vector<int> s = merge_sort(second);

	for(int i : f)
		cout << i << " ";
	cout << " ";

	for(int i : s)
		cout << i << " ";
	cout << endl;

	return merge(f, s);
}

int main()
{
	string input = "9 6 3 5 1 2 0 7";
	istringstream iss(input);

	int x;
	vector<int> a;
	while(iss >> x)
		a.push_back(x) ;

	vector<int> array(100);
	for(int i = 0; i < 100; i++)
		array[i] = rand() % 100;

	for(int i : array)
		cout << i << " ";
	cout << endl << endl;

	for(int i : merge_sort(array))
		cout << i << " ";
	cout << endl;

	return 0;
}

// 9 6 3 5 1 2 0 7
// 9 6 3 5  1 2 0 7
// 9 6  3 5  1 2  0 7
// 9  6  3  5  1  2  0  7
// 6 9  3 5  1 2  0 7
// 3 5 6 9  0 1 2 7
// 0 1 2 3 5 6 7 9