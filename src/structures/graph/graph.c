/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* struct graph {
  int isWeighted;
  int vertices;
  int maxDegree;
  int **edges;
  float **weights;
  int *degree;
};*/

Graph *graph_create(int verticesNumber, int maxDegree, int isWeighted) {
  Graph *g;

  g = (Graph*) malloc(sizeof(struct graph));

  if(g != NULL) {
    int i;

    g->vertices = verticesNumber;
    g->maxDegree = maxDegree;
    g->isWeighted = (isWeighted != 0)?1:0;;
    g->degree = (int*) calloc(verticesNumber, sizeof(int));
    g->edges = (int**) malloc(verticesNumber * sizeof(int*));

    for(i = 0; i < verticesNumber; i++) {
      g->edges[i] = (int*) malloc(maxDegree * sizeof(int));
    }

    if(g->isWeighted) {
      g->weights = (float**) malloc(verticesNumber * sizeof(float*));

      for(i = 0; i < verticesNumber; i++) {
        g->weights[i] = (float*) malloc(maxDegree * sizeof(float));
      }
    }
  }

  return g;
}

void graph_free(Graph *graph) {
  if(graph != NULL) {
    int i;

    for(i = 0; i < graph->vertices; i++) {
      free(graph->edges[i]);
    }
    free(graph->edges);

    if(graph->isWeighted) {
      for(i = 0; i < graph->vertices; i++) {
        free(graph->weights[i]);
      }
      free(graph->weights);
    }

    free(graph->degree);
    free(graph);
  }
}

int graph_insert_edge(Graph *graph, int orig, int dest, int isDigraph, float weight) {
  if(graph == NULL) {
    return 0;
  }
  if(orig < 0 || orig >= graph->vertices) {
    return 0;
  }
  if(dest < 0 || dest >= graph->vertices) {
    return 0;
  }

  graph->edges[orig][graph->degree[orig]] = dest;
  if(graph->isWeighted) {
    graph->weights[orig][graph->degree[orig]] = weight;
  }
  graph->degree[orig]++;

  if(isDigraph == 0) {
    graph_insert_edge(graph,dest,orig,1,weight);
  }

  return 1;
}

int graph_remove_edge(Graph *graph, int orig, int dest, int isDigraph) {
  if(graph == NULL) {
    return 0; 
  }
  if(orig < 0 || orig >= graph->vertices) {
    return 0;
  }
  if(dest < 0 || dest >= graph->vertices) {
    return 0;
  }

  int i = 0;

  while(i < graph->degree[orig] && graph->edges[orig][i] != dest) {
    i++;
  }

  if(i == graph->degree[orig]) {
    // Could not find element
    return 0;
  }
  
  graph->degree[orig]--;
  graph->edges[orig][i] = graph->edges[orig][graph->degree[orig]];

  if(graph->isWeighted) {
    graph->weights[orig][i] = graph->weights[orig][graph->degree[orig]];
  }

  if(isDigraph == 0) {
    graph_remove_edge(graph,dest,orig,1);
  }

  return 1;
  
}

void graph_print(Graph *graph) {
  if(graph == NULL) {
    return;
  }

  int i, j;

  for(i = 0; i < graph->vertices; i++) {
    printf("%d: ", i);

    for(j = 0; j < graph->degree[i]; j++) {
      if(graph->isWeighted) {
        printf("%d(%.2f), ", graph->edges[i][j], graph->weights[i][j]);
      }
      else {
        printf("%d, ", graph->edges[i][j]);
      }
    }

    printf("\n");
  }
}
