/*
* Copyright 2014.215B������
* All rights reserved.
*
* �ļ����ƣ�Trie.h
* ժ	Ҫ���ֵ����������
*
* ��ǰ�汾��1.1
* ��	��: chendaxixi/���ٱ�
* ������ڣ�2014��11��17��
*
* ȡ���汾��1.1
* ԭ����  ��chendaxixi/���ٱ�
* ������ڣ�2014��11��17��
*/

#ifndef TRIE_H
#define TRIE_H

#include "CharStringLink.h"

//�ʵ���
class Trie
{
public:
	Trie(WCHAR c = 0):m_data(c), m_child(NULL), m_brother(NULL), m_word(NULL){
	}
	~Trie()
	{
		if(m_child != NULL)
			delete m_child;
		if(m_brother != NULL)
			delete m_brother;
	}
public:
	//����c����
	Trie* Find(WCHAR c)
	{
		Trie* tree = m_child;
		while(tree != NULL)
		{
			if(tree->m_data == c)
				return tree;
			tree = tree->m_brother;
		}
		return tree;
	}
	//����str��index����Ӵ�
	void Insert(CharString* str, int index)
	{
		if(str == NULL) return;
		if(str->Length() == 0) return;
		if(index == str->Length()-1)
		{
			m_word = str;
			return;
		}
		Trie* tree = Find(str->m_wbody[index]);
		if(tree == NULL)
		{
			tree = new Trie(str->m_wbody[index]);
			if(m_child == NULL)
				m_child = tree;
			else
			{
				tree->m_brother = m_child->m_brother;
				m_child->m_brother = tree;
			}
		}
		tree->Insert(str, index+1);
	}
	//��dic�����д�����
	void Build(CharStringLink* dic)
	{
		if(dic == NULL) return;
		CharStringLink* temp = dic;
		Insert(temp->m_body, 0);
		temp = temp->m_next;
		while(temp != dic)
		{
			Insert(temp->m_body, 0);
			temp = temp->m_next;
		}
	}
	//������s��ͷ�������
	CharString* FindWord(WCHAR* &s)
	{
		if(s == NULL) return NULL;
		Trie* tree1 = NULL;
		Trie* tree2 = NULL;
		WCHAR* sBegin = s;
		tree1 = this;
		tree2 = tree1->Find(*s);
		while(tree2 != NULL)
		{
			tree1 = tree2;
			s++;
			tree2 = tree1->Find(*s);
		}
		if(tree1->m_word != NULL)
			return tree1->m_word;
		s = sBegin;
		return NULL;
	}
public:
	WCHAR m_data;	//��ֵ
	Trie* m_child;	//����
	Trie* m_brother;	//ͬ���ֵ���
	CharString* m_word;	//Ҷ�ڵ��Ӧ���ַ���
};

#endif