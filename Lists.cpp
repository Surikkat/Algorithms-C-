//Узел списка
struct node {
	int item;
	node* next;

	node(int x, node* t)
	{
		item = x;
		next = t;
	}
};