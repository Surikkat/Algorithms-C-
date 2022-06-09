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
    Node<T>* head; //"голова" связанного списка
public:
    List() //конструктор класса без параметров
    {
        head = NULL; //первого элемента пока нет
    }
    //метод, добавляющий новый узел в список
    void addNode(T d);
    //метод, выводящий связанный список на экран
    void printList();
};
