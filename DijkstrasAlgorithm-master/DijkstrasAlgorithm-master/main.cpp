#include <iostream>
#include "graph.h"

int main()
{

    Graph my_graph;

    my_graph.AddEdge('1', '2', 7);
    my_graph.AddEdge('1', '3', 9);
    my_graph.AddEdge('1', '6', 14);
    my_graph.AddEdge('2', '3', 10);
    my_graph.AddEdge('2', '4', 15);
    my_graph.AddEdge('3', '6', 2);
    my_graph.AddEdge('3', '4', 11);
    my_graph.AddEdge('4', '5', 6);
    my_graph.AddEdge('6', '5', 9);

    Vertex* lastVertex = my_graph.DijkstrasAlgorithm('1', '5');

    //My Current example should output 1 3 6 5
    lastVertex->ReconstructPath();

    //Test, should output 2 3 6
    //Vertex* testVertex = my_graph.DijkstrasAlgorithm('2','6');
    //testVertex->ReconstructPath();
}
