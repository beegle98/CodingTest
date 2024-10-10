#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

struct Node {
	map<string, Node> child;
}root;

void insert(Node &v, vector<string> &arr, int idx) {
	if (idx == arr.size()) return;

	if (!v.child.count(arr[idx])) v.child[arr[idx]] = Node();
	insert(v.child[arr[idx]], arr, idx + 1);
}

void dfs(Node &v, int dep = 0) {
	for (auto i : v.child) {
		for (int j = 0; j < dep; j++) cout << " ";
		cout << i.first << "\n";
		dfs(i.second, dep + 1);
	}
}
vector<string> split(string str, char Delimiter) {
	istringstream iss(str);             // istringstream에 str을 담는다.
	string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

	vector<string> result;

	// istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
	while (getline(iss, buffer, Delimiter)) {
		result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string str; cin >> str;
		vector<string> v = split(str, '\\');

		insert(root, v, 0);
	}
	dfs(root);
}