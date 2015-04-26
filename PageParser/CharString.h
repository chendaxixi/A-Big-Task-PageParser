/*
* Copyright 2014.215B������
* All rights reserved.
*
* �ļ����ƣ�CharString.h
* ժ	Ҫ���ַ����������
*
* ��ǰ�汾��1.0
* ��	��: chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*
* ȡ���汾��1.0
* ԭ����  ��chendaxixi/���ٱ�
* ������ڣ�2014��11��16��
*/

#ifndef CHARSTRING_H
#define CHARSTRING_H

#define NULL 0
#include <Windows.h>
#include <wchar.h>

class CharString
{
public:
	//���ֽڣ����ַ����ֹ��캯��
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
	int Length(){return m_len;}	//�����ַ������ȣ�����ĩβ��0
	char* Str(){return m_body;}	//���ض��ֽ��ַ���
	WCHAR* WStr(){return m_wbody;}	//���ؿ��ַ��ַ���
	CharString subString(int startIndex);	//���ش�startIndex��ĩβ���Ӵ�
	CharString subString(int startIndex, int endIndex);	//����startIndex~endIndex����Ӵ�
	CharString wsubString(int startIndex);	//���ش�startIndex��ĩβ�Ŀ��ַ��Ӵ�
	CharString wsubString(int startIndex, int endIndex);	//����startIndex~endIndex��Ŀ��ַ��Ӵ�
	void Concat(CharString str);	//����str�ַ�������������Ϊ���Ӻ���ַ���
	void Concat(char* s, int len);	//�����ַ�������������Ϊ���Ӻ���ַ���
	void wConcat(WCHAR* s, int len);	//Concat���ַ��汾
	void wConcat(CharString str);	//Concat���ַ��汾
	int indexOf(char c);	//��ѯc���ַ����е�һ�γ��ֵ�λ�ã������򷵻�-1
	int indexOf(WCHAR c);	//���ַ��汾
	int windexOf(CharString& str);	//���ַ��汾
	int indexOf(CharString& str);	//��ѯstr�ַ������ַ����е�һ�γ��ֵ�λ�ã������򷵻�-1
	char CharAt(int index);	//index���ַ�
	WCHAR wCharAt(int index);	//���ַ��汾
	void Destroy();	//�����ַ����ڴ�
	bool Valid();	//�ж��Ƿ�Ϊ�����ݱ�ǩ
public:
	bool operator >=(CharString& str);	//�ж��Ƿ����str����strΪ�ַ�����ǰ׺
	bool operator ==(CharString& str);	//�ж��Ƿ����
public:
	char* m_body;	//���ֽ��ַ���
	WCHAR* m_wbody;	//���ַ��ַ���
	int m_len;	//�ַ������ȣ�����ĩβ��0
};

#endif