
//Узел связанного списка
template <typename T>
struct Node
{
    T data;
    Node* next;
};

//Связанный список
template <typename T>
class List
{
private:
    Node<T>* head; //Голова связанного списка
public:
    //Конструктор 
    List() { head = NULL; }

    //Добавление нового узла в список
    void addNode(T d);

    //Вывод связного списка на экран
    void printList();
};

//Добавление нового узла в список
template <typename T>
void List<T>::addNode(T d)
{
    //Создаём новый узел
    Node<T>* nd = new Node<T>;
    nd->data = d;
    nd->next = NULL;

    //Если создаваемый узел первый в списке
    if (head == NULL) { head = nd; }
    else                 //Если узел не первый в списке
    {
        //Ищем узел который идёт перед последним в списке
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