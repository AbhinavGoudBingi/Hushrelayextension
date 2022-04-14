#include "header.h"

map<int,unordered_map<int,int> > txn_heights,excesses,types;

int main(int argc, char *argv[]){
    txn_heights.clear();
    excesses.clear();
    types.clear();
    int global_txn_id=0;
    
clock_t t,e; 
t=clock();
vector<thread> threads;
int NUM_THREADS = 10;
int source = 0;
int sink = 100;
for(int i=0;i<NUM_THREADS;i++){
    thread th(push_test,argc, argv,global_txn_id,source,sink);
    
    threads.push_back(move(th));
    global_txn_id++;
    source++;
    sink++;
}
for(int i=0;i<NUM_THREADS;i++){
    threads[i].join();
}
e = clock();
double time_taken = ((double)(e-t))/CLOCKS_PER_SEC;
cout<<time_taken<<endl;
return 0;
}