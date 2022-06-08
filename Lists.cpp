#include <stdlib.h> 

//���� ������
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

link freelist;//������ ��������� �����

//�������� ������ ��������� �����, ������� ����� ����� ����������� ������ ������� �������
void construct(int N) {
	freelist = new node[N + 1];

	for (int i = 0; i < N; ++i) {
		freelist[i].next = &freelist[i + 1];
	}

	freelist[N].next = 0;
}

//������� ���� �� ������ (����� x)
link remove(link x) {
	link t = x->next;
	x->next = t->next;
	return t;
}

//������ ����� ����, ���� ��� �� ���� ���������
link newNode(int i) {
	link x = remove(freelist);
	x->item = i;
	x->next = x;
	return x;
}

//void deleteNode



//////////////////////////////////////////////////////////////////////////////////////////////////

//��������� ������� ���������� ��������� ������
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

//���������� �������� ������ ������� ������� (��������� �� ������ �������� ������ ���� � ������ � ������ �������)
//����� ���������� N^2
link sortInsert() {
	const int N = 100;
	node heada(0, 0);//��������� ��������� ���� 1-�� �����
	link a = &heada;
	link t = a;

	//��������� ������ ������ ���������� �������
	for (int i = 0; i < N; ++i) {
		t = (t->next = new node(rand() % 1000, 0));
	}

	node headb(0, 0);//��������� ��������� ���� 2-�� ������
	link u;
	link x;
	link b = &headb;

	//������������ �������� ������� ������ �� ������ � ������ �����
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