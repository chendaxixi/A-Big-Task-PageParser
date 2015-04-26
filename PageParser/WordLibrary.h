/*
* Copyright 2014.215B������
* All rights reserved.
*
* �ļ����ƣ�WordLibrary.h
* ժ	Ҫ���ʵ��������
*
* ��ǰ�汾��1.0
* ��	��: chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*
* ȡ���汾��1.0
* ԭ����  ��chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*/

#ifndef WORDLIBRARY_H
#define WORDLIBRARY_H

#include "Trie.h"
#include <fstream>
using namespace std;

#define MAXLEN 500

class WordLibrary
{
public:
	WordLibrary(char* fileName):m_trie(NULL), m_dic(NULL)
	{
		Load(fileName);
	}
	~WordLibrary()
	{
		if(m_trie != NULL)
			delete m_trie;
		if(m_dic != NULL)
			delete m_dic;
	}
public:
	//���شʵ�
	void Load(char* fileName)
	{
		ifstream dic(fileName);
		char* s = new char[MAXLEN];
		WCHAR* ws = NULL;
		int len = 0;
		if(m_dic != NULL)
			delete m_dic;
		m_dic = new CharStringLink;
		while(1)
		{
			if(dic.eof())
				break;
			dic.getline(s, MAXLEN);
			len = MultiByteToWideChar(CP_UTF8, 0, s, -1, NULL, 0);
			ws = new WCHAR[len+3];
			MultiByteToWideChar(CP_UTF8, 0, s, -1, ws, len);
			if(m_dic->m_next == NULL)
				m_dic->Insert(new CharString(ws+1, len-2));
			else
				m_dic->Insert(new CharString(ws, len-1));
			delete[] ws;
		}
		delete[] s;
		if(m_trie != NULL)
			delete m_trie;
		m_trie = new Trie;
		m_trie->Build(m_dic);
	}
public:
	Trie* m_trie;	//�ʵ���
	CharStringLink* m_dic;	//�ʻ�����
};

#endif