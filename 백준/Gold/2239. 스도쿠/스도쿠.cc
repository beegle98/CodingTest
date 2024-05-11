#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);

char ans[10][10],s[10][10];
int key=0,ch1[10][10],ch2[10][10],ch3[10][10];

void f(int x,int y){
	if(x==9 && y==0){
		key=1;
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++) ans[i][j]=s[i][j];
			
		return;
	}
	else if(s[x][y]=='0'){
		for(int i=1;i<=9;i++){
			if(key) return;
			if(!ch1[x][i] && !ch2[y][i] && !ch3[(x/3)*3+y/3][i]){
				s[x][y]='0'+i;
				ch1[x][i]=1;
				ch2[y][i]=1;
				ch3[(x/3)*3+y/3][i]=1;
				f(x+(y+1)/9,(y+1)%9);
				s[x][y]='0';
				ch1[x][i]=0;
				ch2[y][i]=0;
				ch3[(x/3)*3+y/3][i]=0;
			}
		}
	}
	else f(x+(y+1)/9,(y+1)%9);
}

int main(){
    FASTIO
    for(int i=0;i<9;i++){
		cin >> s[i];
		for(int j=0;j<9;j++){
			int x = s[i][j]-'0';
			ch1[i][x]=1;
			ch2[j][x]=1;
			ch3[(i/3)*3+j/3][x]=1;
		}
	}
	f(0,0);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout << ans[i][j];
		}
		cout << '\n';
	}
    return 0;
}