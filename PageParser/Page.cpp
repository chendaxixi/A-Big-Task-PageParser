/*
* Copyright 2014.215B工作室
* All rights reserved.
*
* 文件名称：Page.cpp
* 摘	要：网页类的定义
*
* 当前版本：1.0
* 作	者: chendaxixi/陈少滨
* 完成日期：2014年11月16日
*
* 取代版本：1.0
* 原作者  ：chendaxixi/陈少滨
* 完成日期：2014年11月16日
*/

#include "Page.h"
//
//CharString* Page::Build(HtmlNode* &htmlNode)
//{
//	char c = Char();
//	CharString* result = new CharString;
//	char* s = m_stringNow + m_index;
//	int len = 0;
//	while(1)
//	{
//		if(c == '<')
//			break;
//		len++;
//		if(m_stringNow[m_index+1] == 0)
//		{
//			result->Concat(s, len);
//			c = Next();
//			s = m_stringNow;
//			len = 0;
//		}
//		else
//			c = Next();
//	}
//	result->Concat(s, len);
//	s = m_stringNow + m_index + 1;
//	len = -1;
//	while(1)
//	{
//		if((c == '!') || (c == ' ') || (c == '>') || (c == '/') || (m_stringNow[m_index+1] == 0))
//			break;
//		len++;
//		c = Next();
//	}
//	if(len == 0)
//	{
//		s = m_stringNow + m_index + 1;
//		len = -1;
//		while(1)
//		{
//			if(c == '>')
//				break;
//			len++;
//			c = Next();
//		}
//		if(*m_stack.Peek() >= CharString(s, len))
//		{
//			m_stack.Pop();
//			return result;
//		}
//		else 
//			return result;
//	}
//	if(c == '!')
//	{
//		len++;
//		c = Next();
//		if(c == '-')
//		{
//			c = Next();
//			c = Next();
//			while(1)
//			{
//			while(c != '-')
//				c = Next();
//			c = Next();
//			if(c == '-')
//			{
//				c = Next();
//				if(c == '>')
//				{
//					c = Next();
//					return result;
//				}
//			}
//			c = Next();
//			}
//		}
//	}
//	htmlNode = new HtmlNode(s, len);
//	m_stack.Push(&(htmlNode->m_label));
//	CharString* style = new CharString;
//	s = m_stringNow + m_index;
//	len = 0;
//	while(1)
//	{
//		if(c == '>')
//			break;
//		len++;
//		if(m_stringNow[m_index+1] == 0)
//		{
//			style->Concat(s, len);
//			c = Next();
//			s = m_stringNow;
//			len = 0;
//		}
//		else
//			c = Next();
//	}
//	if(m_stringNow[m_index-1] == '/')
//		len--;
//	style->Concat(s, len);
//	if(style->Length() != 0)
//		htmlNode->m_style = style;
//	else
//		delete style;
//	CharString* temp = NULL;
//	if((m_stringNow[m_index-1] == '/') || (htmlNode->m_label.Valid()))
//	{
//		c = Next();
//		m_stack.Pop();
//		temp = Build(htmlNode->m_brother);
//		result->Concat(temp);
//		delete temp;
//		return result;
//	}
//	else
//	{
//		c = Next();
//		htmlNode->m_body = Build(htmlNode->m_son);
//		temp = Build(htmlNode->m_brother);
//		result->Concat(temp);		
//		delete temp;
//		return result;
//	}
//}

CharStringLink* Find(HtmlNode* htmlNode, CharString& str)
{
	CharStringLink* result = NULL;
	if(htmlNode == NULL) return result;
	CharStringLink* temp;
	CharStringLink* temp2;
	if(htmlNode->m_label == str)
		if(htmlNode->m_body->Length() > 0)
			result = new CharStringLink(htmlNode->m_body);
	temp = Find(htmlNode->m_son, str);
	if(temp != NULL)
		if(result == NULL)
			result = temp;
		else
		{
			temp2 = result->m_pre;
			result->m_pre = temp->m_pre;
			temp->m_pre->m_next = result;
			temp->m_pre = temp2;
			temp2->m_next = temp;
		}
	temp = Find(htmlNode->m_brother, str);
	if(temp != NULL)
	{
		if(result == NULL)
			result = temp;
		else
		{
			temp2 = result->m_pre;
			result->m_pre = temp->m_pre;
			temp->m_pre->m_next = result;
			temp->m_pre = temp2;
			temp2->m_next = temp;
		}
	}
	return result;
}

void Page::Start()
{
	if(Error()) return;
	m_input.imbue(locale("chs"));
	m_string = new WCHAR[MAXLINELEN];
	m_input.getline(m_string, MAXLINELEN);
	m_index = 0;
	m_row = 1;
	Back();
}

bool Page::UpdateLine()
{
	while(m_string[m_indexTry] == L'\0')
	{
		if(m_input.eof()) return true;
		m_input.getline(m_string, MAXLINELEN);
		m_index = 0;
		m_indexTry = m_index;
		m_row++;
		Back();
	}
	return false;
}

void Page::Update()
{
	m_index = m_indexTry;
}

void Page::Back()
{
	m_indexTry = m_index;
}

CharString Page::Build(HtmlNode* &htmlNode)
{
	CharString body = Label(htmlNode);
	if(htmlNode == NULL) return body;
	if(m_row == 20)
	{
		m_row = m_row;
	}
//	wcout << m_row << L" " << htmlNode->m_label.WStr() << " " << m_stack.Size() << endl;
	Style(htmlNode);
	Body(htmlNode);
	End(htmlNode);
	CharString temp = Build(htmlNode->m_brother);
	body.wConcat(temp);
	temp.Destroy();
	return body;
}

CharString Page::Label(HtmlNode* &htmlNode)
{
	CharString result((WCHAR*)NULL, 0);
	Back();
	WCHAR* sTemp = m_string;
	int sLen = 0;
	while(1)
	{
		if(m_string[m_indexTry] == L'\0')
		{
			result.wConcat(sTemp+m_index, sLen);
			if (UpdateLine())
				return result;
			sTemp = m_string;
			sLen = 0;
		}
		while(m_string[m_indexTry] != L'<')
		{
			m_indexTry++;
			sLen++;
			if(m_string[m_indexTry] == L'\0')
			{
				result.wConcat(sTemp+m_index, sLen);
				if(UpdateLine())
					return result;
				sTemp = m_string;
				sLen = 0;
			}
		}
		result.wConcat(sTemp+m_index, sLen);
		Update();
		sTemp = m_string;
		sLen = 0;
		if((m_string[m_indexTry+1] == L'!') && (m_string[m_indexTry+2] == L'-') && (m_string[m_indexTry+3] == L'-'))
		{
			m_indexTry += 4;
			while(1)
			{
				while(m_string[m_indexTry] != L'-')
				{
					m_indexTry++;
					if(UpdateLine())
						return result;
				}
				if((m_string[m_indexTry+1] == L'-') && (m_string[m_indexTry+2] == L'>'))
				{
					m_indexTry += 2;
					break;
				}
				else
					m_indexTry++;
			}
			Update();
			sTemp = m_string;
			sLen = 0;
		}
		else if(m_string[m_indexTry+1] == L'/')
		{
			Update();
			return result;
		}
		else if(!(((m_string[m_indexTry+1] >= L'a') && (m_string[m_indexTry+1] <= L'z'))
			|| ((m_string[m_indexTry+1] >= L'A') && (m_string[m_indexTry+1] <= L'Z'))))
		{
			sLen++;
			m_indexTry++;
		}
		else
		{
			m_indexTry++;
			while(((m_string[m_indexTry] >= L'a') && (m_string[m_indexTry] <= L'z'))
			|| ((m_string[m_indexTry] >= L'A') && (m_string[m_indexTry] <= L'Z'))
			|| ((m_string[m_indexTry] >= L'0') && (m_string[m_indexTry] <= L'9')))
			{
				m_indexTry++;
				sLen++;
			}
			htmlNode = new HtmlNode(sTemp+m_index+1, sLen);
			m_stack.Push(htmlNode->m_label);
			Update();
			return result;
		}
	}
}

void Page::Style(HtmlNode* &htmlNode)
{
	Back();
	WCHAR* sTemp = m_string;
	int sLen = 0;
	while(m_string[m_indexTry] != L'>')
	{
		m_indexTry++;
		sLen++;
		if(m_string[m_indexTry] == L'\0')
		{
			if(htmlNode->m_style == NULL)
				htmlNode->m_style = new CharString(sTemp+m_index, sLen);
			else
				htmlNode->m_style->wConcat(sTemp+m_index, sLen);
			if(UpdateLine())
				return;
			sTemp = m_string;
			sLen = 0;
		}
	}
	if((m_indexTry > 0) && (m_string[m_indexTry-1] == L'/'))
	{
		sLen--;
		m_indexTry--;
	}
	else
		m_indexTry++;
	if(sLen > 0)
	{
		if(htmlNode->m_style == NULL)
			htmlNode->m_style = new CharString(sTemp+m_index, sLen);
		else
			htmlNode->m_style->wConcat(sTemp+m_index, sLen);
	}
	Update();
	UpdateLine();
}

void Page::Body(HtmlNode* &htmlNode)
{
	if((m_string[m_index] == L'/') && (m_string[m_index+1] == L'>'))
		return;
	htmlNode->m_body = new CharString(Build(htmlNode->m_son));
}

void Page::End(HtmlNode* &htmlNode)
{
	if((m_string[m_index] == L'/') && (m_string[m_index+1] == L'>'))
	{
		m_indexTry += 2;
		UpdateLine();
		Update();
		m_stack.Pop();
		return;
	}
	Back();
	m_indexTry+=2;
	WCHAR* sTemp = m_string;
	int sLen = 0;
	while(m_string[m_indexTry] != L'>')
	{
		m_indexTry++;
		sLen++;
	}
	CharString temp(sTemp+m_index+2, sLen);
	if(m_stack.Peek() >= temp)
	{
		temp.Destroy();
		m_stack.Pop();
		m_indexTry++;
		UpdateLine();
		Update();
	}
	else if (m_stack.Peek().Valid())
	{
		temp.Destroy();
		m_stack.Pop();
	}
	else
	{
		temp.Destroy();
		m_indexTry++;
		UpdateLine();
		Update();
	}
}