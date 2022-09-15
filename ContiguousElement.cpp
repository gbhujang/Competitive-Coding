//{ Driver Code Starts
// C++ implementation to check whether the array
// contains a set of contiguous integers
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	// Function to check whether the array contains
	// a set of contiguous integers
	bool areElementsContiguous(int arr[], int n)
	{
		// vector<int> res;
		sort(arr, arr + n);
		int temp = arr[0];
		map<int, int> mp;

		for (int i = 0; i < n; i++) {
			mp[arr[i]];
		}
		for (auto i = mp.begin(); i != mp.end(); i++) {
			if (mp.find(temp) == mp.end()) {
				return 0;
			}
			temp++;
		}


		return 1;
	}
};

//{ Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("outp.in", "w", stdout);

#endif // ONLINE_JUDGE
	int n;
	cin >> n;
	int arr[n + 1];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	Solution ob;
	if (ob.areElementsContiguous(arr, n))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

// } Driver Code Ends