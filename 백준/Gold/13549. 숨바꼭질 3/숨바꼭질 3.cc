#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 200001


bool visited[MAX];
int cnt[MAX];
int n, k, sum=0;
queue<int> q;
int oper(int x, int k){
	if (k == 0) return x - 1;
	else if (k == 1) return x + 1;
	else if (k == 2) return x * 2;
	else return x;
}
void bfs(){
	
	while (!q.empty()){
		int v = q.front();
		q.pop();
		//printf("%d %d\n", v, cnt[v]);
		if (sum > 0 && cnt[v] >= cnt[k]) return;
		for (int i = 0; i < 2; i++){
			int w = oper(v, i);
			if (w < 0 || w >= MAX || visited[w]==true) continue;
			int a = w;
			while (1){
				if (visited[a] == false){
					q.push(a);
					cnt[a] = cnt[v] + 1;
					visited[a] = true;
				}
				if (a == k) return;
				if (a == 0 || a > k) break;
				a *= 2;
			}
			
		}
	}
}
int main(){
	scanf("%d %d", &n, &k);
	if (k <= n){
		printf("%d", n - k);
		return 0;
	}
	int a = n;
	while (true){
		q.push(a);
		visited[a] = true;
		cnt[a] = 0;
		if (a == k){
			printf("0");
			return 0;
		}
		if (a==0 || a > k) break;
		a *= 2;
	}
	bfs();
	printf("%d", cnt[k]);
	return 0;
}