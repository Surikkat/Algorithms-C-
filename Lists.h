#pragma once
typedef int Item;

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

//������� �������� ��� ������ �� ��������
void construct(int n);
link newNode(int n);
void deleteNode(Node n);
void insertNode(Node n, Node m);
link remove(Node n);
link next(Node n);
Item item(Node n);




////////////////////////////////////////////////////////////////////////////////////////////////////

//���������� �������� ������ ������� ������� (��������� �� ������ �������� ������ ���� � ������ � ������ �������)
// ������ ����������� � ����������� ���
//����� ���������� N^2
link sortInsert();

//��������� ������� ���������� ��������� ������
link reverse(link x);

//���� ������������� ������
struct doublyLinkedNode {
	Item item;
	node* next;
	node* prev;
};
