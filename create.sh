#!/bin/5h

g++ create_graph.cpp -I/usr/local/include/igraph -ligraph -o create
for((i=60000;i<=280000;i*=2))
do
   mkdir node_$i
  ./create $i node_$i/view$i.graphml node_$i/read_graph_edge_$i.txt node_$i/read_graph_weight_$i.txt node_$i/ripple-lcc.graph node_$i/ripple-lcc.graph_CREDIT_LINKS node_$i/degOrder-bi.txt
done


  ./create 10 node_10/view10.graphml node_10/read_graph_edge_10.txt node_10/read_graph_weight_10.txt node_10/ripple-lcc.graph node_10/ripple-lcc.graph_CREDIT_LINKS node_10/degOrder-bi.txt
