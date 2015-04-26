/*
* Copyright 2014.215B工作室
* All rights reserved.
*
* 文件名称：Stack.h
* 摘	要：栈类的声明
*
* 当前版本：1.0
* 作	者: chendaxixi/陈少滨
* 完成日期：2014年11月16日
*
* 取代版本：1.0
* 原作者  ：chendaxixi/陈少滨
* 完成日期：2014年11月16日
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
	//入栈
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
	//出栈
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
	//判断栈是否空
	bool empty()
	{
		if(m_size == 0) return true;
		return false;
	}
	//返回栈顶元素
	T Peek()
	{
		return m_top->m_data;
	}
	//查找data在栈中位置，-1表示没有，栈底为0
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
	//栈大小
	int Size()
	{
		return m_size;
	}

private:
	StackNode<T>* m_bottom;	//栈底
	StackNode<T>* m_top;	//栈顶
	int m_size;	//栈大小
};

#endif