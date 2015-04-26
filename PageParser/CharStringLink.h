/*
* Copyright 2014.215B������
* All rights reserved.
*
* �ļ����ƣ�CharStringLink.h
* ժ	Ҫ���ַ��������������
*
* ��ǰ�汾��1.0
* ��	��: chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*
* ȡ���汾��1.0
* ԭ����  ��chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*/

#ifndef CHARSTRINGLINK_H
#define CHARSTRINGLINK_H

#include "CharString.h"

//˫��ѭ������
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
	//�����ַ���
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
	//�����ַ���
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
	//ɾ���ýڵ�
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
	//�ͷ������ڵ��ַ������ڴ�
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
	CharString* m_body;	//����ʾ���ַ���
	CharStringLink* m_next;	//Nextָ��
	CharStringLink* m_pre;	//Preָ��
};

#endif