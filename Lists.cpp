#include <stdlib.h> 

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

link freelist;//Список свободных узлов

//Создание списка свободных узлов, которые потом будут раздаваться другим связным спискам
void construct(int N) {
	freelist = new node[N + 1];

	for (int i = 0; i < N; ++i) {
		freelist[i].next = &freelist[i + 1];
	}

	freelist[N].next = 0;
}

//Удаляем узел из списка (после x)
link remove(link x) {
	link t = x->next;
	x->next = t->next;
	return t;
}

//Создаём новый узел, взяв его из пула свободных
link newNode(int i) {
	link x = remove(freelist);
	x->item = i;
	x->next = x;
	return x;
}

//void deleteNode



//////////////////////////////////////////////////////////////////////////////////////////////////

//Обращения порядка следования элементов списка
link reverse(link x) {
	link t;
	link y = x;
	link r = 0;

	while (y != 0) {
		t = y->next;
		y->next = r;
		r = y;
		y = t;
	}

	return r;
}

//Сортировка связного списка методом вставки (вставляем из одного связного списка узлы в другой в нужном порядке)
//Время выполнения N^2
link sortInsert() {
	const int N = 100;
	node heada(0, 0);//Фиктивный начальный узел 1-го сиска
	link a = &heada;
	link t = a;

	//Заполняем первый список случайными числами
	for (int i = 0; i < N; ++i) {
		t = (t->next = new node(rand() % 1000, 0));
	}

	node headb(0, 0);//Фиктивный начальный узел 2-го списка
	link u;
	link x;
	link b = &headb;

	//Переставляем элементы первого списка во второй в нужные места
	for (t = a->next; t != 0; t = u) {
		u = t->next;
		for (x = b; x->next != 0; x = x->next) {
			if (x->next->item > t->item) {
				break;
			}
		}
		t->next = x->next;
		x->next = t;
	}

	return b;
}