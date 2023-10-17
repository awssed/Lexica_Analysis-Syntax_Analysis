#include "stdafx.h"
#include "iostream"
#include"Error.h"
#include"In.h"
#include"Log.h"
#include"Parm.h"
#include"Out.h"
#include"FST.h"
#include"LA.h"
#include"LT.h"
#include<cwchar>
#include<time.h>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	/*cout << "---- ���� Error::geterror ----" << endl << endl;
	try
	{
		throw ERROR_THROW(100);
	}
	catch (Error::ERROR e) {
		cout << "������ " << e.id << ":" << e.message << endl << endl;
	}
	cout << "---- ���� Error::geterrorin ----" << endl << endl;
	try
	{
		throw ERROR_THROW_IN(111, 7, 7);
	}
	catch (Error::ERROR e) {
		cout << "������ " << e.id << ":" << e.message << ",������:" << e.inext.line << ",�������:" << e.inext.col << endl << endl;
	}
	cout << "------���� getparm -------" << endl << endl;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in:" << parm.in << " ,-out:" << parm.out << " ,-log:" << parm.log << endl << endl;
	}
	catch (Error::ERROR e)
	{

		cout << "������ " << e.id << ": " << e.message << endl << endl;
	}

	cout << "------���� In::getin(1) -------" << endl << endl;

	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		cout << in.text << endl;
		cout << "����� ��������:" << in.size << endl;
		cout << "����� �����:" << in.lines << endl;
		cout << "���������:" << in.ignore << endl;
	}
	catch (Error::ERROR e) {
		cout << "������" << e.id << ':' << e.message;
	}*/

	//cout << "------���� In::getin(2) -------" << endl << endl;

	//try {
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	In::IN in = In::getin(parm);
	//	cout << in.text << endl;
	//	cout << "����� ��������:" << in.size << endl;
	//	cout << "����� �����:" << in.lines << endl;
	//	cout << "���������:" << in.ignore << endl;
	//}
	//catch (Error::ERROR e) {
	//	cout << "������" << e.id << ':' << e.message << endl << endl;
	//	cout << "������:" << e.inext.line << " �������:" << e.inext.col << endl << endl;
	//}
	//Log::LOG log = Log::INITLOG;
	//Out::OUT out = Out::INITOUT;
	//try 
	//{
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	log = Log::getlog(parm.log);
	//	out = Out::GetOut(parm.out);
	//	Log::WriteLine(log, (char*)"�����:", (char*)"��� ������ \n", "");
	//	Log::WriteLine(log, (wchar_t*)L"�����", (wchar_t*)L" ��� ������ \n", L"");
	//	Log::WriteLog(log);
	//	Log::WriteParm(log, parm);
	//	In::IN in = In::getin(parm);
	//	Log::WriteIn(log, in);
	//	Log::Close(log);
	//	Out::WriteText(out, in);
	//	Out::Close(out);
	//}
	//catch (Error::ERROR e) {
	//	Log::WriteError(log, e);
	//	Out::WriteError(out, e);
	//}
	Parm::PARM parm = Parm::getparm(argc, argv);
	Log::LOG log = Log::INITLOG;
	Out::OUT out = Out::INITOUT;
	try
	{
		out = Out::GetOut(parm.out);
		log = Log::getlog(parm.log);
		In::IN in_result = In::getin(parm.in);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		Out::WriteText(out, in_result);
		Log::WriteIn(log, in_result);
		LA::LA(parm, in_result);
		Log::Close(log);
		Out::Close(out);
	}
	catch (Error::ERROR e)
	{
		cout << "������" << e.id << ':' << e.message << endl << endl;
		if(e.inext.line)
		Log::WriteError(log, e);
		Out::WriteError(out, e);
			Log::Close(log);
		Out::Close(out);
	}
	
	return 0;
};