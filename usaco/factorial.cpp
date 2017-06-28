/*
ID: christi58
PROG: fact4
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ofstream fout ("fact4.out");
  ifstream fin ("fact4.in");
  int n;
  fin >> n;
  int rightmost = 1;
  for(int i = 2;i<=n;i++)
  {
    rightmost *= i;
    rightmost %= 100000;
    while(rightmost%10 == 0) rightmost/=10;
  }
  fout << rightmost%10 << endl;
}
