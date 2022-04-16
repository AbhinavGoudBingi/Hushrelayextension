#include "header.h"

void lift(igraph_t *g,int vid, int txnid)
{

	int neighbor,height_min=igraph_vcount(g)+100,eid1;
	int flag=0;
	if(types[vid][txnid]!=1)
	{
		igraph_vs_t vs;
	        igraph_vit_t vit;
        	igraph_vs_adj(&vs,vid,IGRAPH_OUT);
		igraph_vit_create(g,vs,&vit);
		flag=0;	
                while(!IGRAPH_VIT_END(vit))
		{
			
		
			neighbor=IGRAPH_VIT_GET(vit);
			igraph_get_eid(g,&eid1,vid,neighbor,IGRAPH_DIRECTED,1);
			//printf("%d,%d\n",height_min,height[neighbor]);
                        if((int)igraph_cattribute_EAN(g,"flow",eid1)<(int)igraph_cattribute_EAN(g,"weight",eid1))
			{
				flag=1;
				height_min=min(height_min,txn_heights[neighbor][txnid]);
			}
			IGRAPH_VIT_NEXT(vit);				
	
		}

                if(flag==1 && txn_heights[vid][txnid]<=height_min)
		        txn_heights[vid][txnid]=height_min+1;
               //printf("inc=%d,%d\n",vid,height[vid]);
	}	

}


