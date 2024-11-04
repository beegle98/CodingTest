#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];
	int* D = new int[N];
	vector<int> v1;
	vector<int> v2;
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			v1.push_back(A[i] + B[j]);
			v2.push_back(C[i] + D[j]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int start = 0;
	int end = v2.size() - 1;
	while (start < v1.size() && end>=0)
	{
		while (end >= 0 && v1[start] + v2[end] > 0)
		{
			end--;
		}
		if (end >= 0 && v1[start] + v2[end] == 0)
		{
			long long aCount = 1;
			long long bCount = 1;
			while (start < v1.size())
			{
				start++;
				if (start< v1.size() && v1[start] == v1[start - 1])
				{
					aCount++;
				}
				else
				{
					start--;
					break;
				}
			}
			while (end >= 0)
			{
				end--;
				if (end>=0 && v2[end] == v2[end + 1])
				{
					bCount++;
				}
				else
				{
					break;
				}
			}
			answer += aCount * bCount;
		}
		start++;
	}
	cout << answer << "\n";
	return 0;
}