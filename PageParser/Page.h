/*
* Copyright 2014.215B������
* All rights reserved.
*
* �ļ����ƣ�Page.h
* ժ	Ҫ����ҳ�������
*
* ��ǰ�汾��1.0
* ��	��: chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*
* ȡ���汾��1.0
* ԭ����  ��chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*/

#ifndef PAGE_H
#define PAGE_H

#include "CharStringLink.h"
#include "Stack.h"
#include "HtmlNode.h"
#include <fstream>
#include <iostream>
using namespace std;

#define MAXLINELEN 10000	//һ�е���󳤶�

class Page
{
public:
	Page(char* fileName = NULL):m_htmlNode(NULL), m_input(fileName),
		m_string(NULL), m_row(0), m_index(0), m_indexTry(0), m_stack()
	{
		if(m_input.good())
		{
			Start();
			Build(m_htmlNode);
		}
	}
	~Page()
	{
		if(m_htmlNode != NULL)
			delete m_htmlNode;
		if(m_string != NULL)
			delete[] m_string;
	}
public:
	//��ǰ�ڵڼ���
	int Row(){return m_row;}
	//��ǰ�ڵڼ���
	int Line(){return m_indexTry+1;}
	//�Ƿ��ʧ��
	bool Error()
	{
		if(m_input.bad()) 
			return true;
		else
			return false;
	}
	//��ʼ��ȡ
	void Start();
	//������ĩβʱ���У����ļ��������򷵻�true�����򷵻�false
	bool UpdateLine();
	//���Գɹ�
	void Update();
	//����ʧ�ܣ��˻�
	void Back();
	//���뵱ǰHtmlNode�ı�ǩ�ַ���
	CharString Label(HtmlNode* &htmlNode);
	//����HtmlNode�İ�ʽ����
	void Style(HtmlNode* &htmlNode);
	//����HtmlNode������
	void Body(HtmlNode* &htmlNode);
	//�رյ�ǰHtmlNode�ڵ�
	void End(HtmlNode* &htmlNode);
	//����ӵ�ǰ���������HtmlNode�ڵ㣬�����ؽڵ�ǰ���ַ���
	CharString Build(HtmlNode* &htmlNode);
	//������ҳ�ı�ǩ�ڵ�
	HtmlNode* Html(){return m_htmlNode;}

public:
	HtmlNode* m_htmlNode;	//��ҳ��Ӧ��Html�ڵ�
	wifstream m_input;	//��ҳ�ļ�������
	WCHAR* m_string;	//��ǰ�ַ���
	int m_index;	//��ǰ����Ĺ��λ��
	int m_indexTry;	//������ǰ���Ĺ��λ��
	int m_row;	//��ǰ������
	Stack<CharString> m_stack;	//ջ
};

CharStringLink* Find(HtmlNode* htmlNode, CharString& str);

#endif