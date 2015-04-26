/*
* Copyright 2014.215B工作室
* All rights reserved.
*
* 文件名称：CharString.cpp
* 摘	要：字符串类的定义
*
* 当前版本：1.0
* 作	者: chendaxixi/陈少滨
* 完成日期：2014年11月16日
*
* 取代版本：1.0
* 原作者  ：chendaxixi/陈少滨
* 完成日期：2014年11月16日
*/

#include "CharString.h"

bool CharString::operator==(CharString& str)
{
	if(m_len != str.Length())
		return false;
	if(m_body == NULL)
	{
		if(m_wbody == NULL) return false;
		WCHAR* s = str.WStr();
		for(int i = 0;i < m_len;i++)
			if(m_wbody[i] != s[i])
				return false;
		return true;
	}
	char* s = str.Str();
	for(int i = 0;i < m_len;i++)
		if(m_body[i] != s[i])
			return false;
	return true;
}

bool CharString::operator>=(CharString& str)
{
	int len = str.Length();
	if(m_len < len) return false;
	len--;
	if(m_body == NULL)
	{
		if(m_wbody == NULL) return false;
		WCHAR* s = str.WStr();
		for(int i = 0;i < len;i++)
			if(m_wbody[i] != s[i])
				return false;
		return true;
	}
	char* s = str.Str();
	for(int i = 0;i < len;i++)
		if(m_body[i] != s[i])
			return false;
	return true;
}

bool CharString::Valid()
{
	CharString* temp = NULL;
	temp = new CharString(L"br", 2);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"hr", 2);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"img", 3);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"input", 5);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"link", 4);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"meta", 4);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"area", 4);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"base", 4);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"col", 3);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"command", 7);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"embed", 5);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"keygen", 6);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"param", 5);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"source", 6);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"track", 5);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	temp = new CharString(L"wbr", 3);
	if(*this >= *temp)
	{
		delete temp;
		return true;
	}
	delete temp;
	return false;
}

char CharString::CharAt(int index)
{
	if(m_body == NULL) return 0;
	if(index >= m_len) return 0;
	return m_body[index];
}

WCHAR CharString::wCharAt(int index)
{
	if(m_wbody == NULL) return 0;
	if(index >= m_len) return 0;
	return m_wbody[index];
}

void CharString::Concat(CharString str)
{
	if(str.Length() == 0) return;
	char* s = new char[m_len];
	for(int i = 0;i < m_len;i++)
		s[i] = m_body[i];
	if(m_body != NULL)
		delete[] m_body;
	int len;
	if(m_len == 0)
	{
		len = 0;
		m_len = str.Length()-1;
	}
	else
	{
		len = m_len-1;
		m_len = len + str.Length()-1;
	}
	m_body = new char[m_len+1];
	for(int i = 0;i < len;i++)
		m_body[i] = s[i];
	for(int i = len;i < m_len;i++)
		m_body[i] = str.m_body[i-len];
	m_body[m_len] = 0;
	m_len++;
	delete[] s;
}

void CharString::Concat(char* s, int len)
{
	if(len == 0) return;
	char* ss = new char[m_len];
	for(int i = 0;i < m_len;i++)
		ss[i] = m_body[i];
	if(m_body != NULL)
		delete[] m_body;
	int len1;
	if(m_len == 0)
	{
		len1 = 0;
		m_len = len;
	}
	else
	{
		len1 = m_len-1;
		m_len = len1 + len;
	}
	m_body = new char[m_len+1];
	for(int i = 0;i < len1;i++)
		m_body[i] = ss[i];
	for(int i = len1;i < m_len;i++)
		m_body[i] = s[i-len1];
	m_body[m_len] = 0;
	m_len++;
	delete[] ss;
}

void CharString::wConcat(CharString str)
{
	if(str.Length() == 0) return;
	WCHAR* s = new WCHAR[m_len];
	for(int i = 0;i < m_len;i++)
		s[i] = m_wbody[i];
	if(m_wbody != NULL)
		delete[] m_wbody;
	int len;
	if(m_len == 0)
	{
		len = 0;
		m_len = str.Length()-1;
	}
	else
	{
		len = m_len-1;
		m_len = len + str.Length()-1;
	}
	m_wbody = new WCHAR[m_len+1];
	for(int i = 0;i < len;i++)
		m_wbody[i] = s[i];
	for(int i = len;i < m_len;i++)
		m_wbody[i] = str.m_wbody[i-len];
	m_wbody[m_len] = 0;
	m_len++;
	delete[] s;
}

void CharString::wConcat(WCHAR* s, int len)
{
	if(len == 0) return;
	WCHAR* ss = new WCHAR[m_len];
	for(int i = 0;i < m_len;i++)
		ss[i] = m_wbody[i];
	if(m_wbody != NULL)
		delete[] m_wbody;
	int len1;
	if(m_len == 0)
	{
		len1 = 0;
		m_len = len;
	}
	else
	{
		len1 = m_len-1;
		m_len = len1 + len;
	}
	m_wbody = new WCHAR[m_len+1];
	for(int i = 0;i < len1;i++)
		m_wbody[i] = ss[i];
	for(int i = len1;i < m_len;i++)
		m_wbody[i] = s[i-len1];
	m_wbody[m_len] = 0;
	m_len++;
	delete[] ss;
}

CharString CharString::subString(int index)
{
	if(index >= m_len-1)
		return CharString((char*)NULL, 0);
	return CharString(m_body+index, m_len-index-1);
}

CharString CharString::subString(int startIndex, int endIndex)
{
	if((startIndex >= m_len-1) || (endIndex >= m_len-1) || (startIndex > endIndex))
		return CharString((char*)NULL, 0);
	return CharString(m_body+startIndex, endIndex - startIndex + 1);
}

CharString CharString::wsubString(int index)
{
	if(index >= m_len-1)
		return CharString((WCHAR*)NULL, 0);
	return CharString(m_wbody+index, m_len-index-1);
}

CharString CharString::wsubString(int startIndex, int endIndex)
{
	if((startIndex >= m_len-1) || (endIndex >= m_len-1) || (startIndex > endIndex))
		return CharString((WCHAR*)NULL, 0);
	return CharString(m_wbody+startIndex, endIndex - startIndex + 1);
}

int CharString::indexOf(char c)
{
	if(m_body == NULL) return -1;
	for(int i = 0;i < m_len-1;i++)
		if(m_body[i] == c)
			return i;
	return -1;
}

int CharString::indexOf(WCHAR c)
{
	if(m_wbody == NULL) return -1;
	for(int i = 0;i < m_len-1;i++)
		if(m_wbody[i] == c)
			return i;
	return -1;
}

int CharString::indexOf(CharString& str)
{
	char* s = str.m_body;
	int len = str.m_len-1;
	if(s == NULL) return -1;
	if(m_len == 0) return -1;
	bool flag = true;
	for(int i = 0;i < m_len-len-1;i++)
		if(m_body[i] == s[0])
		{
			flag = true;
			for(int j = 0;j < len;j++)
				if(m_body[i+j] != s[j])
				{
					flag = false;
					break;
				}
			if(flag)
				return i;
		}
	return -1;
}

int CharString::windexOf(CharString& str)
{
	WCHAR* s = str.m_wbody;
	int len = str.m_len-1;
	if(s == NULL) return -1;
	if(m_len == 0) return -1;
	bool flag = true;
	for(int i = 0;i < m_len-len-1;i++)
		if(m_wbody[i] == s[0])
		{
			flag = true;
			for(int j = 0;j < len;j++)
				if(m_wbody[i+j] != s[j])
				{
					flag = false;
					break;
				}
			if(flag)
				return i;
		}
	return -1;
}

void CharString::Destroy()
{
	if(m_body != NULL)
	{
		delete[] m_body;
		m_body = NULL;
	}
	if(m_wbody != NULL)
	{
		delete[] m_wbody;
		m_wbody = NULL;
	}
	m_len = 0;
}