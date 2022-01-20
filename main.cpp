#include "Graph.h"
#include "SimpleEdge.h"
#include <iostream>

int main()
{
  Graph g;
  // You can subclass Node, in order to add functionallity to the nodes.
  Node& rMunich = g.makeNode(Node("Munich"));
  Node& rHamburg = g.makeNode<Node>("Hamburg");
  Node& rBerlin = g.makeNode<Node>("Berlin");
  Node& rFrankfurt = g.makeNode<Node>("Frankfurt");

  // SimpleEdge is useful for some cases, but you can also subclass Edge.
  g.makeEdge<SimpleEdge>(rBerlin, rHamburg, 450);
  g.makeEdge<SimpleEdge>(rHamburg, rBerlin, 450);
  // You can make the edges bidirectional, too:
  g.makeBiEdge<SimpleEdge>(rBerlin, rMunich, 650);
  g.makeBiEdge<SimpleEdge>(rBerlin, rFrankfurt, 590);

  // find the shortest path between any type of nodes, regarding the weight of your edges
  auto path = g.findShortestPathDijkstra(rHamburg, rMunich);
  for (Edge* pEdge : path) {
      // dynamic_cast to your Edge type is useful, if you have multiple different types of edges.
      SimpleEdge* pMyEdge = dynamic_cast<SimpleEdge*>(pEdge);
      if (pMyEdge != NULL) {
          std::cout << pEdge->toString() << std::endl;
      }
  }

  return 0;
}