#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		int temp = x;
		int y = 0;
		int m = 0;
		int n = 0;

		if (x < 0)
			return false;

		do {
			m = temp % 10;
			temp = temp / 10;

			y = y * 10 + m;
		} while(temp > 0);


		if (x == y)
			return true;
		else
			return false;
    }
};

int main() {
	Solution solution;
	string ret_str = "true";
	int x;
	bool ret;

	x = 1234321;
	
	ret = solution.isPalindrome(x);

	ret ? ret_str = "True" : ret_str = "False";

	cout << "input:" << x << endl;
	cout << "output:" << ret_str << endl << endl;

	x = 12345321;

	ret = solution.isPalindrome(x);

	ret ? ret_str = "True" : ret_str = "False";

	cout << "input:" << x << endl;
	cout << "output:" << ret_str << endl;


	return 0;
}
