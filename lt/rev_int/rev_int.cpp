#include <string>
#include <limits.h>
#include <iostream>

using namespace std;
class Solution {
public:
    int reverse(int x) {
		long temp = x;
		int ret = 0;
		if (x<0)
			temp = -1 * x;

		while (temp > 0) {
			//long ret_temp = ret;
			if (ret > INT_MAX/10)
				return 0;

			ret *= 10;

			ret += temp % 10;
			temp = temp / 10;
		}

       	if (x < 0)
			ret = -1 * ret;

		return ret; 
    }
};

int main() {
	int ret;
	//int x = 1234;
	int x = 1534236469;
	int y = -1234;
	Solution solution;

	ret = solution.reverse(x);
	cout << "input: " << x << endl;
	cout << "output: " << ret << endl;

	cout << endl;

	ret = solution.reverse(y);
	cout << "input: " << y << endl;
	cout << "output: " << ret << endl;
}
