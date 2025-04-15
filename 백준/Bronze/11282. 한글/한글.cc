#include <iostream>
#include <string.h>

using namespace std;

string unicodeToUTF8(int unicode) {
	std::string utf8_string;

	utf8_string += (0xE0 | (unicode >> 12));
	utf8_string += (0x80 | ((unicode >> 6) & 0x3F));
	utf8_string += (0x80 | (unicode & 0x3F));

	return utf8_string;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cout << unicodeToUTF8(44032 + n - 1);
	return 0;
}
