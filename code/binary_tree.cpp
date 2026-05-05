#include <iostream>
using namespace std;

// 二叉树节点定义
struct TreeNode
{
  int val;         // 节点存储的值
  TreeNode *left;  // 指向左子节点的指针
  TreeNode *right; // 指向右子节点的指针

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 前序遍历:根->左->右
void preorder(TreeNode *root)
{
  if (root == nullptr)
    return;
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}

// 中序遍历:左->根->右
void inorder(TreeNode *root)
{
  if (root == nullptr)
    return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

// 后序遍历:左->右->根
void postorder(TreeNode *root)
{
  if (root == nullptr)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
}

int main()
{
  // 构建示例树
  //         1
  //        /   \
  //     2     3
  //      / \      \
  //   4   5      6
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "前序遍历（根→左→右）：";
  preorder(root);
  cout << endl
       << "期望：1 2 4 5 3 6" << endl
       << endl;

  cout << "中序遍历（左→根→右）：";
  inorder(root);
  cout << endl
       << "期望：4 2 5 1 3 6" << endl
       << endl;

  cout << "后序遍历（左→右→根）：";
  postorder(root);
  cout << endl
       << "期望：4 5 2 6 3 1" << endl
       << endl;

  // 释放内存
  delete root->left->left;
  delete root->left->right;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  cout << "===== 所有测试完成 =====" << endl;
  return 0;
}