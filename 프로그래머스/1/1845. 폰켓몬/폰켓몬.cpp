#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    unordered_set<int> hash;
    for(int i=0;i<n;i++){
        hash.insert(nums[i]);
    }
    int size = hash.size();
    answer = min(n/2,size);
    return answer;
}