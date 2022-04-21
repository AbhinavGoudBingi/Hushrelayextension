#include "header.h"

int push_test(int argc, char *argv[],int txnid,int source, int sink,igraph_t *g) {
  
 	clock_t t,e;
	 FILE *fp6,*fp7;
	 fp6=fopen(argv[3],"a"); 
	if(!fp6)
 	 {
		perror("file does not exist\n");
		exit(1);

 	 }
	//  for(vid=0;vid<igraph_vcount(&g);vid++)
	//  {
	//       igraph_cattribute_VAS_set(&g,"type",vid,"normal");
	//       height[vid]=0;
	//  }

 	 
 	//  sscanf(argv[4],"%d",&source);
    //       sscanf(argv[5],"%d",&sink);    
	 fp7=fopen(argv[4],"a");
        /* if(sink%4==0)
          value=rand()%8+70;
         else if(sink%5==0)
           value=rand()%5+70;
         else if(sink%3==0)
	   value=rand()%7+70;
         else if(sink%7==0)
	  value=rand()%10+70;
         else
           value=rand()%8+70;*/
          
     int value=20;
    //    for(vid=0;vid<igraph_vcount(&g);vid++)
	//  {
		
	// 	igraph_cattribute_VAN_set(&g,"excess",vid,0);
		
		
		
	//  }
    //   for(vid=0;vid<igraph_vcount(&g);vid++)
	//  {
	//       igraph_cattribute_VAS_set(&g,"type",vid,"normal");
	//       height[vid]=0;
	//  }
	types[source][txnid] = 1;
	types[sink][txnid] = -1;
    //      igraph_cattribute_VAS_set(&g,"type",source,"source");
	//  igraph_cattribute_VAS_set(&g,"type",sink,"sink");

	//  height[source]=igraph_vcount(&g);
	txn_heights[source][txnid] = igraph_vcount(g);
	
         
	 
	 

	 //sscanf(argv[5],"%d",&value);   

	//  igraph_cattribute_VAN_set(&g,"excess",source,value); 
	 excesses[source][txnid] = value;    	 
	// printf("excess=%d\t",(int)igraph_cattribute_VAN(&g,"excess",source));    
/*	for(vid=0;vid<igraph_vcount(&g);vid++)
		printf("%d,%d\t",height[vid],(int)igraph_cattribute_VAN(&g,"excess",vid));*/
        t = clock();    

 	main_func(g,source,sink,txnid);
	
 	if(excesses[sink][txnid]==value)
        {
	    
	    	 cout<<"sending ACK\n";    
            //printf("generating random samples for all these nodes\n");
//            payment(&g,height,source,sink,&totalBytes);		       	
	    e=clock();
	    double time_taken = ((double)(e-t))/CLOCKS_PER_SEC; // in seconds 
	    printf("success");
	    fprintf(fp6,"%d %d %d %d %d %f",source,sink,value,igraph_vcount(g),igraph_ecount(g),time_taken); 
            fprintf(fp7,"%d.00 %d %d\n",value,source,sink);

	    fprintf(fp6," %s\n","success");		

        }
        else
	{
		cout<<"sending NACK\n";
	   printf("fail %d\n",sink);
           /* e=clock();
	    
	    double time_taken = ((double)(e-t))/CLOCKS_PER_SEC; // in seconds 
	    fprintf(fp6,"%d %d %d %d %d %f ",source,sink,value,igraph_vcount(&g),igraph_ecount(&g),time_taken); 
            fprintf(fp7,"%d.00 %d %d\n",value,source,sink);
           
	    fprintf(fp6," %s\n","failure");*/
	}
/*	 for(eid=0;eid<igraph_ecount(&g);eid++)
         {
            igraph_edge(&g,eid,&from,&to);
	    printf("flow=%d %d %d\n",from,to,(int)igraph_cattribute_EAN(&g,"flow",eid));
         }
	 for(vid=0;vid<igraph_vcount(&g);vid++)
		printf("%d,%d\t",height[vid],(int)igraph_cattribute_VAN(&g,"excess",vid));*/
    fclose(fp6);
     return 0;
}
