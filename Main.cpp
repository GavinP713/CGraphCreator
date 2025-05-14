#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct edge {
  int toIndex;
  int value;
};  

struct vert {
  vector<edge> edges;
  string label;
};

void addVert(string _label);
void addEdge(string labelA, string labelB);
void removeVert(string _label);
void removeEdge(string labelA, string labelB);
void connect(vert vertA, vert vertB);
void disconnect(vert vertA, vert vertB);
void print();

int main() {
  vector<vert> graph;
  
  addVert("A");
  addVert("B");
  
  return 0;
}

void addVert(string _label) {
  
}

void addEdge(string labelA, string labelB) {
  
}

void removeVert(string _label) {

}

void removeEdge(string vertA, string vertB) {

}

void print() {

}
