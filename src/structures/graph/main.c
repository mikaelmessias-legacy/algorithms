#include <stdio.h>
#include "graph.h"

int main() {
  Graph *g = graph_create(3, 2, 0);
   
  if(g) {
    printf("Graph created sucessfully.\n\n");
    printf("Vertices: %d\nMax degree: %d\nIs weighted? ", g->vertices,   \
           g->maxDegree);
    
    if(g->isWeighted) {
      printf("Yes\n");
    }
    else {
      printf("No\n\n");
    }
  }

  graph_insert_edge(g,0,1,0,0);
  graph_insert_edge(g,0,2,0,0);
  graph_insert_edge(g,1,2,0,0);
  graph_insert_edge(g,1,0,0,0);

  graph_print(g);
  
  graph_free(g);
  
  return 0;
}
