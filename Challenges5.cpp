#include <bits/stdc++.h>
using namespace std;
bool isValid(const string &s){
    int bal = 0;
    for(char c : s){
        if(c=='(') bal++;
        else if(c==')') {
            if(bal==0) return false;
            bal--;
        }
    }
    return bal==0;
}
vector<string> fixExpression(string expr){
    unordered_set<string> seen;
    queue<string> q;
    vector<string> res;
    q.push(expr);
    bool found=false;

    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            string cur=q.front(); q.pop();
            if(isValid(cur)){
                res.push_back(cur);
                found=true;
            }
            if(found) continue;
            for(int j=0;j<cur.size();j++){
                if(cur[j]!='(' && cur[j]!=')') continue;
                string next=cur.substr(0,j)+cur.substr(j+1);
                if(!seen.count(next)){
                    seen.insert(next);
                    q.push(next);}}}
        if(found) break;}
    return res;
}
int main(){
vector<string> r1=fixExpression("()())()");
    for(auto &s:r1) cout<<s<<" "; cout<<endl;
vector<string> r2=fixExpression("(a)())()");
    for(auto &s:r2) cout<<s<<" "; cout<<endl;
vector<string> r3=fixExpression(")(");
    for(auto &s:r3) cout<<s<<" "; cout<<endl;
vector<string> r4=fixExpression("abc");
    for(auto &s:r4) cout<<s<<" "; cout<<endl;
vector<string> r5=fixExpression("(((");
    for(auto &s:r5) cout<<s<<" "; cout<<endl;
}
