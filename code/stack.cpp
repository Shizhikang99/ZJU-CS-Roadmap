#include <iostream>
using namespace std;

class Stack
{
private:
  static const int MAX = 100;
  int arr[MAX];
  int topIndex;

public:
  Stack() : topIndex(-1) {}

  void push(int val)
  {
    if (topIndex >= MAX - 1)
    {
      cout << "栈已满，无法压入" << endl;
      return;
    }
    arr[++topIndex] = val;
  }

  void pop()
  {
    if (isEmpty())
    {
      cout << "栈为空，无法弹出" << endl;
      return;
    }
    topIndex--;
  }

  int top()
  {
    if (isEmpty())
    {
      cout << "栈为空" << endl;
      return -1;
    }
    return arr[topIndex];
  }

  bool isEmpty()
  {
    return topIndex == -1;
  }

  int size()
  {
    return topIndex + 1;
  }

  void print()
  {
    if (isEmpty())
    {
      cout << "栈为空" << endl;
      return;
    }
    cout << "栈内容（从栈底到栈顶）：";
    for (int i = 0; i <= topIndex; i++)
    {
      cout << arr[i];
      if (i < topIndex)
        cout << " -> ";
    }
    cout << endl;
  }
};

int main()
{
  Stack s;

  cout << "===== 测试压入 =====" << endl;
  s.push(10);
  s.push(20);
  s.push(30);
  s.print();

  cout << "栈顶元素：" << s.top() << endl;
  cout << "栈大小：" << s.size() << endl;

  cout << "===== 测试弹出 =====" << endl;
  s.pop();
  s.print();
  cout << "栈顶元素：" << s.top() << endl;

  cout << "===== 测试判空 =====" << endl;
  cout << "是否为空：" << (s.isEmpty() ? "是" : "否") << endl;

  s.pop();
  s.pop();
  cout << "全部弹出后，是否为空：" << (s.isEmpty() ? "是" : "否") << endl;

  s.pop(); // 尝试从空栈弹出

  cout << "===== 所有测试完成 =====" << endl;
  return 0;
}