/* https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/inversion-of-array-1587115620

Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:
 
Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count. */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int cnt = mergeSort(arr, 0, arr.size() - 1);
        return cnt;
    }

  private:
   
    int merge(vector<int> &arr, int s, int e) {
        int mid = (s + e) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        vector<int> first(len1), second(len2);

       
        for (int i = 0; i < len1; i++) {
            first[i] = arr[s + i];
        }

        for (int i = 0; i < len2; i++) {
            second[i] = arr[mid + 1 + i];
        }

        int index1 = 0, index2 = 0, mainArrayIndex = s;
        int inversions = 0;

        
        while (index1 < len1 && index2 < len2) {
            if (first[index1] <= second[index2]) {
                arr[mainArrayIndex++] = first[index1++];
            } else {
                arr[mainArrayIndex++] = second[index2++];
                inversions += (len1 - index1); 
            }
        }

        
        while (index1 < len1) {
            arr[mainArrayIndex++] = first[index1++];
        }
        while (index2 < len2) {
            arr[mainArrayIndex++] = second[index2++];
        }

        return inversions;
    }

    // Merge Sort function
    int mergeSort(vector<int> &arr, int s, int e) {
        int res = 0;
        if (s < e) {
            int mid = (s + e) / 2;

            res += mergeSort(arr, s, mid);
            
            res += mergeSort(arr, mid + 1, e);

           
            res += merge(arr, s, e);
        }
        return res;
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends