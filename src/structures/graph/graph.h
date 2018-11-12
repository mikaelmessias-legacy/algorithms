/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

struct graph {
  int isWeighted;
  int vertices;
  int maxDegree;
  int **edges;
  float **weights;
  int *degree;
};

typedef struct graph Graph;

/**
 * @brief Allocates a graph structure in memory.
 * @param vertices The number of vertices in the graph.
 * @param degre The maximum degree of the graph
 * @param isWeighted A binary number that indicates if there is presence of weights in the graph
 * @return 
 **/
Graph *graph_create(int verticesNumber, int maxDegree, int isWeighted);

/**
 * @brief
 * @param graph
 **/
void graph_free(Graph *graph);

/**
 * @brief
 * @param graph
 * @param orig
 * @param dest
 * @param isDigraph
 * @param weight
 * @return
 **/
int graph_insert_edge(Graph *graph, int orig, int dest, int isDigraph, float weight);

/**
 * @brief
 * @param graph
 * @param orig
 * @param dest
 * @param isDigraph
 **/
int graph_remove_edge(Graph *graph, int orig, int dest, int isDigraph);

/**
 * @brief
 * @param graph
 * @param initial
 * @param visited
 **/
void graph_depth_search(Graph *graph, int initial, int *visited);

/**
 * @brief
 * @param graph
 * @param initial
 * @param visited
 **/
void graph_breadth_search(Graph *graph, int initial, int *visited);

/**
 * @brief
 * @param graph
 * @param initial
 * @param ancestor
 * @param distance
 **/
void graph_shortest_path(Graph *graph, int initial, int *ancestor, float *distance);

/**
 * @brief
 * @param graph
 * @param initial
 * @param ancestor
 * @param distance
 **/
void graph_print(Graph *graph);

#endif // GRAPH_H
