#include <iostream>
using namespace std;

int main(void)
{
  while(true)
  {
    int i;
    cin >> i;
    if(i == 42)
      return 0;
    cout << i << endl;
  }
}
