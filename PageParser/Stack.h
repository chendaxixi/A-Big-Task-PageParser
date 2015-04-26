/*
* Copyright 2014.215B������
* All rights reserved.
*
* �ļ����ƣ�Stack.h
* ժ	Ҫ��ջ�������
*
* ��ǰ�汾��1.0
* ��	��: chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*
* ȡ���汾��1.0
* ԭ����  ��chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*/

#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;

template<class T>
class StackNode
{
public:
	class StackNode(T data):m_data(data), m_next(NULL), m_pre(NULL){
	}
public:
	T m_data;
	StackNode* m_next;
	StackNode* m_pre;
};

template<class T>
class Stack
{
public:
	Stack():m_bottom(NULL), m_top(NULL), m_size(0){
	}
public:
	//��ջ
	void Push(T data)
	{
		StackNode<T>* temp = new StackNode<T>(data);
		if(m_size == 0)
		{
			m_size++;
			m_bottom = temp;
			m_top = temp;
		}
		else
		{
			temp->m_pre = m_top;
			m_top->m_next = temp;
			m_top = temp;
			m_size++;
		}
	}
	//��ջ
	void Pop()
	{
		if(m_size == 0) return;
		if(m_size == 1)
		{
			delete m_top;
			m_size = 0;
			m_bottom = NULL;
			m_top = NULL;
		}
		else
		{
			m_size--;
			m_top = m_top->m_pre;
			delete m_top->m_next;
			m_top->m_next = NULL;
		}
	}
	//�ж�ջ�Ƿ��
	bool empty()
	{
		if(m_size == 0) return true;
		return false;
	}
	//����ջ��Ԫ��
	T Peek()
	{
		return m_top->m_data;
	}
	//����data��ջ��λ�ã�-1��ʾû�У�ջ��Ϊ0
	int indexOf(T data)
	{
		int pos = 0;
		StackNode<T>* temp = m_bottom;
		while(temp != NULL)
		{
			if(temp->m_data == T)
				return pos;
			pos++;
			temp = temp->m_next;
		}
		return -1;
	}
	//ջ��С
	int Size()
	{
		return m_size;
	}

private:
	StackNode<T>* m_bottom;	//ջ��
	StackNode<T>* m_top;	//ջ��
	int m_size;	//ջ��С
};

#endif