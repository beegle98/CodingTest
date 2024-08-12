#define N 4
#define MAX 5040

typedef struct {
    int strike;
    int ball;
} Result;

typedef struct {
    int data[4];
}Node;

Node possible[MAX+1]; // 답 가능성이 있는 숫자들
bool possible_check[MAX+1];
int possible_size;

bool visited[10]; // init에 쓰임, 숫자 중복 체크
int save[4]; // init에 쓰임, dfs 돌면서 들어갈때마다 숫자 하나씩 저장해둠
Result res; // query 결과

// API
extern Result query(int guess[]);

// possible 배열에 중복 안되게 0123 ~ 9876 채우기, possible_check true로 초기화
void init_dfs(int index){
    if(index==N){
        Node num;
        for(int i=0;i<N;i++) num.data[i] = save[i];
        possible_check[possible_size]=true;
        possible[possible_size++]=num;
        return;
    }

    for(int i=0;i<10;i++){
        if(visited[i]) continue;
        visited[i]=true;
        save[index]=i;
        init_dfs(index+1);
        visited[i]=false;
    }
}
// 가능한 수 와 예상한 수, 두 숫자를 비교해서 스트라이크, 볼 개수 체크 => 결과가 query 결과인 res랑 같으면 true 리턴, 다르면 false 리턴
bool res_check(int a[],int b[]){

    int strike=0, ball = 0;

    int ch[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<N;i++) ch[a[i]]=1;
	for (int i=0;i<N;i++){
        if (a[i] == b[i]) strike++;
		else if (ch[b[i]] == 1) ball++;
    }

    if(res.strike == strike && res.ball == ball) return true;
    else return false;

}
// guess와 possible 비교해서 스트라이크, 볼 개수가 같지 않으면 possible 배열에서 삭제
void sol(Node guess_num){

    for(int i=0;i<MAX;i++){
        if(possible_check[i] && !res_check(possible[i].data, guess_num.data)){
            possible_check[i]=false;
            possible_size--;
        }
    }
    
}

int front(int index){ // 가능한 수 중 가장 앞에 있는 수의 index 가져옴
    for(int i=index;i<MAX;i++){
        if(possible_check[i]) return i;
    }
}

void doUserImplementation(int guess[]) { // 배열 주소 받아 사용
    
    possible_size=0;
    init_dfs(0); // possible 0123 ~ 9876 초기화

    int idx = 0;
    while(true){

        idx = front(idx);
        Node tmp = possible[idx]; // 예상한 수 (가능한 배열 중 아무거나 해도 큰 상관 없어보여 첫번째꺼 가져옴)

        res = query(tmp.data);
        
        if(res.strike==N){//예상한 수가 운좋게 4스트라이크 => 바로 종료
            for(int i=0;i<N;i++) guess[i]=tmp.data[i];
            break;                
        }

        sol(tmp);

        if(possible_size==1){// 가능한 수가 1개 남음 => 종료
            idx = front(idx);
            for(int i=0;i<N;i++) guess[i]=possible[idx].data[i];
            break;
        }
    }

}