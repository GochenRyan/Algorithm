#include <iostream>
#include <stack>
#include <iomanip>
#include <stdio.h>

using namespace std;

const int maxLength=100;

class BinaryTree;
class BinaryTreeNode
{
    friend class BinaryTree;
protected:
    char data;
    BinaryTreeNode *leftChild;
    BinaryTreeNode *rightChild;
public:
    BinaryTreeNode()
    {
       leftChild=NULL;
       rightChild=NULL;
    }
    BinaryTreeNode(char xdata,BinaryTreeNode *xleftChild=NULL,BinaryTreeNode *xrightChild=NULL)
    {
        data=xdata;
        leftChild=xleftChild;
        rightChild=xrightChild;
    }
    ~BinaryTreeNode(){}
};

class BinaryTree
{
public:
    BinaryTree():root(NULL){}
    ~BinaryTree(){destroy(root);}
    void createBinaryTree(){createBinaryTree(root);}
    bool isEmpty(){return (root==NULL)? true:false;}
    int getHeight(){return getHeight(root);}
    int getSize(){return getSize(root);}
    int getLeafSize(){return getLeafSize(root);}
    void perOrder(){perOrder(root);}
    void inOrder(){inOrder(root);}
    void postOrder(){postOrder(root);}
    int searchValue(char val){return searchValue(val,root);}
    void output();
private:
    BinaryTreeNode *root;
    void destroy(BinaryTreeNode *&subTree);
    void createBinaryTree(BinaryTreeNode *&subTree);
    int getHeight(BinaryTreeNode *subTree);
    int getSize(BinaryTreeNode *subTree);
    int getLeafSize(BinaryTreeNode *subTree);
    void perOrder(BinaryTreeNode *subTree);
    void inOrder(BinaryTreeNode *subTree);
    void postOrder(BinaryTreeNode *subTree);
    int searchValue(char val,BinaryTreeNode *subTree);
};

void BinaryTree::destroy(BinaryTreeNode *&subTree){
    if(subTree!=NULL){
        destroy(subTree->leftChild);
        destroy(subTree->rightChild);
        delete subTree;
    }
}

void BinaryTree::createBinaryTree(BinaryTreeNode *&subTree){
    char item;
    cin>> item;
	if (item != '#') {
		subTree = new BinaryTreeNode (item);
		createBinaryTree( subTree->leftChild);
		createBinaryTree( subTree->rightChild);
	}
	else subTree = NULL;
}

//返回树深度
int BinaryTree::getHeight(BinaryTreeNode *subTree){
    if(subTree==NULL) return 0;
    else return 1+max(getHeight(subTree->leftChild),getHeight(subTree->rightChild));
}

//返回节点个数
int BinaryTree::getSize(BinaryTreeNode *subTree){
    if(subTree==NULL) return 0;
    else return 1+getSize(subTree->leftChild)+getSize(subTree->rightChild);
}

//返回树节点个数
int BinaryTree::getLeafSize(BinaryTreeNode *subTree){
    if(subTree==NULL) return 0;
    if(subTree->leftChild==NULL && subTree->rightChild==NULL) return 1;
    int counter=getLeafSize(subTree->leftChild)+getLeafSize(subTree->rightChild);
    return counter;
}

//先序遍历
void BinaryTree::perOrder(BinaryTreeNode *subTree){
    if(subTree!=NULL){
        cout<<subTree->data<<' ';
        perOrder(subTree->leftChild);
        perOrder(subTree->rightChild);
    }
}

//中序遍历
void BinaryTree::inOrder(BinaryTreeNode *subTree){
    if(subTree!=NULL){
        inOrder(subTree->leftChild);
        cout<<subTree->data<<' ';
        inOrder(subTree->rightChild);
    }
}

//后序遍历
void BinaryTree::postOrder(BinaryTreeNode *subTree){
    if(subTree!=NULL){
        postOrder(subTree->leftChild);
        postOrder(subTree->rightChild);
        cout<<subTree->data<<' ';
    }
}

int BinaryTree::searchValue(char val,BinaryTreeNode *subTree){
    if(subTree==NULL) return 0;
    if(subTree->data==val) return 1;
    int counter=searchValue(val,subTree->leftChild)+searchValue(val,subTree->rightChild);
    return counter;
}


//以缩格文本形式输出所有节点
void BinaryTree::output(){
    stack<BinaryTreeNode*> S;
    BinaryTreeNode *p=root;
    int counter=1;
    int label=0;
    cout<<"The tree is:"<<endl;
    while(p!=NULL){
        cout<<setw(counter)<<setfill(' ');
        if(label==1){
            cout<<setw(counter+2)<<setfill(' ');
            label=0;
        }
        cout<<p->data<<endl;
        if(p->leftChild==NULL && p->rightChild==NULL && S.empty()) return;
        if(p->rightChild!=NULL)  S.push(p->rightChild);
        if(p->leftChild!=NULL){
            p=p->leftChild;
            counter+=2;
        }
        else{
            p=S.top();
            S.pop();
            if(!S.empty()) label=1;
        }
    }
}

int main()
{
    char select;
//    freopen("data.txt","r",stdin);
    BinaryTree tree;
    while(cin>>select){
        switch(select){
            case 'C': {
                      tree.createBinaryTree();
                      cout<<"Created success!"<<endl;
                      break;
            }
            case 'H': {
                      cout<<"Height="<<tree.getHeight()<<'.'<<endl;
                      break;
            }
            case 'L': {
                      cout<<"Leaf="<<tree.getLeafSize()<<'.'<<endl;
                      break;
            }
            case 'N': {
                      cout<<"Nodes="<<tree.getSize()<<'.'<<endl;
                      break;
            }
            case '1': {
                      cout<<"Preorder is:";
                      tree.perOrder();
                      cout<<'.'<<endl;
                      break;
            }
            case '2': {
                      cout<<"Inorder is:";
                      tree.inOrder();
                      cout<<'.'<<endl;
                      break;
            }
            case '3': {
                      cout<<"Postorder is:";
                      tree.postOrder();
                      cout<<'.'<<endl;
                      break;
            }
            case 'F': {
                      char val;
                      cin>>val;
                      cout<<"The count of "<<val<<' '<<"is "<<tree.searchValue(val)<<'.'<<endl;
                      break;
            }
            case 'P': {
                tree.output();
                      break;
            }
        }
    }
    return 0;
}
