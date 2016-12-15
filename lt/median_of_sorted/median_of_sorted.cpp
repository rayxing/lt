#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double ret = 0;

		int n = nums1.size();
		int m = nums2.size();
		
		int range_n_low = 0;
		int range_n_high = n-1;
		int range_m_low = 0;
		int range_m_high = m-1;
		int temp_n = 0;
		int temp_m = 0;

		do {
			(range_n_high - range_n_low + 1) / 2
			
			if (nums1[range_n_low] > )

		} 
		while (1)
        
		return ret;
    }
};

int main() {
	Solution solution;
	vector<int> nums1;
	vector<int> nums2;

	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(5);

	nums2.push_back(2);
	nums2.push_back(5);
	nums2.push_back(8);
	nums2.push_back(9);

	double ret = solution.findMedianSortedArrays(nums1, nums2);
	cout << "ret: " << ret << endl;

	return 0;
}
