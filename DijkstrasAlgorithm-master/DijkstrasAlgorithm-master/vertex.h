#ifndef VERTEX_H
#define VERTEX_H

#include "edge.h"
#include <vector>
#include <stack>

class Vertex
{
public:
    Vertex();
    Vertex(int key);

    char GetKey();
    int GetNumEdges();
    Edge* GetEdge(char to);
    Edge* GetEdge(int index);

    void AddEdge(Edge* newEdge);
    void AddEdge(Vertex *to, int key);
    bool HasEdge(char to);

    void SetNumEdges(int numEdges);
    void SetKey(char key);

    Vertex* CopyVertex();

    int GetWeight();
    int SetWeight(int weight);

    void ReconstructPath();

    Vertex* GetPrev();
    void SetPrev(Vertex* prev);
private:
    char key_ = '?';
    int num_edges_ = 0;

    int weight_ = 0;
    Vertex* prev_ = nullptr;

    std::vector<Edge *> edges_;
};

#endif // NODE_H
