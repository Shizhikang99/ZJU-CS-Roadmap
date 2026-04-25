#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  void insertAtHead(int val)
  {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
  }

  void insertAtTail(int val)
  {
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
      head = newNode;
      return;
    }
    Node *cur = head;
    while (cur->next != nullptr)
    {
      cur = cur->next;
    }
    cur->next = newNode;
  }

  void deleteNode(int val)
  {
    if (head == nullptr)
      return;
    if (head->data == val)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }
    Node *cur = head;
    while (cur->next != nullptr && cur->next->data != val)
    {
      cur = cur->next;
    }
    if (cur->next != nullptr)
    {
      Node *temp = cur->next;
      cur->next = cur->next->next;
      delete temp;
    }
  }

  bool contains(int val)
  {
    Node *cur = head;
    while (cur != nullptr)
    {
      if (cur->data == val)
        return true;
      cur = cur->next;
    }
    return false;
  }

  void print()
  {
    Node *cur = head;
    while (cur != nullptr)
    {
      cout << cur->data;
      if (cur->next != nullptr)
        cout << " -> ";
      cur = cur->next;
    }
    cout << endl;
  }

  ~LinkedList()
  {
    Node *cur = head;
    while (cur != nullptr)
    {
      Node *temp = cur;
      cur = cur->next;
      delete temp;
    }
  }
};

int main()
{
  LinkedList list;

  cout << "===== 测试尾插法 =====" << endl;
  list.insertAtTail(1);
  list.insertAtTail(2);
  list.insertAtTail(3);
  list.print();

  cout << "===== 测试头插法 =====" << endl;
  list.insertAtHead(0);
  list.print();

  cout << "===== 测试查找 =====" << endl;
  cout << "是否存在2:" << (list.contains(2) ? "是" : "否") << endl;
  cout << "是否存在5:" << (list.contains(5) ? "是" : "否") << endl;

  cout << "===== 测试删除 =====" << endl;
  list.deleteNode(2);
  list.print();
  list.deleteNode(0);
  list.print();

  cout << "===== 所有测试完成 =====" << endl;
  return 0;
}