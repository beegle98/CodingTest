#include <bits/stdc++.h>

using namespace std;

int dp[51][1001];

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    
    int n = onboard.size();
    int answer = 2e9;
    temperature+=10;t1+=10;t2+=10;
    memset(dp,0x7f,sizeof(dp));
    dp[temperature][0]=0;
    for(int i=0;i<n-1;i++){
        for(int t=0;t<=50;t++){
            int nt=t; 
            if(temperature<t)nt--;else if(temperature>t)nt++;
            if(!(onboard[i+1]&&(nt<t1||t2<nt)))
                dp[nt][i+1]=min(dp[nt][i+1],dp[t][i]);
            for(int d=-1;d<=1;d++){
                nt=t+d;if(nt<0||nt>50)continue;
                int add=!d?b:a;
                if(!(onboard[i+1]&&(nt<t1||t2<nt)))
                    dp[nt][i+1]=min(dp[nt][i+1],dp[t][i]+add);
            }
        }
    }
    for(int t=0;t<=50;t++)answer=min(answer,dp[t][n-1]);
    return answer;
}