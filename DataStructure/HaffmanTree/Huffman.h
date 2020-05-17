/**
 * C++ʵ�ֵ�Huffman����
 *
 * ����Huffman��ʱ��ʹ�õ�����С�ѡ�
 *
 * @author skywang
 * @date 2014/03/25
 */

#ifndef _HUFFMAN_TREE_HPP_
#define _HUFFMAN_TREE_HPP_

#include <iomanip>
#include <iostream>
#include "HuffmanNode.h"
#include "MinHeap.h"
using namespace std;

template <class T>
class Huffman {
	private:
		HuffmanNode<T> *mRoot;	// �����

    public:
		Huffman();
		~Huffman();

		// ǰ�����"Huffman��"
		void preOrder();
		// �������"Huffman��"
		void inOrder();
		// �������"Huffman��"
		void postOrder();

		// ����Huffman��
		void create(T a[], int size);
		// ����Huffman��
		void destroy();

		// ��ӡHuffman��
		void print();
	private:
		// ǰ�����"Huffman��"
		void preOrder(HuffmanNode<T>* tree) const;
		// �������"Huffman��"
		void inOrder(HuffmanNode<T>* tree) const;
		// �������"Huffman��"
		void postOrder(HuffmanNode<T>* tree) const;

		// ����Huffman��
		void destroy(HuffmanNode<T>* &tree);

		// ��ӡHuffman��
		void print(HuffmanNode<T>* tree, T key, int direction);
};

/*
 * ���캯��
 */
template <class T>
Huffman<T>::Huffman():mRoot(NULL)
{
}

/*
 * ��������
 */
template <class T>
Huffman<T>::~Huffman()
{
	destroy();
}

/*
 * ǰ�����"Huffman��"
 */
template <class T>
void Huffman<T>::preOrder(HuffmanNode<T>* tree) const
{
	if(tree != NULL)
	{
		cout<< tree->key << " " ;
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template <class T>
void Huffman<T>::preOrder()
{
	preOrder(mRoot);
}

/*
 * �������"Huffman��"
 */
template <class T>
void Huffman<T>::inOrder(HuffmanNode<T>* tree) const
{
	if(tree != NULL)
	{
		inOrder(tree->left);
		cout<< tree->key << " " ;
		inOrder(tree->right);
	}
}

template <class T>
void Huffman<T>::inOrder()
{
	inOrder(mRoot);
}

/*
 * �������"Huffman��"
 */
template <class T>
void Huffman<T>::postOrder(HuffmanNode<T>* tree) const
{
	if(tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout<< tree->key << " " ;
	}
}

template <class T>
void Huffman<T>::postOrder()
{
	postOrder(mRoot);
}

/*
 * ����Huffman��
 *
 * ����˵����
 *     a Ȩֵ����
 *     size �����С
 *
 * ����ֵ��
 *     Huffman���ĸ��ڵ�
 */
template <class T>
void Huffman<T>::create(T a[], int size)
{
    int i;
    HuffmanNode<T> *left, *right, *parent;
	MinHeap<T> *heap = new MinHeap<T>();

	// ��������a��Ӧ����С��
    heap->create(a, size);

    for(i=0; i<size-1; i++)
    {
        left = heap->dumpFromMinimum();  // ��С�ڵ�������
        right = heap->dumpFromMinimum(); // ��β����Һ���

		// �½�parent�ڵ㣬���Һ��ӷֱ���left/right��
		// parent�Ĵ�С�����Һ���֮��
        parent = new HuffmanNode<T>(left->key+right->key, left, right, NULL);
        left->parent = parent;
		right->parent = parent;


		// ��parent�ڵ����ݿ�����"��С��"��
		if (heap->copyOf(parent)!=0)
		{
			cout << "����ʧ��!" << endl << "��������" << endl;
			destroy(parent);
			parent = NULL;
			break;
		}
    }

	mRoot = parent;

	// ������С��
	heap->destroy();
	delete heap;
}

/*
 * ����Huffman��
 */
template <class T>
void Huffman<T>::destroy(HuffmanNode<T>* &tree)
{
	if (tree==NULL)
		return ;

	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;
	tree=NULL;
}

template <class T>
void Huffman<T>::destroy()
{
	destroy(mRoot);
}

/*
 * ��ӡ"Huffman��"
 *
 * key        -- �ڵ�ļ�ֵ
 * direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
 *               -1����ʾ�ýڵ������ĸ���������;
 *                1����ʾ�ýڵ������ĸ������Һ��ӡ�
 */
template <class T>
void Huffman<T>::print(HuffmanNode<T>* tree, T key, int direction)
{
	if(tree != NULL)
	{
		if(direction==0)	// tree�Ǹ��ڵ�
			cout << setw(2) << tree->key << " is root" << endl;
		else				// tree�Ƿ�֧�ڵ�
			cout << setw(2) << tree->key << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << endl;

		print(tree->left, tree->key, -1);
		print(tree->right,tree->key,  1);
	}
}

template <class T>
void Huffman<T>::print()
{
	if (mRoot != NULL)
		print(mRoot, mRoot->key, 0);
}

#endif
