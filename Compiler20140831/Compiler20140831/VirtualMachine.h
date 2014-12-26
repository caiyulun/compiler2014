#pragma once
#include "CodeGen.h"
using namespace compiler;
namespace swd
{
	class Error;
	class SymbolTable;
}
namespace vm
{
	class StackItem
	{
	public:
		string name;
		string value;
		Tag type;
	};

	class RuntimeInfo
	{
	public:
		string lastScope;
		string currentScope;
		int currentPc;//current pc
		int vStackItems;
		vector<int> varStackItems;
		int constStackItems;
		int paramNum;//function params
	};

	class VirtualMachine
	{
	protected:
		int programCounter;//pc
		bool reg_flag;//flag register
		map<string, int> labelPos;//<Label,pos>, new iterator=vector.begin()+pos
		vector<shared_ptr<IRCode>>::iterator it;
		vector<Error> errList;
		//stack
		vector<StackItem> constStack;//���� ȫ�ֱ���ջ
		vector<StackItem> vStack;//ȫ����ͨջ
		map<string, string> varStack;//�ֲ�����ջ
		//code generator
		compiler::IRCodeGen *generator;
		swd::SymbolTable *symTable;
		RuntimeInfo rtInfo;
		swd::SymbolTable *currentTable;
	public:
		VirtualMachine();
		VirtualMachine(compiler::IRCodeGen *generator);
		VirtualMachine(compiler::IRCodeGen *generator, swd::SymbolTable *symTable);
		void initRuntimeInfo();
		void labelScan();
		void scan();
		void move();
		void run();
		void compute(char op);
	};
}