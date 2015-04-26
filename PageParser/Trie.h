/*
* Copyright 2014.215B工作室
* All rights reserved.
*
* 文件名称：Trie.h
* 摘	要：字典树类的声明
*
* 当前版本：1.1
* 作	者: chendaxixi/陈少滨
* 完成日期：2014年11月17日
*
* 取代版本：1.1
* 原作者  ：chendaxixi/陈少滨
* 完成日期：2014年11月17日
*/

#ifndef TRIE_H
#define TRIE_H

#include "CharStringLink.h"

//词典树
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
	//查找c子树
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
	//插入str从index起的子串
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
	//从dic链表中创建树
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
	//查找以s开头的最长单词
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
	WCHAR m_data;	//数值
	Trie* m_child;	//子树
	Trie* m_brother;	//同层兄弟树
	CharString* m_word;	//叶节点对应的字符串
};

#endif