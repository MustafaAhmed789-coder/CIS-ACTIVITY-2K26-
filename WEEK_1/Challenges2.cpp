#include <bits/stdc++.h>
using namespace std;

string passwordRecovery(string log, string pattern) {
    unordered_map<char,int> need,window;
    for(char c:pattern) need[c]++;
    int have=0,required=need.size(),left=0,minLen=INT_MAX,start=0;
    for(int right=0;right<log.size();right++){
        char c=log[right];
        window[c]++;
        if(need.count(c)&&window[c]==need[c]) have++;
        while(have==required){
            if(right-left+1<minLen){minLen=right-left+1;start=left;}
            char lc=log[left]; window[lc]--; 
            if(need.count(lc)&&window[lc]<need[lc]) have--;
            left++;
        }
    }
    return minLen==INT_MAX?"":log.substr(start,minLen);
}

int main(){
    cout<<passwordRecovery("ADOBECODEBANC","ABC")<<endl;
    cout<<passwordRecovery("a","a")<<endl;
    cout<<passwordRecovery("a","aa")<<endl;
}
