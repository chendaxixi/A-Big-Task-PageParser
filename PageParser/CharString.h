/*
* Copyright 2014.215B工作室
* All rights reserved.
*
* 文件名称：CharString.h
* 摘	要：字符串类的声明
*
* 当前版本：1.0
* 作	者: chendaxixi/陈少滨
* 完成日期：2014年11月16日
*
* 取代版本：1.0
* 原作者  ：chendaxixi/陈少滨
* 完成日期：2014年11月16日
*/

#ifndef CHARSTRING_H
#define CHARSTRING_H

#define NULL 0
#include <Windows.h>
#include <wchar.h>

class CharString
{
public:
	//多字节，宽字符两种构造函数
	CharString(char* s = NULL, int len = 0):m_body(NULL), m_wbody(NULL), m_len(0)
	{
		if(len == 0)
		{
			m_body = NULL;
			m_len = 0;
			return;
		}
		m_body = new char[len+1];
		for(int i = 0;i < len;i++)
			m_body[i] = s[i];
		m_body[len] = 0;
		m_len = len+1;
	}
	CharString(WCHAR* s = NULL, int len = 0):m_body(NULL), m_wbody(NULL), m_len(0)
	{
		if(len == 0)
		{
			m_wbody = NULL;
			m_len = 0;
			return;
		}
		m_wbody = new WCHAR[len+1];
		for(int i = 0;i < len;i++)
			m_wbody[i] = s[i];
		m_wbody[len] = L'\0';
		m_len = len+1;
	}
public:
	int Length(){return m_len;}	//返回字符串长度，包括末尾的0
	char* Str(){return m_body;}	//返回多字节字符串
	WCHAR* WStr(){return m_wbody;}	//返回宽字符字符串
	CharString subString(int startIndex);	//返回从startIndex到末尾的子串
	CharString subString(int startIndex, int endIndex);	//返回startIndex~endIndex间的子串
	CharString wsubString(int startIndex);	//返回从startIndex到末尾的宽字符子串
	CharString wsubString(int startIndex, int endIndex);	//返回startIndex~endIndex间的宽字符子串
	void Concat(CharString str);	//连接str字符串，结果自身变为连接后的字符串
	void Concat(char* s, int len);	//连接字符串，结果自身变为连接后的字符串
	void wConcat(WCHAR* s, int len);	//Concat宽字符版本
	void wConcat(CharString str);	//Concat宽字符版本
	int indexOf(char c);	//查询c在字符串中第一次出现的位置，若无则返回-1
	int indexOf(WCHAR c);	//宽字符版本
	int windexOf(CharString& str);	//宽字符版本
	int indexOf(CharString& str);	//查询str字符串在字符串中第一次出现的位置，若无则返回-1
	char CharAt(int index);	//index处字符
	WCHAR wCharAt(int index);	//宽字符版本
	void Destroy();	//清理字符串内存
	bool Valid();	//判断是否为无内容标签
public:
	bool operator >=(CharString& str);	//判断是否大于str，即str为字符串的前缀
	bool operator ==(CharString& str);	//判断是否相等
public:
	char* m_body;	//多字节字符串
	WCHAR* m_wbody;	//宽字符字符串
	int m_len;	//字符串长度，包括末尾的0
};

#endif