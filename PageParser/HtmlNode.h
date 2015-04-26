/*
* Copyright 2014.215B工作室
* All rights reserved.
*
* 文件名称：HtmlNode.h
* 摘	要：网页中语法结构节点类的声明
*
* 当前版本：1.0
* 作	者: chendaxixi/陈少滨
* 完成日期：2014年11月16日
*
* 取代版本：1.0
* 原作者  ：chendaxixi/陈少滨
* 完成日期：2014年11月16日
*/

#ifndef HTMLNODE_H
#define HTMLNODE_H

#include "CharString.h"

//Html标签节点
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
	CharString m_label;	//标签字符串
	CharString* m_style;	//版式
	CharString* m_body;	//内容
	HtmlNode* m_son;	//儿子，即位于该标签内的第一个子标签
	HtmlNode* m_brother;	//同层的标签
};

#endif