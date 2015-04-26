/*
* Copyright 2014.215B������
* All rights reserved.
*
* �ļ����ƣ�HtmlNode.h
* ժ	Ҫ����ҳ���﷨�ṹ�ڵ��������
*
* ��ǰ�汾��1.0
* ��	��: chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*
* ȡ���汾��1.0
* ԭ����  ��chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*/

#ifndef HTMLNODE_H
#define HTMLNODE_H

#include "CharString.h"

//Html��ǩ�ڵ�
class HtmlNode
{
public:
	HtmlNode(WCHAR* s = NULL, int len = 0):m_label(s, len), m_style(NULL), m_body(NULL), m_son(NULL), m_brother(NULL){
	}
	~HtmlNode()
	{
		m_label.Destroy();
		if(m_style != NULL)
		{
			m_style->Destroy();
			delete m_style;
		}
		if(m_body != NULL)
		{
			m_body->Destroy();
			delete m_body;
		}
		if(m_son != NULL)
			delete m_son;
		if(m_brother != NULL)
			delete m_brother;
	}
public:
	CharString m_label;	//��ǩ�ַ���
	CharString* m_style;	//��ʽ
	CharString* m_body;	//����
	HtmlNode* m_son;	//���ӣ���λ�ڸñ�ǩ�ڵĵ�һ���ӱ�ǩ
	HtmlNode* m_brother;	//ͬ��ı�ǩ
};

#endif