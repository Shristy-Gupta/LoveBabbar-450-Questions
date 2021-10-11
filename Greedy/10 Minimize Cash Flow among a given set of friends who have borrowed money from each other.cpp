// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int const N=3;
// amount[p] indicates the net amount to be credited/debited
// to/from person 'p'
// If amount[p] is positive, then i'th person will amount[i]
// If amount[p] is negative, then i'th person will give  -amount[i]
void minCashFlowRecurssion(int amount[]){
    // Find the indexes of minimum and maximum values in amount[]
    // amount[mxCredit] indicates the maximum amount to be given
    //                  (or credited) to any person .
    // And amount[mxDebit] indicates the maximum amount to be taken
    //                  (or debited) from any person.
    // So if there is a positive value in amount[], then there must
    // be a negative value
    int maxcredit_index=0,maxdebit_index=0;
    if(N==0){
        return;
    }
    for(int i=0;i<N;i++){
        if(amount[maxcredit_index]<amount[i]){
            maxcredit_index=i;
        }
        if(amount[maxdebit_index]>amount[i]){
            maxdebit_index=i;
        }
    }
    if(amount[maxcredit_index]==0 && amount[maxdebit_index]==0){
        return;
    }
    int minimum_amount=min(amount[maxcredit_index],-amount[maxdebit_index]);
    amount[maxcredit_index]-=minimum_amount;
    amount[maxdebit_index]+=minimum_amount;
    // If minimum is the maximum amount to be
    cout << "Person " << maxdebit_index << " pays " << minimum_amount
         << " to " << "Person " << maxcredit_index << endl;
 
    // Recur for the amount array.  Note that it is guaranteed that
    // the recursion would terminate as either amount[mxCredit]
    // or  amount[mxDebit] becomes 0
    minCashFlowRecurssion(amount);
    
}
// Given a set of persons as graph[] where graph[i][j] indicates
// the amount that person i needs to pay person j, this function
// finds and prints the minimum cash flow to settle all debts.
void minCashFlow(int graph[][N])
{
    int amount[N]={0};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //net cash flow is credit-debit
            amount[i]+=(graph[j][i]-graph[i][j]);
        }
    }
    minCashFlowRecurssion(amount);
}

int main() {
    // graph[i][j] indicates the amount that person i needs to
    // pay person j
    
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};
 
    // Print the solution
    minCashFlow(graph);
    return 0;
}
