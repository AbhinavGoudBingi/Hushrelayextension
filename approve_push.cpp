#include "header.h"

void approve_push(igraph_t *g,int vid_neighbour,int flow, int txnid)
{
	int excess;	
	excess=excesses[vid_neighbour][txnid]; //(int)igraph_cattribute_VAN(g,"excess",vid_neighbour);
	excesses[vid_neighbour][txnid] = excess+flow;
       // igraph_cattribute_VAN_set(g,"excess",vid_neighbour,excess+flow);
        if(types[vid_neighbour][txnid]!=-1)
        {
//		printf("exit=%s\n",igraph_cattribute_VAS(g,"type",vid_neighbour));
		cout<<"approving push to node "<<vid_neighbour<<" for txn id "<<txnid<<"\n";
	        lift(g,vid_neighbour,txnid);

	}	

}


