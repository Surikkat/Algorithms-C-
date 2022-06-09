
//���� ���������� ������
template <typename T>
struct Node
{
    T data;
    Node* next;
};

//��������� ������
template <typename T>
class List
{
private:
    Node<T>* head; //������ ���������� ������
public:
    //����������� 
    List() { head = NULL; }

    //���������� ������ ���� � ������
    void addNode(T d);

    //����� �������� ������ �� �����
    void printList();
};

//���������� ������ ���� � ������
template <typename T>
void List<T>::addNode(T d)
{
    //������ ����� ����
    Node<T>* nd = new Node<T>;
    nd->data = d;
    nd->next = NULL;

    //���� ����������� ���� ������ � ������
    if (head == NULL) { head = nd; }
    else                 //���� ���� �� ������ � ������
    {
        //���� ���� ������� ��� ����� ��������� � ������
        Node<T>* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nd;
    }
}

template <typename T>
void List<T>::printList()
{
    Node<T>* current = head;
    while (current != NULL)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}