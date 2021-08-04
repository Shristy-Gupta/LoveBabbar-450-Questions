// Calculate square of a number without using *, / and pow()
#include <iostream>
using namespace std;

int square(int n)
{
    if(n==0){
        return 0;
    }
    if(n<0){
        n=-n;
    }
    int x=n>>1;//x=n/2
    int y=square(x);
    if(n%2==0){
        return y<<2;
    }
    else{
       return (y<<2)+(x<<2)+1;
    }
}

int main() {
    // Function calls
    for (int n = 1; n <= 5; n++)
        cout << "n = " << n << ", n^2 = " << square(n)
             << endl;
    return 0;
}
