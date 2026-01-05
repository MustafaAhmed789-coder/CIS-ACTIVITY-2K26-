#include <bits/stdc++.h>
using namespace std;

int countLessEqual(vector<vector<int>>& mat, int mid){
    int n = mat.size(), i = n-1, j = 0, cnt = 0;
    while(i >= 0 && j < n){
        if(mat[i][j] <= mid){
            cnt += i+1;
            j++;
        } else i--;
    }
    return cnt;
}

int kthSmallest(vector<vector<int>>& matrix, int k){
    int n = matrix.size();
    int low = matrix[0][0], high = matrix[n-1][n-1];
    while(low < high){
        int mid = low + (high - low)/2;
        if(countLessEqual(matrix, mid) < k) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main(){
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 8;
    cout << kthSmallest(matrix, k) << endl;
    return 0;
}
