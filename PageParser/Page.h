/*
* Copyright 2014.215B工作室
* All rights reserved.
*
* 文件名称：Page.h
* 摘	要：网页类的声明
*
* 当前版本：1.0
* 作	者: chendaxixi/陈少滨
* 完成日期：2014年11月16日
*
* 取代版本：1.0
* 原作者  ：chendaxixi/陈少滨
* 完成日期：2014年11月16日
*/

#ifndef PAGE_H
#define PAGE_H

#include "CharStringLink.h"
#include "Stack.h"
#include "HtmlNode.h"
#include <fstream>
#include <iostream>
using namespace std;

#define MAXLINELEN 10000	//一行的最大长度

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
	//当前在第几行
	int Row(){return m_row;}
	//当前在第几列
	int Line(){return m_indexTry+1;}
	//是否打开失败
	bool Error()
	{
		if(m_input.bad()) 
			return true;
		else
			return false;
	}
	//开始读取
	void Start();
	//读到行末尾时换行；若文件结束，则返回true，否则返回false
	bool UpdateLine();
	//尝试成功
	void Update();
	//尝试失败，退回
	void Back();
	//读入当前HtmlNode的标签字符串
	CharString Label(HtmlNode* &htmlNode);
	//读入HtmlNode的版式部分
	void Style(HtmlNode* &htmlNode);
	//读入HtmlNode的内容
	void Body(HtmlNode* &htmlNode);
	//关闭当前HtmlNode节点
	void End(HtmlNode* &htmlNode);
	//构造从当前输入光标起的HtmlNode节点，并返回节点前的字符串
	CharString Build(HtmlNode* &htmlNode);
	//返回网页的标签节点
	HtmlNode* Html(){return m_htmlNode;}

public:
	HtmlNode* m_htmlNode;	//网页对应的Html节点
	wifstream m_input;	//网页文件输入流
	WCHAR* m_string;	//当前字符串
	int m_index;	//当前读入的光标位置
	int m_indexTry;	//尝试向前读的光标位置
	int m_row;	//当前的行数
	Stack<CharString> m_stack;	//栈
};

CharStringLink* Find(HtmlNode* htmlNode, CharString& str);

#endif