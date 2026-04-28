#include <iostream>
using namespace std;

class CircularQueue
{
private:
  static const int MAX = 5; // 故意设小，方便测试判满
  int arr[MAX];
  int front; // 队首下标
  int rear;  // 队尾下标（指向下一个可插入位置)
  int count; // 当前元素个数

public:
  CircularQueue() : front(0), rear(0), count(0) {}

  // 入队
  void enqueue(int val)
  {
    if (isFull())
    {
      cout << "队列已满，无法入队元素" << val << endl;
      return;
    }
    arr[rear] = val;
    rear = (rear + 1) % MAX;
    count++;
    cout << "入队:" << val << endl;
  }

  // 出队
  void dequeue()
  {
    if (isEmpty())
    {
      cout << "队列为空，无法出队" << endl;
      return;
    }
    int val = arr[front];
    front = (front + 1) % MAX;
    count--;
    cout << "出队:" << val << endl;
  }

  // 获取队首元素
  int getFront()
  {
    if (isEmpty())
    {
      cout << "队列为空" << endl;
      return -1;
    }
    return arr[front];
  }

  // 判空
  bool isEmpty()
  {
    return count == 0;
  }

  // 判满
  bool isFull()
  {
    return count == MAX;
  }

  // 获取当前元素个数
  int size()
  {
    return count;
  }

  // 打印队列内容
  void print()
  {
    if (isEmpty())
    {
      cout << "队列为空" << endl;
      return;
    }
    cout << "队列内容（从队首到队尾）:";
    for (int i = 0; i < count; i++)
    {
      int index = (front + i) % MAX;
      cout << arr[index];
      if (i < count - 1)
        cout << "->";
    }
    cout << endl;
  }
};

int main()
{
  CircularQueue q;

  cout << "===== 测试入队 =====" << endl;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);
  q.enqueue(60); // 应该提示队列已满
  q.print();

  cout << "队首元素:" << q.getFront() << endl;
  cout << "当前大小:" << q.size() << endl;

  cout << "===== 测试出队 =====" << endl;
  q.dequeue();
  q.dequeue();
  q.print();

  cout << "===== 测试循环写入 =====" << endl;
  q.enqueue(70);
  q.enqueue(80);
  q.print();

  cout << "===== 全部出队 =====" << endl;
  while (!q.isEmpty())
  {
    q.dequeue();
  }
  q.dequeue(); // 应该提示队列为空

  cout << "===== 所有测试完成 =====" << endl;
  return 0;
}