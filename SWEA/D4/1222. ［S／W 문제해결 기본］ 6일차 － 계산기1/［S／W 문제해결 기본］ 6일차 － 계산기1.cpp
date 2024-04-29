#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

stack<char> op;
stack<int> num;


int priority(char c){
    if (c == '+') return 1;
    else if (c == '*') return 2;
    return 0; 
}

int main(){
    FASTIO
 
    int ans,T=10;
    for(int t=1;t<=T;t++){
        
        int n; cin >> n;
        string str; cin >> str;
        string postfix;
        for(int i=0;i<str.size();i++){
            if(str[i]>='0' && str[i]<='9'){
                postfix += str[i];
            }
            else if(op.empty() || str[i]=='('){
                op.push(str[i]);
            }
            else if(str[i]==')'){
                while(op.top() != '('){
                    postfix += op.top();
                    op.pop();
                }
                op.pop(); // '(' 삭제
            }
            else if(priority(op.top()) < priority(str[i])){
                op.push(str[i]);
            }
            else{
                while(!op.empty() && priority(op.top()) >= priority(str[i])){
                    postfix += op.top();
                    op.pop();
                }
                op.push(str[i]);
            }
        }
        while(!op.empty()){
            postfix += op.top();
            op.pop();
        }
        ans=0;
        for(int i=0;i<postfix.size();i++){
            char c=postfix[i];
            if(c>='0' && c<='9'){
                num.push(c-'0');
            }
            else{
                if(c=='+'){
                    int a,b;
                    a=num.top(); num.pop();
                    b=num.top(); num.pop();
                    num.push(a+b);
                }
                else if(c=='*'){
                    int a,b;
                    a=num.top(); num.pop();
                    b=num.top(); num.pop();
                    num.push(a*b);
                }
            }
        }
        ans = num.top();
        num.pop();
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}