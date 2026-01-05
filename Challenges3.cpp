#include <bits/stdc++.h>
using namespace std;

double balancedMedian(vector<int>& A, vector<int>& B){
    int m=A.size(), n=B.size();
    int total=m+n;
    int i=0,j=0,count=0;
    int median1=0, median2=0;
    
    for(int k=0;k<=total/2;k++){
        median1=median2;
        if(i<m && (j>=n || A[i]<=B[j])) median2=A[i++];
        else median2=B[j++];
    }
    
    if(total%2==0) return (median1+median2)/2.0;
    return median2;
}

int main(){
    vector<int> A1={1,3}, B1={2};
    cout<<balancedMedian(A1,B1)<<endl; 
    vector<int> A2={1,2}, B2={3,4};
    cout<<balancedMedian(A2,B2)<<endl; 
    vector<int> A3={1,5,7}, B3={2,3,6,8};
    cout<<balancedMedian(A3,B3)<<endl; 
}
