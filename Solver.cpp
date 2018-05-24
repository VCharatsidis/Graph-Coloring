#include "Graph.cpp";
#include <iostream>
#include <string>
using std::vector;

class Solver {
public:
	Graph* graph;
	Solver(Graph* give_graph) : graph(give_graph) {};
	Graph* core;

	void solve() {
		core = graph->clone();
		int size = graph->nodes.size();

		//for (int number_colors = 2; number_colors < size; number_colors++)
		//{
			setup_colors(100);
			delete_unimportant_nodes(100);
		//}
	}

private:

	void setup_colors(int number_colors)
	{
		int size = graph->nodes.size();

		for (int node = 0; node < size; node++)
		{
			for (int color = 0; color < number_colors; color++)
			{
				graph->nodes[node]->available_colors.push_back(1);
				core->nodes[node]->available_colors.push_back(1);
			}
		}
	}

	void delete_unimportant_nodes(int number_colors)
	{
		int deleted = 0;
		int temp = -1;

		while (temp != deleted) 
		{
			int size = core->nodes.size();
			temp = deleted;
			for (int node = 0; node < size; node++)
			{
				int neighbours = core->nodes[node]->neighbours.size();

				if (neighbours < number_colors - 1)
				{
					
					int node_id = core->nodes[node]->id;
					std::cout << "node to be deleted " + std::to_string(node_id)+" deleted = "+std::to_string(deleted) << std::endl;

					update_core_neighbours(node_id);
					core->nodes.erase(core->nodes.begin() + node);
					deleted++;
					break;
				}
			}
		}
	}

	void update_core_neighbours(int to_be_deleted)
	{
		int size = core->nodes.size();

		for (int node = 0; node < size; node++)
		{
			int neighbours_size = core->nodes[node]->neighbours.size();

			for (int j = 0; j < neighbours_size; j++)
			{
				if (core->nodes[node]->neighbours[j] == to_be_deleted)
				{
					core->nodes[node]->neighbours.erase(core->nodes[node]->neighbours.begin() + j);
					break;
				}
			}	
		}
	}
};