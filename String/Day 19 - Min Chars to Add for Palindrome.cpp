/* https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/minimum-characters-to-be-added-at-front-to-make-string-palindrome

Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc" */


//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        int len = s.length();
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        
        s = s + "$" + revStr;
        
        vector<int> lpsArray = make_lps(s);
        
        return (len - lpsArray.back());
    }
    
    private:
    vector<int> make_lps(string &pattern) {
        int patternLength = pattern.length();
        vector<int> lpsArr(patternLength);
    
        lpsArr[0] = 0;
        int prefixLen = 0;
    
        int i = 1;
        while (i < patternLength) {
    
            if (pattern[i] == pattern[prefixLen]) {
                prefixLen++;
                lpsArr[i] = prefixLen;
                i++;
            } else {
                if (prefixLen != 0) {
                    prefixLen = lpsArr[prefixLen - 1];
                } else {
                    lpsArr[i] = 0;
                    i++;
                }
            }
        }
        return lpsArr;
    }

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends