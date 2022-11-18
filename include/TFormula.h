#include "TStack.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class TFormula {
protected:
	string infix;// ��������� ����� ������
	string postfix; // ����������� �����
	vector <char> lexems; //�������
	map <char, int> priority; // ���������� ��������
	map <char, double> operands; //��������
public:
	TFormula(string _infix); // ����������� �������������
	string GetInfix() const; // �������� ��������� �����
	string GetPostfix()const; // �������� ����������� �����
	vector <char> GetOperands() const; // �������� ������ ���������
	double Calculate(const map <char, double>& values); // ���������� ����������
	void ToPostfix(); // ������� ��������� � ����������� �����
	void Parse(); // ���������� �������� �� ������ � ������ ������
};