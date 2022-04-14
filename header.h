#include <igraph.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
//#include <gcrypt.h>
#include "puzzle.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <bits/stdc++.h>
//#include "omp.h"
using namespace std;

//#define ENABLE_OMP_PARALLEL_FOR

// #error ySize was already defined

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

extern map<int,unordered_map<int,int> > txn_heights,excesses,types;
int push_test(int argc, char *argv[],int txnid,int source, int sink);
int min(int x,int y);
void preflow(igraph_t *g,int source, int txnid);
void main_func(igraph_t *g,int source,int sink,int txnid);
void lift(igraph_t *g,igraph_integer_t vid,int txnid);
void approve_push(igraph_t *g,igraph_integer_t vid_neighbour,int flow,int txnid);
void payment(igraph_t *g,int *height,igraph_integer_t source,igraph_integer_t sink,unsigned long int*);
void bfs_mark(igraph_t *g,int *bfs_edge_marker,int *height,igraph_integer_t source,igraph_integer_t sink,unsigned char **buffer,unsigned long int*);
//void create_puzzle(igraph_t *g,unsigned char **buffer,int *edge_set,int track,int source,int sink,unsigned long int*);
//void solve_puzzle(igraph_t *g, int *edge_set,int track, y_val **commit,unsigned char **buffer, int source,int sink,int res,unsigned long int*);

#endif
