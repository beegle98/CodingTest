#include <stdio.h>
int n, k, h_size = 0,cnt=1;
long long int sum = 0;
int stack[110000], len = 0;
int s[110000][3];// 회원번호, 시간, 계산대 번호
int h[110000];
int compare(int a, int b){
	if ((s[a][1] == s[b][1] && s[a][2] < s[b][2]) || s[a][1] > s[b][1]){//뒤가 작으면
		return 1;
	}
	else return 0;
}
void push_heap(int tmp){
	int i=++h_size;
	while (i>1){
		if (compare(h[i/2],tmp)){
			h[i] = h[i / 2];
			i /= 2;
		}
		else break;
	}
	h[i] = tmp;
}
int pop_heap(){
	int parent=1, child=2, ret = h[1];
	int tmp = h[h_size];
	h[h_size--] = 0;
	while (child<=h_size){
		if (child+1<=h_size && compare(h[child],h[child+1])){
			child++;
		}
		if (compare(tmp, h[child])){
			h[parent] = h[child];
			parent = child;
			child *= 2;
		}
		else break;
	}
	h[parent] = tmp;
	return ret;
}
void push(int tmp){
	stack[++len] = tmp;
}
int pop(){
	if (len == 0) return 0;
	else return stack[len--];
}
int main(){

	//input
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d %d", &s[i][0], &s[i][1]);
	}
	
	//init: heap에 k개 만큼 넣기
	if (n < k) k = n;
	for (int i = 1; i <= k; i++){
		s[i][2] = i;
		push_heap(i);
	}
	// main: heap에서 stack으로 빼고 그 만큼 heap에 넣어주기
	int tmp;
	//printf("%d\n", k);
	//for (int j = 1; j <= k; j++) printf("%d:%d  ", h[j], s[h[j]][1]);
	//printf("\n\n");
	for (int i = k + 1; i <= n;){
		while (h_size>0){
			tmp = pop_heap();
			//printf("%d ", tmp);
			sum += (long long int)s[tmp][0] * cnt;
			cnt++;
			push(tmp);
			if (s[tmp][1] != s[h[1]][1]) break;
		}
		while (len>0 && i<=n){
			tmp = pop();
			s[i][1] += s[tmp][1];
			s[i][2] = s[tmp][2];
			push_heap(i++);
		}
		//printf("%d\n", i);
		//for (int j = 1; j <= k; j++) printf("%d:%d  ", h[j], s[h[j]][1]);
		//printf("\n\n");
	}
	//end: 힙에 남은거 빼기
	while (h_size>0){
		tmp=pop_heap();
		//printf("%d ", tmp);
		sum += (long long int)s[tmp][0] * cnt;
		cnt++;
	}
	printf("%lld", sum);
	return 0;
}