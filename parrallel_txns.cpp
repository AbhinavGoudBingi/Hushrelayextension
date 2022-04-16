#include "header.h"

map<int,unordered_map<int,int> > txn_heights,excesses,types;
map<int,queue<int> > waiting_txns;
mutex heights_lock,excess_lock,types_lock,graph_lock;

int main(int argc, char *argv[]){
    txn_heights.clear();
    excesses.clear();
    types.clear();
    int global_txn_id=0;

     igraph_t g;
         srand(time(NULL));         
 	 int eid,from,to,value,flow;//,source,sink,count=0;
 	 igraph_i_set_attribute_table(&igraph_cattribute_table);
	 
 	 FILE *fp=fopen(argv[1],"r"); 
 	 if(!fp)
 	 {
	
		perror("file does not exist\n");
		exit(1);
 	 }
	 
 	 igraph_read_graph_edgelist(&g, fp, 0, IGRAPH_DIRECTED);
 	 fclose(fp);
	// height=(int*)calloc(igraph_vcount(&g),sizeof(int));
 	 fp=fopen(argv[2],"r");
 	 if(!fp)
 	 {
		perror("file does not exist\n");
		exit(1);

 	 }

      for(eid=0;eid<igraph_ecount(&g);eid++)
 	 {
	
		fscanf(fp,"%d %d",&flow,&value);
 	        igraph_edge(&g, eid, &from, &to);
	//	printf("eid=%d, %d, %d\n",eid,from,to);
 	 	igraph_cattribute_EAN_set(&g,"weight",eid,value);
	//	printf("val=%d\n",(int)igraph_cattribute_EAN(&g, "weight",eid));

				
	    	
	        igraph_cattribute_EAN_set(&g,"flow",eid,flow);            
		igraph_cattribute_EAN_set(&g,"flow_true",eid,0);            

 	 }
    
clock_t t,e; 
t=clock();
vector<thread> threads;
int NUM_THREADS = 20;
int source = 0;
int sink = 100;
for(int i=0;i<NUM_THREADS;i++){
    thread th(push_test,argc, argv,global_txn_id,source,sink,&g);
    //cout<<"hi\n";
    threads.push_back(move(th));
    //threads[i].join();
    global_txn_id++;
    source++;
    sink++;
}
for(int i=0;i<NUM_THREADS;i++){
    threads[i].join();
}

e = clock();
igraph_destroy(&g);
double time_taken = ((double)(e-t))/CLOCKS_PER_SEC;
cout<<time_taken<<endl;
return 0;
}