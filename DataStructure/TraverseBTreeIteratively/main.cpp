/*
    前、中、后序遍历二叉树的非递归方式实现
*/

#include <iostream>
#include <stack>

typedef struct node
{
    int data;
    struct node *lChild;
    struct node *rChild;
}BTNode;

class BinaryTree
{
public:
    BinaryTree():root(nullptr){}
    ~BinaryTree(){destroyTree(root);}
    void createBinaryTree(){createBinaryTree(root);}
    void preOrder();
    void inOreder();
    void postOrder();
private:
    BTNode *root;
    void destroyTree(BTNode *&node);
    void createBinaryTree(BTNode *&node);
};

void BinaryTree::createBinaryTree(BTNode *&node)
{
    int value;
    std::cin >> value;
    if (value != -1)
    {
        node = new BTNode();
        node->data = value;
        createBinaryTree(node->lChild);
        createBinaryTree(node->rChild);
    }
    else
    {
        node = nullptr;
    }
}

void BinaryTree::destroyTree(BTNode *&node)
{
    if (node != nullptr)
    {
        destroyTree(node->lChild);
        destroyTree(node->rChild);
        delete node;
    }
}

// 前序遍历（非递归）
void BinaryTree::preOrder()
{
    if (root == nullptr) return;
    if (root->lChild == nullptr && root->rChild == nullptr) return;
    std::stack<BTNode*> s;
    BTNode *pNode = root;
    while(!s.empty() || pNode)
    {
        if (pNode)
        {
            std::cout << pNode->data << ' ';
            s.push(pNode);
            pNode = pNode->lChild;
        }
        else
        {
            pNode = s.top();
            s.pop();
            pNode = pNode->rChild;
        }
    }
    std::cout << std::endl;
}

// 中序遍历（非递归）
void BinaryTree::inOreder()
{
    if (root == nullptr) return;
    if (root->lChild == nullptr && root->rChild == nullptr) return;
    std::stack<BTNode*> s;
    BTNode *pNode = root;
    while(!s.empty() || pNode)
    {
        if (pNode)
        {
            s.push(pNode);
            pNode = pNode->lChild;
        }
        else
        {
            pNode = s.top();
            s.pop();
            std::cout << pNode->data << ' ';
            pNode = pNode->rChild;
        }
    }
    std::cout << std::endl;
}

// 后序遍历（非递归）
void BinaryTree::postOrder()
{
    if (root == nullptr) return;
    if (root->lChild == nullptr && root->rChild == nullptr) return;
    std::stack<BTNode*> s;
    BTNode *pNode = root;
    BTNode *pLastVisit = nullptr;
    while (pNode)
    {
        s.push(pNode);
        pNode = pNode->lChild;
    }
    while(!s.empty())
    {
        pNode = s.top();
        // 一个根节点被访问的前提是：无右子树或右子树已被访问过
        if (pNode->rChild == nullptr || pNode->rChild == pLastVisit)
        {
            s.pop();
            std::cout << pNode->data << ' ';
            pLastVisit = pNode;
        }
        else
        {
            pNode = pNode->rChild;
            while (pNode)
            {
                s.push(pNode);
                pNode = pNode->lChild;
            }
        }
    }
    std::cout << std::endl;
}

int main()
{
    freopen("in.txt", "r", stdin);
    BinaryTree binaryTree;
    binaryTree.createBinaryTree();
    std::cout << "preOrder: ";
    binaryTree.preOrder();
    std::cout << "inOreder: ";
    binaryTree.inOreder();
    std::cout << "postOreder: ";
    binaryTree.postOrder();
    fclose(stdin);
    return 0;
}

