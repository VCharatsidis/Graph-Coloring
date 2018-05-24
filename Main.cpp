// reading a text file
#include "GraphReader.cpp"
using namespace std;

int main() {
	
	//Test GraphReader
	GraphReader* gr = new GraphReader();

	Graph* graph = gr->read("4_1");

	for (int i = 0; i < graph->nodes.size(); i++)
	{
		int node_id = graph->nodes[i]->id;
		std::cout << "node id " + std::to_string(node_id) << std::endl;
	}

	return 0;
}