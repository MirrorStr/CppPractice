// C++ Program to evaluate largest of the three numbers
// using nested if else
#include <iostream>
using namespace std;
  
int main()
{
    // declaring three numbers
    int a = 10;
    int b = 2;
    int c = 6;
  
    // outermost if else
    if (a < b) {
        // nested if else
        if (c < b) {
            printf("%d is the greatest", b);
        }
        else {
            printf("%d is the greatest", c);
        }
    }
    else {
        // nested if else
        if (c < a) {
            printf("%d is the greatest", a);
        }
        else {
            printf("%d is the greatest", c);
        }
    }
  
    return 0;
}
