#include <vector>
#include <algorithm>
#include "Node.h"
#include <iostream>

class Utils
{
public:
	Utils(void);
	~Utils();
	void aStar(Point D, Point A, std::vector<Point> &v, int towermap[20][15]);
	bool caseIsEmpty(int i, int j,  int towermap[20][15]);
	int distanceMan(Point D, Point A);
	int distanceCub(Point D, Point A);
	void addAdj(Node &C, int towermap[20][15]);
	bool isHere(Node &C, std::vector<Node*> &v);
	int getPos(Node &c, std::vector<Node*> &v);
	Node bestNode(std::vector<Node*> &v);
	void addCloseList(Node &C);
	void createPath(std::vector<Point> &v);

private:
	std::vector<Node*> _openlist;
	std::vector<Node*> _closedList;
	Node *Arr, *Dep;
};

