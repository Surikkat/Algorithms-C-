#pragma once
typedef int Item;

//Узел списка
struct node {
	int item;
	node* next;

	node(int x, node* t)
	{
		item = x;
		next = t;
	}

	node()
	{
		item = 0;
		next = 0;
	}
};

typedef node* link;

//Базовые операции для работы со списками
void construct(int n);
link newNode(int n);
void deleteNode(Node n);
void insertNode(Node n, Node m);
link remove(Node n);
link next(Node n);
Item item(Node n);




////////////////////////////////////////////////////////////////////////////////////////////////////

//Сортировка связного списка методом вставки (вставляем из одного связного списка узлы в другой в нужном порядке)
// Список заполняется и сортируется сам
//Время выполнения N^2
link sortInsert();

//Обращения порядка следования элементов списка
link reverse(link x);

//Узел двусвязанного списка
struct doublyLinkedNode {
	Item item;
	node* next;
	node* prev;
};
