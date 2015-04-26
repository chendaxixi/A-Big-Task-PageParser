/*
* Copyright 2014.215B工作室
* All rights reserved.
*
* 文件名称：main.cpp
* 摘	要：网页主体提取&分词
*
* 当前版本：1.0
* 作	者: chendaxixi/陈少滨
* 完成日期：2014年11月16日
*
* 取代版本：1.0
* 原作者  ：chendaxixi/陈少滨
* 完成日期：2014年11月16日
*/

#include "Parser.h"
#include <iostream>
using namespace std;

int main(int argc, char* args[])
{
	char* dicName = args[1];
	char inputName[50];
	char outputName[50];
	int len1 = 0;
	int len2 = 0;
	while(args[2][len1] != 0)
	{
		inputName[len1] = args[2][len1];
		len1++;
	}
	inputName[len1] = 0;
	while(args[3][len2] != 0)
	{
		outputName[len2] = args[3][len2];
		len2++;
	}
	outputName[len2] = 0;
	wofstream output;
	CharString str(L"p", 1);
	Parser parser;
	cout << "Load Dictionary ... Please Wait..." << endl;
	parser.LoadDic(dicName);
	cout << "Load Dictionary Successfully!" << endl;
	inputName[len1] = '0';
	inputName[len1+1] = '0';
	inputName[len1+2] = '0';
	inputName[len1+4] = '.';
	inputName[len1+5] = 'h';
	inputName[len1+6] = 't';
	inputName[len1+7] = 'm';
	inputName[len1+8] = 0;
	outputName[len2] = '0';
	outputName[len2 + 1] = '0';
	outputName[len2 + 2] = '0';
	outputName[len2 + 4] = '.';
	outputName[len2 + 5] = 't';
	outputName[len2 + 6] = 'x';
	outputName[len2 + 7] = 't';
	outputName[len2 + 8] = 0;
	for(int i = 0;i < 10;i++)
	{
		inputName[len1+3] = '0' + i + 1;
		outputName[len2 + 3] = '0' + i + 1;
		if(i == 9)
		{
			inputName[len1+2] = '1';
			inputName[len1+3] = '0';
			outputName[len2+2] = '1';
			outputName[len2+3] = '0';
		}
		cout << "Load Page" << i+1 << " ... Please Wait..." << endl;
		parser.LoadPage(inputName);
		cout << "Load Successfully!" << endl;
		parser.FindLabel(str);
		cout << "Seperate Words... Please Wait..." << endl;
		parser.Seperate();
		cout << "Seperate Successfully" << endl;
		output.open(outputName);
		output.imbue(locale("chs"));
		parser.Print(output);
		output.close();
	}
	str.Destroy();
	system("pause");
}