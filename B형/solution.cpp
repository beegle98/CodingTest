#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define FASTIO cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

struct Player
{
  int Id;
  int Ability;
  bool operator<(const Player &t) const
  {
    if (Ability == t.Ability)
    {
      return Id > t.Id;
    }
    return Ability < t.Ability;
  }
};

multiset<Player> left_heap[10];
multiset<Player> right_heap[10];

int id = 0;

int n, l;

void iterSwap(int index1, auto iter1, int index2, auto iter2)
{
  Player left = *iter1;
  Player right = *iter2;

  left_heap[index1].erase(iter1);
  right_heap[index2].erase(iter2);

  left_heap[index1].insert(right);
  right_heap[index2].insert(left);
}

void iSort(int index)
{
  auto hMax = --left_heap[index].end();  // left_heap의 최댓값
  auto hMin = right_heap[index].begin(); // right_heap의 최솟값
  if (*hMin < *hMax)
    iterSwap(index, hMax, index, hMin);
}

void init(int N, int L, int mAbility[])
{
  for (int i = 0; i < 10; i++)
  {
    left_heap[i].clear();
    right_heap[i].clear();
  }
  id = 0;
  n = N;
  l = L;
  for (int i = 0; i < L; i++)
  {
    for (int j = 0; j < N / L; j++)
    {
      int ab = mAbility[i * (N / L) + j];

      if (left_heap[i].size() == right_heap[i].size())
      {
        left_heap[i].insert({id++, ab});
      }
      else
      {
        right_heap[i].insert({id++, ab});
      }
      if (left_heap[i].empty() || right_heap[i].empty())
        continue;

      iSort(i);
    }
  }
}

int move()
{
  int idSum = 0;
  for (int i = 1; i < l; i++)
  {
    auto MIN = left_heap[i - 1].begin();
    auto MAX = --right_heap[i].end();
    idSum += (*MAX).Id + (*MIN).Id;
    iterSwap(i - 1, MIN, i, MAX);
  }
  for(int i=0;i<l;i++){
    iSort(i);
  }
  return idSum;
}

int trade()
{
  int idSum = 0;
  for (int i = 1; i < l; i++)
  {
    auto MID = --left_heap[i - 1].end();
    auto MAX = --right_heap[i].end();
    idSum += (*MAX).Id + (*MID).Id;
    iterSwap(i - 1, MID, i, MAX);
  }
  for(int i=0;i<l;i++){
    iSort(i);
  }
  return idSum;
}