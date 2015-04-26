/*
* Copyright 2014.215B工作室
* All rights reserved.
*
* 文件名称：CharStringLink.h
* 摘	要：字符串链表类的声明
*
* 当前版本：1.0
* 作	者: chendaxixi/陈少滨
* 完成日期：2014年11月16日
*
* 取代版本：1.0
* 原作者  ：chendaxixi/陈少滨
* 完成日期：2014年11月16日
*/

#ifndef CHARSTRINGLINK_H
#define CHARSTRINGLINK_H

#include "CharString.h"

//双向循环链表
class CharStringLink
{
public:
	CharStringLink():m_body(NULL), m_next(NULL), m_pre(NULL){
	}
	CharStringLink(CharString* str):m_next(this), m_pre(this), m_body(str){
	}
	~CharStringLink()
	{
		if(m_pre == NULL) return;
		m_pre->m_next = NULL;
		if(m_next != NULL)
			delete m_next;
	}
public:
	//插入字符串
	void Insert(CharString* str)
	{
		if(m_next == NULL)
		{
			m_body = str;
			m_next = this;
			m_pre = this;
			return;
		}
		CharStringLink* p = new CharStringLink(str);
		p->m_next = this;
		p->m_pre = m_pre;
		m_pre->m_next = p;
		m_pre = p;
	}
	//查找字符串
	CharStringLink* Find(CharString& str)
	{
		if(m_body == NULL) return NULL;
		CharStringLink* temp = this;
		if(*(temp->m_body) == str)
			return temp;
		temp = temp->m_next;
		while(temp != this)
		{
			if(*(temp->m_body) == str)
				return temp;
			temp = temp->m_next;
		}
		return NULL;
	}
	//删除该节点
	void Delete()
	{
		if(m_next == this)
		{
			m_body = NULL;
			m_next = NULL;
			m_pre = NULL;
		}
		else
		{
			m_pre->m_next = m_next;
			m_next->m_pre = m_pre;
			m_next = NULL;
			m_pre = NULL;
			delete this;
		}
	}
	//释放链表内的字符串的内存
	void Destroy()
	{
		if(m_body == NULL) return;
		CharStringLink* temp = this;
		delete m_body;
		temp = temp->m_next;
		while(temp != this)
		{
			delete temp->m_body;
			temp = temp->m_next;
		}
	}
public:
	CharString* m_body;	//所表示的字符串
	CharStringLink* m_next;	//Next指针
	CharStringLink* m_pre;	//Pre指针
};

#endif