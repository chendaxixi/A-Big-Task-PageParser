/*
* Copyright 2014.215B工作室
* All rights reserved.
*
* 文件名称：Parser.h
* 摘	要：网页解析分词类的声明
*
* 当前版本：1.1
* 作	者: chendaxixi/陈少滨
* 完成日期：2014年11月11日
*
* 取代版本：1.1
* 原作者  ：chendaxixi/陈少滨
* 完成日期：2014年11月17日
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
	//加载网页
	void LoadPage(char* fileName)
	{
		if(m_page != NULL)
			delete m_page;
		m_page = new Page(fileName);
	}
	//加载词典
	void LoadDic(char* fileName)
	{
		if(m_dic != NULL)
			delete m_dic;
		m_dic = new WordLibrary(fileName);
	}
	//查找网页中str标签的正文部分
	void FindLabel(CharString& str)
	{
		if(m_page == NULL) return;
		if(m_body != NULL)
			delete m_body;
		m_body = Find(m_page->Html(), str);
	}
	//分词
	void Seperate();
	//将分词结果输出
	void Print(wofstream& output);
private:
	Page* m_page;	//分析器的网页
	WordLibrary* m_dic;	//分析器的词典
	CharStringLink* m_body;	//分析器的所求标签的正文部分
	CharStringLink* m_word;	//分词结果
};

#endif