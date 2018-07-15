#include <iostream>
#include <vector>

using namespace std;

int steps(int n)
{
	if(n <= 0)
		return 0;
	else if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else if(n == 3)
		return 4;

	vector<int> memo(n + 1);
	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;

	for(int i = 4; i <= n; i++)
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];

	return memo[n];
}

int main()
{
	int n;
	cin >> n;
	cout << steps(n) << endl;
	return 0;
}