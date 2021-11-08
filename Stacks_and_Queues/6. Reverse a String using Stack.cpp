//return the address of the string
char* reverse(char *S, int len)
{
    stack<char> st;
    for(int i=0;i<len;i++){
        st.push(S[i]);
    }
    for(int i=0;i<len;i++){
        char k=st.top();
        st.pop();
        S[i]=k;
    }
    return S;
}
