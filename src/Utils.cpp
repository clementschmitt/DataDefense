#include "Utils.h"

Utils::Utils(void)
{

}

Utils::~Utils()
{
	delete Arr;
	delete Dep;
}

/*
* Calcule le chemin via A*
* D : point de départ
* A : point d'arrivée
* v : vecteur pour stocker le chemin
*/
void Utils::aStar(Point D, Point A, std::vector<Point> &v,  int towermap[20][15])
{
	Node *current;

	//on créer le point de départ
	Dep = new Node(D);
	Dep->setDP(0);
	Dep->setDR(this->distanceCub(D, A));
	Dep->MajDT();

	//on créer le point d'arrivé
    Arr = new Node(A);
	Arr->setDR(0);

	//le noeud courant devient le point de départ
	current = new Node(*Dep);

	_openlist.push_back(current);
	addCloseList(*current);
	addAdj(*current, towermap);

	//tant que la liste n'est pas vide et que l'on est pas sur la case d'arrivée
	while (!(current->getCoor().x == Arr->getCoor().x && current->getCoor().y == Arr->getCoor().y) && !_openlist.empty())
	{
		//on prend le meilleur noeud comme noeud courant
		current = new Node(bestNode(_openlist));

		addCloseList(*current);
		addAdj(*current, towermap);
	}

	if (current->getCoor().x == Arr->getCoor().x && current->getCoor().y == Arr->getCoor().y)
	{
		createPath(v);
	}
	else
	{
		std::cout << "No path found" << std::endl;
	}

}

//retourne vrai si la case est vide faux sinon
bool Utils::caseIsEmpty(int i, int j, int towermap[20][15])
{
	return towermap[i][j] != true
}

//calcul de la distance de Manhatan
int Utils::distanceMan(Point D, Point A)
{
	return std::abs(D.x - A.x) + std::abs(D.y - A.y);
}

//Calcul de la distance a vol d'oiseau
int Utils::distanceCub(Point D, Point A)
{
	return std::max(std::abs(D.x - A.x), std::abs(D.y - A.y));
	//return std::sqrt(std::pow(D.x + A.x,2) + std::pow(D.y + A.y,2));
}

//Ajoute les case adjacente dans la liste ouverte
void Utils::addAdj(Node &C, int towermap[20][15])
{
	Node *tmp;
	int pos;
	std::vector<Point> t;
	
	
	Point a;
	a.x = C.getCoor().x - 1;
	a.y = C.getCoor().y;
	t.push_back(a);
	a.x = C.getCoor().x + 1;
	a.y = C.getCoor().y;
	t.push_back(a);
	a.y = C.getCoor().y - 1;
	a.x = C.getCoor().x;
	t.push_back(a);
	a.y = C.getCoor().y + 1;
	a.x = C.getCoor().x;
	t.push_back(a);

	for (unsigned int i = 0; i < t.size(); i++)
	{
		if (t[i].x >= 0 && t[i].y >= 0 && t[i].x < 20 && t[i].y < 15 && caseIsEmpty(t[i].x, t[i].y, towermap))
		{
			tmp = new Node(t[i]);
			if (!isHere(*tmp, _closedList))
			{
				tmp->setDP(C.getDP() + distanceMan(C.getCoor(), t[i]));
				tmp->setDR(distanceMan(t[i], Arr->getCoor));
				tmp->MajDT();
				tmp->setParent(C);
			}

			if (isHere(*tmp, _openlist))
			{
				pos = getPos(*tmp, _openlist);
				if (tmp->getDT() < _openlist[pos]->getDT())
				{
					_openlist[pos] = new Node(*tmp);
				}
			}
			else
			{
				_openlist.push_back(tmp);
			}
		}
	}
	
		
}

//renvoi vrai si un noeud est dans la liste 
bool Utils::isHere(Node &C, std::vector<Node*> &v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (C == *v[i])
			return true;
	}
	return false;
}

//renvoi le noeuds de la liste avec le poids le plus faible
Node Utils::bestNode(std::vector<Node*> &v)
{
	Node *best;
	best = new Node(*v[0]);
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (i == 0)
			continue;
		else
		{
			if (best->getDT() > v[i]->getDT())
			{
				best = new Node(*v[i]);
			}
		}
	}

	return *best;
}

//ajoute un noeud dans la liste fermée et le retire de la liste ouverte
void Utils::addCloseList(Node &C)
{
	_closedList.push_back(&C);

	_openlist.erase(_openlist.begin() + getPos(C,_openlist));
}

//recréer le chemin
void Utils::createPath(std::vector<Point> &v)
{
	Node *tmp = new Node(*_closedList.back());
	Point p;

	while (tmp->getParent != NULL)
	{
		p.x = tmp->getCoor().x;
		p.y = tmp->getCoor().y;

		v.push_back(p);
		tmp = new Node(*tmp->getParent());
	}

	

}

//recupere la postion du noeud dans la liste
int Utils::getPos(Node &c, std::vector<Node*> &v)
{
	unsigned int i;
	for(i = 0; i < v.size(); i++)
	{
		if (c == *v[i])
			break;
	}
	return i;
}


