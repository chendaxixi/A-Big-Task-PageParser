/*
* Copyright 2014.215B������
* All rights reserved.
*
* �ļ����ƣ�Parser.cpp
* ժ	Ҫ����ҳ�����ִ����ʵ��
*
* ��ǰ�汾��1.1
* ��	��: chendaxixi/���ٱ�
* ������ڣ�2014��11��17��
*
* ȡ���汾��1.7
* ԭ����  ��chendaxixi/���ٱ�
* ������ڣ�2014��11��17��
*/

#include "Parser.h"

void Parser::Print(wofstream& output)
{
	if(m_word == NULL) return;
	CharStringLink* temp = m_word;
	if(temp->m_body->WStr() != NULL)
		output << temp->m_body->WStr() << endl;
	temp = temp->m_next;
	while(temp != m_word)
	{
		if(temp->m_body->WStr() != NULL)
			output << temp->m_body->WStr() << endl;
		temp = temp->m_next;
	}
}

void Parser::Seperate()
{
	if(m_dic == NULL) return;
	if(m_body == NULL) return;
	if(m_word != NULL)
		delete m_word;
	m_word = new CharStringLink;
	CharStringLink* temp = m_body;
	CharString* srcString = temp->m_body;
	Trie* tree = m_dic->m_trie;
	WCHAR* s = srcString->WStr();
	CharString* StrTemp = NULL;
	while(*s != L'\0')
	{
		StrTemp = tree->FindWord(s);
		if(StrTemp != NULL)
			m_word->Insert(StrTemp);
		else
			s++;
	}
	temp = temp->m_next;
	while(temp != m_body)
	{
		srcString = temp->m_body;
		s = srcString->WStr();
		while(*s != 0)
		{
			StrTemp = tree->FindWord(s);
			if(StrTemp != NULL)
				m_word->Insert(StrTemp);
			else
				s++;
		}
		temp = temp->m_next;
	}
}
