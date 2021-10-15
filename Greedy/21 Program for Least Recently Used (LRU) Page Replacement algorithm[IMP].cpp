class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        int pf=0;
        vector<int> memory;
        for(int i=0;i<N;i++){
           
            if(memory.size()==0){
                pf++;
                memory.push_back(pages[i]);
            }
            else{
                 //Find the element is alredy present in the memory
                 auto it= find(memory.begin(),memory.end(),pages[i]);
                 //If the item is not present then insert in the memory
                 if(it==memory.end()){
                     pf++;
                     if(memory.size()==C){
                         memory.erase(memory.begin());
                     }
                     memory.push_back(pages[i]);
                 }
                 else{
                     //If item is already present in the memory then move to the top
                     memory.erase(it);
                     memory.push_back(pages[i]);
                 }
            }
        }
        return pf;
    }
};
