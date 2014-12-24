#pragma once
#include "CodeGen.h"
using namespace compiler;
namespace vm
{
	class StackItem
	{
	public:
		string name;
		string value;
		Tag type;
	};

	class VirtualMachine
	{
	protected:
		int programCounter;//pc
		map<string, int> labelPos;//<Label,pos>, new iterator=vector.begin()+pos
		vector<shared_ptr<IRCode>>::iterator it;
		//stack
		vector<StackItem> constStack;//���� ȫ�ֱ���ջ
		vector<StackItem> vStack;//ȫ����ͨջ
		map<string, string> varStack;//�ֲ�����ջ
		//code generator
		compiler::IRCodeGen *generator;
	public:
		VirtualMachine(){}
		VirtualMachine(compiler::IRCodeGen *generator);
		void run();
	};
}