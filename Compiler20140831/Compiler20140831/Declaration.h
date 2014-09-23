#pragma once
#include "stdafx.h"
#include "lexer.h"
namespace swd
{

	enum class DeclaredType
	{
		Constant, Enumeration,
		Type, Variable, Record,
		Program, Procedure, Function,
		Undefined, 
		INT, FLOAT, STRING, USERTYPE /*���ÿɲ���*/
	};

	class Declaration
	{
	public:
		DeclaredType type;//���ͣ�constant��type��var
		string name;//��ʶ������
	};

	class ConstantDecl :public Declaration
	{
	public:
		// const i=10
		Token value;
	};

	class VariableDecl :public Declaration
	{
	public:
		// var i:integer
		Token identity;

	};

	class TypeDecl :public Declaration //ֻ֧��record ��֧�������ö��
	{
	public:
		vector<VariableDecl*> vars;
	};

	class FunctionDecl :public Declaration
	{
	public:
		std::vector<VariableDecl*> vars;
		std::string returnType;
	};
}