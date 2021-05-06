/*Method 1 (Use Sorting)
Approach: 

Sort the input array.
Traverse the array and check for missing and repeating.

Method 2 (Use count array)
Approach: 

Create a temp array temp[] of size n with all initial values as 0.
Traverse the input array arr[], and do following for each arr[i] 
if(temp[arr[i]] == 0) temp[arr[i]] = 1;
if(temp[arr[i]] == 1) output “arr[i]” //repeating
Traverse temp[] and output the array element having value as 0 (This is the missing element)

--this method*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool>seen(nums.size() + 1);
        int twice;
        for (auto& val : nums) {
            if (seen[val])
                twice = val;
            else
                seen[val] = true;
        }
        for (int i = 1; i < seen.size(); ++i) {
            if (!seen[i]) {
                return vector<int>{twice, i};
            }
        }
        return vector<int>();
    }
};
/*
Method 4 (Make two equations)
Approach:
Let x be the missing and y be the repeating element.
Get the sum of all numbers using formula S = n(n+1)/2 – x + y
Get product of all numbers using formula P = 1*2*3*…*n * y / x
The above two steps give us two equations, we can solve the equations and get the values of x and y

*/

/*
// C++ program to find the repeating
// and missing elements using Maps
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int arr[] = { 4, 3, 6, 2, 1, 1 };
	int n = 6;
	unordered_map<int, bool> numberMap;
	for(int i : arr)
	{
		if (numberMap.find(i) ==
			numberMap.end())
		{
			numberMap[i] = true;
		}
		else
		{
			cout << "Repeating = " << i;
		}
	}
	cout << endl;	
	for(int i = 1; i <= n; i++)
	{
		if (numberMap.find(i) ==
			numberMap.end())
		{
			cout << "Missing = " << i;
		}
	}
	return 0;
}
*/

