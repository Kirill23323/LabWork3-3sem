#include "TStack.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class TFormula {
protected:
	string infix;// инфиксная форма записи
	string postfix; // постфиксная форма
	vector <char> lexems; //лексемы
	map <char, int> priority; // приоритеты операций
	map <char, double> operands; //операнды
public:
	TFormula(string _infix); // конструктор инициализатор
	string GetInfix() const; // получить инфиксную форму
	string GetPostfix()const; // получить постфиксную форму
	vector <char> GetOperands() const; // получить список операндов
	double Calculate(const map <char, double>& values); // вычисление результата
	void ToPostfix(); // перевод выражения в постфиксную форму
	void Parse(); // добавление символов из строки в вектор лексем
};