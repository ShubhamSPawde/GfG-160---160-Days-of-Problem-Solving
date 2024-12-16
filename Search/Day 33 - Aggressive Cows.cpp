/* https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/aggressive-cows

You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[2] and
the third cow can be placed at stalls[3].
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.

Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.

Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways. */

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
	bool check(vector<int> &s, int k, int d) {
		int n = 1;
		int p = s[0];
		for (int i = 1; i < s.size(); i++) {
			if (s[i] - p >= d) {
				p = s[i];
				n++;
			}
		}
		return (n >= k);
	}
	int aggressiveCows(vector<int> &s, int k) {
		sort(s.begin(), s.end());
		int result = 0;
		int l = 1;
		int h = s.back() - s[0];
		while (l <= h) {
			int m = l + (h - l) / 2;
			if (check(s, k, m)) {
				result = m;
				l = m + 1;
			} else {
				h = m - 1;
			}
		}
		return r;
	}
};

//{ Driver Code Starts.

int main() {
	int test_case;
	cin >> test_case;
	cin.ignore();
	while (test_case--) {

		int k;
		vector<int> arr;
		string input;
		getline(cin, input);
		stringstream ss(input);
		int number;
		while (ss >> number) {
			arr.push_back(number);
		}
		string in;
		getline(cin, in);
		stringstream sss(in);
		int num;
		while (sss >> num) {
			k = num;
		}
		Solution ob;
		int ans = ob.aggressiveCows(arr, k);
		cout << ans << endl;
		cout << "~" << endl;
	}
	return 0;
}

// } Driver Code Ends