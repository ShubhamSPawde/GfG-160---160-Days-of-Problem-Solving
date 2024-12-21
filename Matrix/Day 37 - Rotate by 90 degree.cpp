/* https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/rotate-by-90-degree-1587115621

Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

Examples:

Input: mat[][] = [[1, 2, 3],
                [4, 5, 6]
                [7, 8, 9]]
Output: Rotated Matrix:
[3, 6, 9]
[2, 5, 8]
[1, 4, 7]

Input: mat[][] = [[1, 2],
                [3, 4]]
Output: Rotated Matrix:
[2, 4]
[1, 3] */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        for(int i = 0; i<mat.size(); i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        for(int i = 0; i<mat.size(); i++){
            for(int j = i + 1; j<mat.size(); j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends

