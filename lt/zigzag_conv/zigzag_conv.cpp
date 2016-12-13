#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.size();
		
		char ** rows = new char *[numRows];
		int * idx = new int[numRows];

		memset(idx, sizeof(int)*numRows, 0);

		for (int i=0; i<numRows; ++i) {
			rows[i] = new char[len+1];
			memset(rows[i], sizeof(char)*(len+1), 0);
		}

		int col = 0;
		int i=0;
		
		while (i< len) {

			for (int j=0; j<numRows; ++j) {
				if (j % 2 == 1) {
					rows[j][idx[j]] = s[i];
					
					++ idx[j];

					++ i;
					if (i>= len)
						break;
				}
				else {
					if (idx[j] % 2 == 1) {
						rows[j][idx[j]] = ' ';
						idx[j] ++;
					} else {
						rows[j][idx[j]] = s[i];
						idx[j] ++;

						++ i;
						if (i>= len)
							break;
					}
				}
			}
		};

		//char res_str = new char[2*len+1];
		string res = "";
		for (int i=0; i<numRows; ++i) {
			char * p = rows[i];
			//cout << "row : " << i << endl;
			for (int j=0; j<idx[i]; ++j) {
				//cout << p[j] << endl;
				if (p[j] != ' ')
					res.push_back(p[j]);
			}
		}
		

		for (int i=0; i<numRows; ++i) {
			delete[] rows[i];
		}
		delete[] idx;
		delete[] rows;

		return res;	
    }
};

int main() {
	Solution solution;
	string s = "PAYPALISHIRING";
	//string s = "A";
	string res;
	
	res = solution.convert(s, 3);

	cout << "input: " << s << endl;
	cout << "output:"  << res << endl;
	
}
