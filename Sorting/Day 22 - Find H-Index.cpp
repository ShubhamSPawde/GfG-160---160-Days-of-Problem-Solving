/* https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/find-h-index--165609

Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

Examples:

Input: citations[] = [3, 0, 5, 3, 0]
Output: 3
Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.

Input: citations[] = [5, 1, 2, 4, 1]
Output: 2
Explanation: There are 3 papers (with citation counts of 5, 2, and 4) that have 2 or more citations. However, the H-Index cannot be 3 because there aren't 3 papers with 3 or more citations. */


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {

        vector<int> arr = countingsort_algorithm(citations);

        int idx = 0;
        int n = arr.size();
        while (idx < n && arr[idx] > idx) {
            idx++;
        }
        return idx;
    }

    vector<int> countingsort_algorithm(vector<int>& citations) {
        vector<int> arr(citations.size(), 0);
        int maxi = INT_MIN;

        for (int i = 0; i < citations.size(); i++)
            maxi = max(maxi, citations[i]);

        vector<int> cnt_pos(maxi + 1, 0);
        for (int i = 0; i < citations.size(); i++) {
            cnt_pos[citations[i]]++;
        }

        int index = 0;
        for (int i = maxi; i >= 0; i--) {
            while (cnt_pos[i] > 0) {
                arr[index++] = i;
                cnt_pos[i]--;
            }
        }
        return arr;
    }

};


//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends