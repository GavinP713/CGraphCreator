#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Edge {
  int toIndex;
  int value;

  Edge(int _toIndex, int _value) {
    toIndex = _toIndex;
    value = _value;
  }
};  

struct Vert {
  vector<Edge*> edges;
  string label;
  int index;
  
  Vert(string _label, int _index) {
    label = _label;
    index = _index;
  }
  
  ~Vert() {
    // delete edge list from memory
    for (Edge* edge : edges) {
      delete(edge);
    }
  }
};

Vert* addVert(vector<Vert*> &graph, string _label);
Edge* addEdge(vector<Vert*> &graph, string labelA, string labelB);
void removeVert(vector<Vert*> &graph, string _label);
void removeEdge(vector<Vert*> &graph, string labelA, string labelB);
void connect(Vert* vertA, Vert* vertB);
void disconnect(Vert* vertA, Vert* vertB);
bool checkConnected(Vert* vertA, Vert* vertB);
void print(vector<Vert*> graph);

int main() {
  vector<Vert*> graph;
  
  return 0;
}

Vert* addVert(vector<Vert*> &graph, string _label) {
  Vert* vert = new Vert(_label, graph.size());
  graph.push_back(vert);
  
  return vert;
}

Edge* addEdge(vector<Vert*> &graph, string labelA, string labelB) {
  Vert* vertA = addVert(graph, labelA);
  Vert* vertB = addVert(graph, labelB);
  Edge* edge = new Edge(vertB->index, 0);

  vertA->edges.push_back(edge);

  return edge;
}

Vert* getVert(string _label) {

}

void removeVert(vector<Vert*> &graph, Vert* target) {
  // loop through verts
  for (Vert* vert : graph) {
    if (vert != target) {
      // loop through edges
      vector<Edge*> &edges = vert->edges;
      for (vector<Edge*>::iterator it = edges.begin(); it != edges.end();) {
	if (edges[it]->toIndex == target->index) {
	  // unlink
	  edges.erase(it);
	}
      }
    }
  }

  // delete from memory
  delete target;
}

void removeEdge(vector<Vert*> &graph, string vertA, string vertB) {

}

// add an edge between two verts
void connect(Vert* vertA, Vert* vertB) {
  // check that it isnt already connected
  if (checkConnected(vertA, vertB) == false) {
    Edge* edge = new Edge(vertB->index, 0);
    vertA->edges.push_back(edge);
  }
}

void disconnect(Vert* vertA, Vert* vertB) {
  for (Edge* edge : vertA->edges) {
    if (edge->toIndex == vertB->index) {
      vertA->edges.erase(edge);
      delete edge;
      return;
    }
  }
}

bool checkConnected(Vert* vertA, Vert* vertB) {
  for (Edge* edge : vertA->edges) {
    if (edge->toIndex == vertB->index) {
      return true;
    }
  }
  return false;
}

void print(vector<Vert*> graph) {

}
