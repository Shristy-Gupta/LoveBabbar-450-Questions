/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/
long long mod=1000000007;
long long number(Node* head){
  long long ans=0;
  while(head!=NULL){
      long long val=head->data;
      ans=((ans*10)%mod+val)%mod;
      head=head->next;
  }
  return ans;
}
/*You are required to complete this method*/
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  long long number1=number(l1);
  long long number2=number(l2);
  return ((number1*number2)%mod);
}
