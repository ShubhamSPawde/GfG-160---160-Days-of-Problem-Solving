/* https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/spirally-traversing-a-matrix-1587115621

You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.

Examples:

Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation: 

Input: mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]
Explanation: Applying same technique as shown above.

Input: mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]
Output: [32, 44, 27, 23, 62, 50, 28, 54]
Explanation: Applying same technique as shown above, output will be [32, 44, 27, 23, 62, 50, 28, 54]. */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int stcol = 0;
        int strow = 0;
        int endcol = m - 1;
        int endrow = n - 1;
        int cnt = 0;
        int total = n * m;
        vector<int> ans;
        while(cnt < total){
            for(int index = stcol; index <=endcol && cnt < total; index++){
                int ele = matrix[strow][index];
                ans.push_back(ele);
                cnt++;
            }
            strow++;
            for(int index = strow; index<= endrow && cnt < total; index++){
                int ele = matrix[index][endcol];
                ans.push_back(ele);
                cnt++;
            }
            endcol--;
            for(int index = endcol; index>= stcol && cnt < total; index--){
                int ele = matrix[endrow][index];
                ans.push_back(ele);
                cnt++;
            }
            endrow--;
            for(int index = endrow; index>= strow && cnt < total; index--){
                int ele = matrix[index][stcol];
                ans.push_back(ele);
                cnt++;
            }
            stcol++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends