#ifndef EDGE_H
#define EDGE_H

#include "iostream"
class Vertex;

class Edge
{
public:
    Edge();
    Edge(Vertex *to, int weight);

    Vertex* GetTo();
    int GetWeight();

    void SetTo(Vertex* to);
    void SetWeight(int weight);

    Edge* CopyEdge();
private:
    int weight_ = 0;
    Vertex *to_;
};

#endif // EDGE_H
