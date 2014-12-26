#pragma once
#include "stdafx.h"

namespace swd
{
	/*
	���ű��������õ�Ϊ������Ϣ���������a��������ԣ����֣����ͣ����������֣�����������ֵ��֮��
	�����Ǳ���ȡֵ
	*/
	class Node;

	class SymbolTable
	{
	public:
		string name;
		int tableIndex;
		SymbolTable* outer;
		vector<SymbolTable*> inner;
		SymbolTable();
		SymbolTable(string name);
		std::map<std::string, swd::Node* > dict;
		bool add(std::string key, Node* val);
		bool addInnerTable(SymbolTable *innerTable);
		SymbolTable* findInnerTable(string name);
		Node* lookup(std::string key);
		Node* lookupInScope(std::string key);
	};
}