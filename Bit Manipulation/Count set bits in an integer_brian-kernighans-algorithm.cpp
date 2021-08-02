#include <iostream>
#include <bitset>
using namespace std;
 
// Function to count the total number of set bits in `n`
int countSetBits(int n)
{
    // `count` stores the total bits set in `n`
    int count = 0;
 
    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }
 
    return count;
}
int setBits(int N) {
        //Brian Kernighan's Algorithm
       unsigned int count1=0;
       while(N){
          int rsbm= N & -N; 
          N = N-rsbm;
          count1++;
       }
       return count1;
    }
 
int main()
{
    int n = -1;
 
    cout << n << " in binary is " << bitset<32>(n) << endl;
    cout << "The total number of set bits in " << n << " is "
         << countSetBits(n) << endl;
 
    return 0;
}
