#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        for (int i=0; i<nums.size()-1; ++i) {
            for (int j=i+1; j<nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    
                    return result;
                }
            }
        }
        
        return result;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    int target = 9;

    vector<int> result;
    Solution s;

    result = s.twoSum(nums, target); 

    vector<int>::iterator itr = result.begin();
    for (; itr!=result.end(); ++itr)
        cout << (*itr) << endl;

    return 0;
}
