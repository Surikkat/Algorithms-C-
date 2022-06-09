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
    Node<T>* head; //"������" ���������� ������
public:
    List() //����������� ������ ��� ����������
    {
        head = NULL; //������� �������� ���� ���
    }
    //�����, ����������� ����� ���� � ������
    void addNode(T d);
    //�����, ��������� ��������� ������ �� �����
    void printList();
};
