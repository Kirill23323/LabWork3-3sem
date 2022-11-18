#include "TFormula.h"


void TFormula::ToPostfix()
{
  Parse();
  TStack <char> stack;
  char stackSymbol;
  int openingBreketsCount = 0;
  int closingBreketsCount = 0;
  for (char symbol : lexems) 
  {
    if (symbol == '(')
    {
      stack.Push(symbol);
      openingBreketsCount++;
      continue;
    }
    else if (symbol == ')') 
    {
      stackSymbol = stack.Pop();
      closingBreketsCount++;
      while (stackSymbol != '(') 
      {
        postfix += stackSymbol;
        stackSymbol = stack.Pop();
      }
      continue;
    }
    else if ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/')) 
    {
      while (!stack.IsEmpty()) 
      {
        stackSymbol = stack.Pop();
        if (priority[symbol] <= priority[stackSymbol])
        {
          postfix += stackSymbol;
        }
        else 
        {
          stack.Push(stackSymbol);
          break;
        }
      }
      stack.Push(symbol);
      continue;
    }
    else 
    {
      operands.insert({ symbol,0.0 });
      postfix += symbol;
    }
  }
  while (!stack.IsEmpty()) 
  {
    stackSymbol = stack.Pop();
    postfix += stackSymbol;
  }
  if (openingBreketsCount != closingBreketsCount)
    throw "Err";
}

void TFormula::Parse()
{
  for (char c : infix)
    lexems.push_back(c);
}

TFormula::TFormula(string _infix)
{
  infix = _infix;
  priority = { {'+',1},{'-',1},{'*',2},{'/',2} };
  ToPostfix();
 
}

string TFormula::GetInfix() const
{
  return infix;
}

string TFormula::GetPostfix() const
{
  return postfix;
}

vector<char> TFormula::GetOperands() const
{
  vector <char> op;
  for (const auto& symbol : operands)
    op.push_back(symbol.first);
  return op;
}

double TFormula::Calculate(const map<char, double>& values)
{
  for (auto& val : values)
  {
    try 
    {
      operands.at(val.first) = val.second;
    }
    catch (out_of_range& e) {}
  }
  TStack <double> stack;
  double leftOperand, rightOperand;
  for (char lexem : postfix) 
  {
    if (lexem == '+')
    {
      if (stack.IsEmpty())
        throw "Err";
      rightOperand = stack.Pop();
      leftOperand = stack.Pop();
      stack.Push(leftOperand + rightOperand);
      continue;
    }
    else if (lexem == '-')
    {
      if (stack.IsEmpty())
        throw "Err";
      rightOperand = stack.Pop();
      leftOperand = stack.Pop();
      stack.Push(leftOperand - rightOperand);
      continue;
    }
    else if (lexem == '*')
    {
      if (stack.IsEmpty())
        throw "Err";
      rightOperand = stack.Pop();
      leftOperand = stack.Pop();
      stack.Push(leftOperand * rightOperand);
      continue;
    }
    else if (lexem == '/')
    {
      if (stack.IsEmpty())
        throw "Err";
      rightOperand = stack.Pop();
      leftOperand = stack.Pop();
      if (rightOperand == 0)
        throw "Err";
      stack.Push(leftOperand / rightOperand);
      continue;
    }
    else
      stack.Push(operands[lexem]);
  }
  return stack.Pop();
}
