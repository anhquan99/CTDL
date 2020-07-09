// increaser
#include <iostream>
using namespace std;

int main ()
{
  int *a[5];
//  *a = new int [5];
  int b [5] = {1,2,3,4,5};
  cout << "this\n";
  for(int i = 0; i < 5; i++){
    a[i] = &b[i];
    cout << *a[i] << '\n';
  } 
  
  return 0;
}
