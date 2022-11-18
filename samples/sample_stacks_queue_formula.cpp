// Тестирование стеков,очередей, алгоритма перевода в постфиксную форму
#include <iostream>
#include <iomanip>
#include "TFormula.h"
#include "TQueue.h"
#include"TStack.h"

using namespace std;

void line() 
{
  cout << "==============================================================================" << endl;
}

int main()
{
  setlocale(LC_ALL, "Russian");
  
  line();
  
  TStack <int> pt(3);
  pt.Push(1);
  pt.Push(2);
  cout << "Размер стека " << pt.Size() << endl;
  cout << "Верхний элемент стека pt  " << pt.TopElem() << endl;
  pt.Pop();
  pt.Pop();
  pt.Push(3);
  cout << "Верхний элемент стека pt  " << pt.TopElem() << endl;
  cout << "Размер стека pt " << pt.Size() << endl;
  pt.Pop();

  if (pt.IsEmpty()) {
    cout << "Стек пуст\n" << endl;
  }
  else {
    cout << "Стек не пуст\n" << endl;
  }
  
  TStack <int> pt2(4);
  pt2.Push(100);
  pt2.Push(200);
  pt2.Push(300);
  pt2.Push(400);
  cout << "Верхний элемент стека pt2  " << pt2.TopElem() << endl;
  cout << "Размер стека pt2 " << pt2.Size() << endl;
  TStack <int> pt3(pt2);
  cout << "Верхний элемент стека pt3  " << pt3.TopElem() << endl;
  cout << "Размер стека pt3 " << pt3.Size() << endl;
  
  line();

  TQueue <int> q(5);

  q.Push(1);
  q.Push(2);
  q.Push(3);

  cout << "Первый элемент в очереди q " << q.StartElem() << endl;
  q.Pop();

  q.Push(4);

  cout << "Размер очереди q " << q.Size() << endl;

  q.Pop();
  q.Pop();
  q.Pop();

  if (q.IsEmpty())
    cout << "Очередь пуста\n" << endl;
  else 
    cout << "Очередь не пуста\n" << endl;

  TQueue <int> q2(4);
  q2.Push(10);
  q2.Push(20);
  q2.Push(30);
  q2.Push(40);
  cout << "Первый элемент в очереди q2 " << q2.StartElem() << endl;
  cout << "Размер очереди q2 " << q2.Size() << endl;
  TQueue <int> q3(q2);
  cout << "Первый элемент в очереди q3 " << q3.StartElem() << endl;
  cout << "Размер очереди q3 " << q3.Size() << endl;

 line();

 string exprStr;
 cout << "Введите инфиксное выражение без пробелов " << endl;
 cin >> exprStr;
 TFormula expr(exprStr);
 cout << "Инфиксное выражение:  " << expr.GetInfix() << endl;
 cout << "Постфиксное выражение: " << expr.GetPostfix() << endl;
 vector <char> operands = expr.GetOperands();
 map <char, double> values;
 double value;
 for (const auto& operand : operands)
 {
   cout << "Введите значение для операнда " << operand << endl;
   cin >> value;
   values[operand] = value;
 }
 
 cout << "Результат = " << expr.Calculate(values) << endl;

 line();

 
  return 0;
}
