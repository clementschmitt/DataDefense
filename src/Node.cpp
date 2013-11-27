#include "Node.h"

//constructeur à partir d'un point
Node::Node(Point n)
{
	this->_coor.x = n.x;
	this->_coor.y = n.y;
}

//constructeur par copie
Node::Node(Node &p)
{
	this->parent = p.getParent();
	this->_distP = p.getDP();
	this->_distR = p.getDR();
	this->_distT = p.getDT();
	this->_coor.x = p.getCoor().x;
	this->_coor.y = p.getCoor().y;
}

//setteur distance parcourue
void Node::setDP(int d){ _distP = d; }
//getteur distance parcourue
int Node::getDP(){ return _distP; }
//setteur distance restante
void Node::setDR(int d){ _distR = d; }
//met à jour la distance totale
void Node::MajDT(){ _distT = _distP + _distR; }
//getteur sur x et y
Point Node::getCoor(){ return _coor; }
//setteur noeud parent
void Node::setParent(Node &p){ parent = new Node(p); }
//getteur DT
int Node::getDT(){ return _distT; };
//getteur parent
Node* Node::getParent(){ return parent; }
//getteur distance restante
int Node::getDR(){ return _distR; }

//redéfinission opérateur ==
bool Node::operator==(const Node& a)
{
	//return (this->parent == a.parent && this->_coor.x == a._coor.x && this->_coor.y == a._coor.y && this->_distP == a._distP && this->_distR == a._distR && this->_distT == a._distT);
	return (this->_coor.x == a._coor.x && this->_coor.y == a._coor.y );
}

//destructeur
Node::~Node()
{
	delete parent;
}
