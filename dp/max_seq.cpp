#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

//test case:
//  input: 1324252379
//  output: 124579
//
//  input: 158234
//  output: 1234

string max_seq(string s) {
	int length[1000];
	int num[1000];

	memset(&length, 1000*sizeof(int), 0);
	memset(&num, 1000*sizeof(int), 0);

	for (int i=0; i<s.length(); ++i) {

		int data = s[i] - '0';

		for (int j=0; j<=i; ++j) {

			if (num[j] < data) {

				if (length[i] < length[j]+1) {

					length[i] = length[j] + 1;
					num[i] = data;
				}
			}
			else if (num[j] > data) {

				if (length[j] > length[j]+1) {

					length[i] = length[j];
					num[i] = num[j];
				}
			}
		}
	}

	for (int i=0; i<s.length(); ++i) {
		cout << i << ": " << num[i] << ", " << length[i] << endl;
	}

	return "";
}

int main() {

	string s = "1324252379";
	//string s = "158234";
	cout << "input: " << s << endl;

    string ret = max_seq(s);

	cout << "ret: " << ret << endl;

	return 0;
}
