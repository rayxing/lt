#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
		int size = str.size();
		int limit = INT_MAX / 10;
		
		int data = 0;
		int sign = 0;
		bool indata = false;
		
		for (int i=0; i<size; ++i) {

			if (str[i] == '-')
				if (indata==false && sign==0) {
					sign = -1; 
					indata = true;
					continue;
				}
				else
					return 0;

			if (str[i] == '+')
				if (indata==false && sign==0) {
					indata = true;
					sign = 1; 
					continue;
				}
				else 
					return 0; 

			if (str[i]>='0' && str[i]<='9') {
				if (sign!=-1 && (limit<data || INT_MAX-str[i]+'0'<=data*10)) {
					return INT_MAX;
				}
				
				if (sign==-1 && (limit<data || INT_MIN+str[i]-'0'>=-1*data*10)) {
					return INT_MIN;
				}

				indata = true;

				data = data*10 + str[i] - '0';
			}
			else if (str[i]==' ' && indata==false) {
				continue;
			} 
			else if (str[i]=='+' && indata==false) {
				continue;
			} 
			else  //str[i]<'0' && str[i]>'9' {
				break;
		}	

		if (sign == -1)
			data = -1 * data;

		return data; 
    }
};

int main() {
	Solution solution;
	//string str = " -  123456789.dfdf112  ";
	//string str = " -12345ia6789.dfdf112  ";
	//string str = "2147483648";
	//string str = "- 2147483647";
	string str = "      -11919730356x";

	int ret = 0;
	
	ret = solution.myAtoi(str);
	
	cout << "input: " << str << endl;
	cout << "output: " << ret << endl;


	return 0;
}
