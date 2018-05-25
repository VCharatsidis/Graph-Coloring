#ifndef NODE_H
#define NODE_H
#include <vector>

struct Node {
	int id;
	std::vector<int> neighbours;
	std::vector<int> available_colors;
	int color = -1;
};

#endif