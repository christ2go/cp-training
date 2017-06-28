/*
ID: christi58
PROG: stamps
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void)
{
  ofstream fout ("stamps.out");
  ifstream fin ("stamps.in");

  int n,k; fin >> k >> n;

vector<int> possible(2396089);
set<int> ps;
for(int i = 0;i<n;i++)
{
  int t; fin >> t;
  ps.insert(t);
  possible[t] = 1; // Possible with 1 coin
}
for(int i = 1;i<2396089;i++)
{
  if(possible[i] == 0 || possible[i] > k)
  {
    fout << i-1 << endl;
    return 0;
  }
  for(int j:ps)
  {
    if(possible[i+j] != 0)
      possible[i+j] = min(possible[i+j],possible[i]+1);
    else
      possible[i+j] = possible[i]+1;
  }
}
}
