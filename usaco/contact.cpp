/*
ID: christi58
PROG: contact
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct CountingTrie
{
  bool ishead;
  int count;
  CountingTrie* left;
  CountingTrie* right;
  CountingTrie(bool ishead)
  {
    this->ishead = ishead;
    this->count = 0;
    this->left = NULL;
    this->right = NULL;
  }
  void initleft()
  {
    if(this->left == NULL)
    {
      this->left = new CountingTrie(false);
    }
  }
  void initright()
  {
    if(this->right == NULL)
    {
      this->right = new CountingTrie(false);
    }
  }
  void insert(string& st,int a, int b,int i = -1)
  {
    if(i >= 0)
    {
      // Maybe increase count
      if((i+1) >= a && (i+1) <= b)
        count++;
    }
    if((i+1) == st.size())
      return;
    if(st[i+1] == '0')
    {
      if(this->left == NULL)
      {
        left = new CountingTrie(false);
      }
      left->insert(st,a,b,i+1);
    }
    if(st[i+1] == '1'){
      if(right == NULL)
      {
        right = new CountingTrie(false);
      }

      right->insert(st,a,b,i+1);
    }
  }

  void rundown(vector< pair< int, string > >& vvec, string a)
  {
    if(count != 0)
    {
      vvec.push_back(make_pair(count,a));
    }
    if(left != NULL)
    {
      left->rundown(vvec,a+"0");
    }
    if(right != NULL)
    {
      right->rundown(vvec,a+"1");
    }
  }
};
int main() {
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
    int a, b, n; fin >> a >> b >> n;
    string s;
    string r;
    while(getline(fin,r))
    {
        s += r;
    }
    CountingTrie t = new CountingTrie(true);
    for(int i = 0;i<=s.size()-(a);i++)
    {
      string insert = s.substr(i,min(b,(int)s.size()-i));
      t.insert(insert,a,b);
    }
    vector< pair<int, string> > arr;
    t.rundown(arr,"");
    sort(arr.begin(),arr.end(),[ ]( pair<int, string>& l,  pair<int, string>& r){
      if(l.first == r.first)
      {
        if(l.second.size() == r.second.size())
        {
          return l.second < r.second;
        }
        return l.second.size() < r.second.size();
      }
      return l.first > r.first;
    });
    int printed = 1;
    int old = arr[0].first;
    fout << old << endl;
    int lc = 0;
    for(auto& p:arr)
    {
      if(p.first != old)
      {
        old = p.first;
        lc = 0;
        printed++;
        if(printed > n)
        {
          fout << endl;
          return 0;

        }
          fout << endl << old << endl;

      }else if(lc != 0 && lc != 6){
        fout << " ";
      }
      if(lc == 6)
      {
        fout << endl;
        lc = 0;
      }
      fout << p.second;
      lc++;
    }
    fout << endl;
    return 0;
}
