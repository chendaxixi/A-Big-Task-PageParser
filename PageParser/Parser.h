/*
* Copyright 2014.215B������
* All rights reserved.
*
* �ļ����ƣ�Parser.h
* ժ	Ҫ����ҳ�����ִ��������
*
* ��ǰ�汾��1.1
* ��	��: chendaxixi/���ٱ�
* ������ڣ�2014��11��11��
*
* ȡ���汾��1.1
* ԭ����  ��chendaxixi/���ٱ�
* ������ڣ�2014��11��17��
*/

#ifndef PARSER_H
#define PARSER_H

#include "WordLibrary.h"
#include "Page.h"
using namespace std;

class Parser
{
public:
	Parser():m_page(NULL), m_dic(NULL), m_body(NULL), m_word(NULL){
	}
	~Parser()
	{
		if(m_page != NULL)
			delete m_page;
		if(m_dic != NULL)
			delete m_dic;
		if(m_body != NULL)
			delete m_body;
		if(m_word != NULL)
			delete m_word;
	}
public:
	//������ҳ
	void LoadPage(char* fileName)
	{
		if(m_page != NULL)
			delete m_page;
		m_page = new Page(fileName);
	}
	//���شʵ�
	void LoadDic(char* fileName)
	{
		if(m_dic != NULL)
			delete m_dic;
		m_dic = new WordLibrary(fileName);
	}
	//������ҳ��str��ǩ�����Ĳ���
	void FindLabel(CharString& str)
	{
		if(m_page == NULL) return;
		if(m_body != NULL)
			delete m_body;
		m_body = Find(m_page->Html(), str);
	}
	//�ִ�
	void Seperate();
	//���ִʽ�����
	void Print(wofstream& output);
private:
	Page* m_page;	//����������ҳ
	WordLibrary* m_dic;	//�������Ĵʵ�
	CharStringLink* m_body;	//�������������ǩ�����Ĳ���
	CharStringLink* m_word;	//�ִʽ��
};

#endif