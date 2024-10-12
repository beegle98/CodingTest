#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Manachers
{
    void make_A(string &text, vector<int> &P)
    {
        int sLen = (int)text.size(), r = 0, c = 0;

        for (int i = 0; i < sLen; i++)
        {
            if (r < i) P[i] = 0;
            else P[i] = min(P[2 * c - i], r - i);

            while (i - P[i] - 1 >= 0 && i + P[i] + 1 < sLen && text[i - P[i] - 1] == text[i + P[i] + 1]) P[i]++;

            if (r < i + P[i])
            {
                r = i + P[i];
                c = i;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Manachers palindrome;
    string s, text = "*";
  
    cin >> s;
    for (auto& c : s) { text += c; text += "*"; }

    vector<int> P(text.size(), 0);
    palindrome.make_A(text, P);

    int answer = -1;
    for (int i = 0; i < text.size(); i++) answer = max(answer, P[i]);
    cout << answer << '\n';

    return 0;
}

