#include "graph.h"

Graph::Graph()
{

}

void Graph::AddVertex(int key){
    vertex_list_.push_back(new Vertex(key));
    num_vertexes_++;
}

void Graph::AddEdge(char from, char to, int weight){
    Vertex *vfrom = GetVertex(from);
    Vertex *vto = GetVertex(to);
    vfrom->AddEdge(vto, weight);
}

Vertex* Graph::GetVertex(char key){
    int i = 0;
    while(i < num_vertexes_){
        if(vertex_list_[i]->GetKey() == key){
            return vertex_list_[i];
        }
        i++;
    }

    AddVertex(key);
    return vertex_list_[i];
}

bool Graph::IsAdjacent(char from, char to){
    Vertex *vfrom = GetVertex(from);

    if(vfrom->HasEdge(to)){
        return true;
    }else{
        return false;
    }
}

void Graph::PrintNeighbors(char vertex){
    Vertex *vfrom = GetVertex(vertex);

    for(int i = 0; i < vfrom->GetNumEdges(); i++){
        std::cout<<vfrom->GetEdge(i)->GetTo()->GetKey()<<" ";
    }
    std::cout<<std::endl;
}

Vertex* Graph::DijkstrasAlgorithm(char start, char end){ //This will house the majority of logic, so adding comments

    //The current vertex i'm are working on.
    Vertex* currentVertex = nullptr;

    //How many vertices we've visited.
    int visited = 0;

    //The array to keep track of the already visited vertices.
    int visitedIndex[6] = {0,0,0,0,0,0};  
    
    int currentDistance = 0;
    int currentShortestDistance = 10000;  //set this high to make sure its higher than all other

    //Set every Vertex's Distance to infinity
            //add all Vertex's to an unvisited list
    int unvisitedList[6] = {'1','2','3','4','5','6'};  //all vertexes are in univisted list
    for(int i=0; i<6; i++){
        currentVertex = GetVertex(unvisitedList[i]); //MIGHT NEED UNIVISTED LIST TO BE CHAR
        currentVertex->SetWeight(10000); //using 10000 as "infinity"
    }

    //Set start Vertex's Distance to 0
            // Set start point as current point
    currentVertex = GetVertex(start);   //current point is start point now
    currentVertex->SetWeight(0);        //start vertex weight is now 0

    //debugging stuff
        //currentVertex = GetVertex('4');
        //std::cout<<"VERTEX 4 HAS THIS MANY EDGES CONNECTED TO IT: "<<currentVertex->GetNumEdges()<<"\n";
        //std::cout<<currentVertex->GetEdge(0)->GetTo()->GetKey()<<"\n";
        //currentVertex->GetEdge(0)->GetTo()->SetWeight(1234);
        //std::cout<<currentVertex->GetEdge(0)->GetTo()->GetWeight()<<"\n";
        //int count = 0; //using this to refrence item in list so I can change my currentVertext
                        //if we didnt start at first node I would either need to change my list so its in order or come up with a new way
        //int count = currentVertex->GetKey()-49;
        //int visited = 0;
        //int temp = currentVertex->GetKey()-48; //converting from ascii hence -48
        //std::cout<<"the current vertex key is: "<<temp<<"\n";
        //int visited = temp - 1;
        //while(visited < 7 - unvisitedList[start]){
        //while(visitedIndex[currentVertex->GetKey()] != -1){
        //int t;
    
    //iterating through
    while(visited < 6){
        //find unvisited vertex with the least weight
        int tempshort = 10000;
        char indexShort;
        for(int i=0; i<6; i++){
            if(visitedIndex[i] != -1){                              //checking to see if its been visited
               //Debugging
                // std::cout<<i<<"\t"<<visitedIndex[i]<<std::endl;
                currentVertex = GetVertex(unvisitedList[i]);
                if(currentVertex->GetWeight()<tempshort){
                 //Debugging
                    //   std::cout<<"Made it"<<std::endl;
                    tempshort = currentVertex->GetWeight();
                    indexShort = currentVertex->GetKey();
                }
            }
        }
        currentVertex = GetVertex(indexShort);

        //Debugging
            //std::cout<<indexShort<<"\n";
            //std::cout<<currentVertex->GetKey()<<"\n";
        for(int i=0; i<currentVertex->GetNumEdges(); i++){  //looking at all neighbors of the current vertex
            
            //seeing if the edge of the vertex we are at, looking plus the weight of the current vertex we are on
                // is less than the total weight at the vertex it leads too
            if(currentVertex->GetEdge(i)->GetWeight() + currentVertex->GetWeight() < currentVertex->GetEdge(i)->GetTo()->GetWeight()){ // && visitedIndex[currentVertex->GetKey()] != -1){
                //setting the weight of the vertex that the edge leads to equal to
                    //the edge we are using to get there plus the vertex's weight we are leaving
                currentVertex->GetEdge(i)->GetTo()->SetWeight(currentVertex->GetEdge(i)->GetWeight() + currentVertex->GetWeight());
                //now connect the vertex's to show how we got to them
                    //so now vertex we just set has a prev = the vertex we visted from the edge
                currentVertex->GetEdge(i)->GetTo()->SetPrev(currentVertex);
                //Debugging
                    //std::cout<<"Vertex: "<<currentVertex->GetEdge(i)->GetTo()->GetKey() <<" prev = "<< currentVertex->GetKey()-48<<"\n";
            }
        }
        //Debugging
            //std::cout<<"The current Vertex is: "<<currentVertex->GetKey()<< " and it has a weight of:  "<<currentVertex->GetWeight() <<"\n";
        visitedIndex[(currentVertex->GetKey()-48)-1] = -1; 
        visited = visited + 1;  

    //now that this is all done, lets find the path that got us to our end vertex and return that
        //returning the end vertex since all the calculations have been done!
    currentVertex = GetVertex(end);
    return currentVertex;

    //Debugging
        //currentVertex = GetVertex(start);
        //currentVertex->SetPrev(currentVertex->GetEdge(0)->GetTo()->CopyVertex());
        //return currentVertex;
}

