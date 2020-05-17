#include <iostream>
#include <stdio.h>

using namespace std;

bool judgePri(char ope1,char ope2){
    if((ope1=='*' || ope1=='/') && (ope2=='+' || ope2=='-')) return true;
    else return false;
}

class BinaryTree;
class BinaryTreeNode{
    friend class BinaryTree;
protected:
    char data;
    BinaryTreeNode *leftTree;
    BinaryTreeNode *rightTree;
public:
    BinaryTreeNode():leftTree(NULL),rightTree(NULL){}
    BinaryTreeNode(char xdata,BinaryTreeNode *xleftTree=NULL,BinaryTreeNode *xrightTree=NULL){
        data=xdata;
        leftTree=xleftTree;
        rightTree=xrightTree;
    }
    ~BinaryTreeNode(){}
};

class BinaryTree{
private:
    BinaryTreeNode *root;
    void createBinaryTree(BinaryTreeNode *&subTree);
    void destroy(BinaryTreeNode *&subTree);
    void inOrder(BinaryTreeNode *subTree);
    int calculate(BinaryTreeNode *subTree);
public:
    BinaryTree():root(NULL){}
    ~BinaryTree(){destroy(root);}
    void createBinaryTree(){createBinaryTree(root);}
    void inOrder(){inOrder(root);}
    int calculate(){return calculate(root);}
};

void BinaryTree::createBinaryTree(BinaryTreeNode *&subTree){
    char item;
    cin>>item;
    if(item!='@'){
        subTree=new BinaryTreeNode(item);
        createBinaryTree(subTree->leftTree);
        createBinaryTree(subTree->rightTree);
    }
    else subTree=NULL;
}

void BinaryTree::destroy(BinaryTreeNode *&subTree){
    if(subTree!=NULL){
        destroy(subTree->leftTree);
        destroy(subTree->rightTree);
        delete subTree;
    }
}

void BinaryTree::inOrder(BinaryTreeNode *subTree){
    if(subTree!=NULL){
        if(subTree->rightTree!=NULL && judgePri(subTree->data,subTree->rightTree->data)){
            inOrder(subTree->leftTree);
            cout<<subTree->data;
            cout<<'(';
            inOrder(subTree->rightTree);
            cout<<')';
        }
        else{
        inOrder(subTree->leftTree);
        cout<<subTree->data;
        inOrder(subTree->rightTree);
        }
    }
}

int BinaryTree::calculate(BinaryTreeNode *subTree){
    if(subTree!=NULL){
        if(subTree->data=='+'){
            return calculate(subTree->leftTree)+calculate(subTree->rightTree);
        }
        else if(subTree->data=='-'){
            return calculate(subTree->leftTree)-calculate(subTree->rightTree);
        }
        else if(subTree->data=='*'){
            return calculate(subTree->leftTree)*calculate(subTree->rightTree);
        }
        else if(subTree->data=='/'){
            return calculate(subTree->leftTree)/calculate(subTree->rightTree);
        }
        else {
            return int(subTree->data-'0');
        }
    }
}

int main()
{
    BinaryTree tree;
  //  freopen("data.txt","r",stdin);
    tree.createBinaryTree();
    tree.inOrder();
    cout<<'='<<tree.calculate()<<endl;
    return 0;
}
