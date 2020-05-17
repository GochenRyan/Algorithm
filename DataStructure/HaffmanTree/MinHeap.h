/**
 * ��С�ѣ�ΪHuffman������ġ�
 *
 * @author skywang
 * @date 2014/03/25
 */

#ifndef _HUFFMAN_MIN_HEAP_HPP_
#define _HUFFMAN_MIN_HEAP_HPP_

#include "HuffmanNode.h"

template <class T>
class MinHeap {
	private:
		HuffmanNode<T> *mHeap;	// ��С�ѵ�����
		int mCapacity;			// �ܵ�����
		int mSize;				// ��ǰ��Ч���ݵ�����
	private:
		// �ϵ��㷨
		void filterUp(int start);
		// �µ��㷨
		void filterDown(int start, int end);
		// ��������HuffmanNode�ڵ��ȫ�����ݣ�i��j�ǽڵ�������
		void swapNode(int i, int j);
	public:
		MinHeap();
	    ~MinHeap();

        // ��node��ȫ�����ݿ�����"��С�ѵ�ָ���ڵ�"
		int copyOf(HuffmanNode<T> *node);
		// ��ȡ��С�ڵ�
		HuffmanNode<T>* dumpFromMinimum();
		// ������С��
		void create(T a[], int size);
		// ������С��
		void destroy();
};


template <class T>
MinHeap<T>::MinHeap()
{
}

template <class T>
MinHeap<T>::~MinHeap()
{
	destroy();
}

/*
 * ��С�ѵ����µ����㷨
 *
 * ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
 *
 * ����˵����
 *     start -- ���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ)
 *     end   -- ������Χ(һ��Ϊ���������һ��Ԫ�ص�����)
 */
template <class T>
void MinHeap<T>::filterDown(int start, int end)
{
    int c = start; 	 	// ��ǰ(current)�ڵ��λ��
    int l = 2*c + 1; 	// ��(left)���ӵ�λ��
    HuffmanNode<T> tmp = mHeap[c];	// ��ǰ(current)�ڵ�

    while(l <= end)
    {
		// "l"�����ӣ�"l+1"���Һ���
        if(l < end && mHeap[l].key > mHeap[l+1].key)
            l++;		// ������������ѡ���С�ߣ���mHeap[l+1]
        if(tmp.key <= mHeap[l].key)
            break;		//��������
        else
        {
            mHeap[c] = mHeap[l];
            c = l;
            l = 2*l + 1;
        }
    }
    mHeap[c] = tmp;
}

/*
 * ��С�ѵ����ϵ����㷨(��start��ʼ����ֱ��0��������)
 *
 * ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
 *
 * ����˵����
 *     start -- ���ϵ��ڵ����ʼλ��(һ��Ϊ���������һ��Ԫ�ص�����)
 */
template <class T>
void MinHeap<T>::filterUp(int start)
{
    int c = start;			// ��ǰ�ڵ�(current)��λ��
    int p = (c-1)/2;		// ��(parent)����λ��
    HuffmanNode<T> tmp = mHeap[c];		// ��ǰ�ڵ�(current)

    while(c > 0)
    {
        if(mHeap[p].key <= tmp.key)
            break;
        else
        {
            mHeap[c] = mHeap[p];
            c = p;
            p = (p-1)/2;
        }
    }
    mHeap[c] = tmp;
}

/*
 * ��node��ȫ�����ݿ�����"��С�ѵ�ָ���ڵ�"
 *
 * ����ֵ��
 *     0����ʾ�ɹ�
 *    -1����ʾʧ��
 */
template <class T>
int MinHeap<T>::copyOf(HuffmanNode<T> *node)
{
    // ���"��"�������򷵻�
    if(mSize == mCapacity)
        return -1;

    mHeap[mSize] = *node;   // ��"node������"ȫ�����Ƶ�"����ĩβ"
    filterUp(mSize);		// ���ϵ�����
    mSize++;				// �ѵ�ʵ������+1

    return 0;
}

/*
 * ��������HuffmanNode�ڵ��ȫ������
 */
template <class T>
void MinHeap<T>::swapNode(int i, int j)
{
	HuffmanNode<T> tmp = mHeap[i];
	mHeap[i] = mHeap[j];
	mHeap[j] = tmp;
}

/*
 * �½�һ���ڵ㣬������С������С�ڵ�����ݸ��Ƹ��ýڵ㡣
 * Ȼ�����С�ڵ�֮����������¹������С�ѡ�
 *
 * ����ֵ��
 *     ʧ�ܷ���NULL��
 */
template <class T>
HuffmanNode<T>* MinHeap<T>::dumpFromMinimum()
{
    // ���"��"�ѿգ��򷵻�
    if(mSize == 0)
		return NULL;

	HuffmanNode<T> *node;
    if((node = new HuffmanNode<T>()) == NULL)
		return NULL;

	// ��"��С�ڵ��ȫ������"���Ƹ�node
	*node = mHeap[0];

	swapNode(0, mSize-1);				// ����"��С�ڵ�"��"���һ���ڵ�"
    filterDown(0, mSize-2);	// ��mHeap[0...mSize-2]�����һ����С��
	mSize--;

	return node;
}

/*
 * ������С��
 *
 * ����˵����
 *     a -- �������ڵ�����
 *     size -- �����С
 */
template <class T>
void MinHeap<T>::create(T a[], int size)
{
	int i;

	// ������С������Ӧ������
	mSize = size;
	mCapacity = size;
	mHeap = new HuffmanNode<T>[size];

	// ��ʼ������
    for(i=0; i<size; i++)
	{
		mHeap[i].key = a[i];
		mHeap[i].parent = mHeap[i].left = mHeap[i].right = NULL;
	}

    // ��(size/2-1) --> 0��α���������֮�󣬵õ�������ʵ������һ����С�ѡ�
    for (i = size / 2 - 1; i >= 0; i--)
		filterDown(i, size-1);
}

// ������С��
template <class T>
void MinHeap<T>::destroy()
{
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
	mHeap = NULL;
}
#endif
