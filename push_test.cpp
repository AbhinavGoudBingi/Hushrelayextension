#include "header.h"

int push_test(int argc, char *argv[],int txnid,int source, int sink) {
  
 	 igraph_t g;
	 int *height;	
	clock_t t,e; 
         srand(time(NULL));         
 	 igraph_integer_t eid,from,to,value,vid,eid1,flow;//,source,sink,count=0;
 	 igraph_i_set_attribute_table(&igraph_cattribute_table);
	 FILE *fp6,*fp7;
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
          
        value=40;
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
	txn_heights[source][txnid] = igraph_vcount(&g);
	
         
	 
	 

	 //sscanf(argv[5],"%d",&value);   

	//  igraph_cattribute_VAN_set(&g,"excess",source,value); 
	 excesses[source][txnid] = value;    	  	       
	// printf("excess=%d\t",(igraph_integer_t)igraph_cattribute_VAN(&g,"excess",source));    
/*	for(vid=0;vid<igraph_vcount(&g);vid++)
		printf("%d,%d\t",height[vid],(igraph_integer_t)igraph_cattribute_VAN(&g,"excess",vid));*/
        t = clock();    

 	main_func(&g,source,sink,txnid);
	
	  
 	if(excesses[sink][txnid]==value)
        {
	    
	    	     
            //printf("generating random samples for all these nodes\n");
//            payment(&g,height,source,sink,&totalBytes);		       	
	    e=clock();
	    double time_taken = ((double)(e-t))/CLOCKS_PER_SEC; // in seconds 
	    printf("success");
	    fprintf(fp6,"%d %d %d %d %d %f",source,sink,value,igraph_vcount(&g),igraph_ecount(&g),time_taken); 
            fprintf(fp7,"%d.00 %d %d\n",value,source,sink);

	    fprintf(fp6," %s\n","success");		

        }
        else
	{
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
	    printf("flow=%d %d %d\n",from,to,(igraph_integer_t)igraph_cattribute_EAN(&g,"flow",eid));
         }
	 for(vid=0;vid<igraph_vcount(&g);vid++)
		printf("%d,%d\t",height[vid],(igraph_integer_t)igraph_cattribute_VAN(&g,"excess",vid));*/
    fclose(fp6);
    igraph_destroy(&g);
     return 0;
}
