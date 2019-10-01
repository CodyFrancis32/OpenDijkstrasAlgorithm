#include "edge.h"

Edge::Edge()
{

}

Edge::Edge(Vertex *to, int weight){
    to_ = to;
    weight_ = weight;
}

Vertex* Edge::GetTo(){
    return to_;
}

int Edge::GetWeight(){
    return weight_;
}

void Edge::SetTo(Vertex* to){
    to_ = to;
}

void Edge::SetWeight(int weight){
    weight_ = weight;
}

Edge* Edge::CopyEdge(){
    Edge* newEdge = new Edge();

    newEdge->SetTo(to_);
    newEdge->SetWeight(weight_);

    return newEdge;
}
