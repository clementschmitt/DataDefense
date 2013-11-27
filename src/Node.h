
struct Point
{
	int x;
	int y;
};

class Node
{
public:
	Node(Point n);
	Node(Node &p);
	~Node();
	void setDP(int d);
	int getDP();
	void setDR(int d);
	Point getCoor();
	void MajDT();
	int getDT();
	int getDR();
	void setParent(Node &p);
	Node* getParent();
	bool operator==(const Node& a);
private:
	//noeud parent
	Node *parent = 0;
	//distance entre le point de départ et le noeud
	int _distP;
	//distance entre le noeud et le point d'arriver à vol d'oiseau
	int _distR;
	//distance totale
	int _distT;
	//coordonnées de la case
	Point _coor;
};