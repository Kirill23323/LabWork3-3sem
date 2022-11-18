#include <iostream>
#ifndef TStack_H 
#define TStack_H
template<class T>
class TStack
{
protected:
	int top; // индекс вершины стека
	size_t memSize; // размер памяти для массива
	T* pMem; // указатель на массив элементов
public:
	TStack(); // конструктор по умолчанию
	TStack(size_t _memSize); // конструктор инициализатор
	TStack(const TStack <T>& p); // конструктор копирования
	TStack(TStack&& p); // конструктор перемещения
	~TStack(); // деструктор
	bool IsFull(void) const; // контроль переполнения
	bool IsEmpty() const; // контроль пустоты
	void Push(const T& value); // добавить значение
	int Size() const; // Возвращает количество элементов  стека
	T TopElem() const; // Возвращает верхний элемент стека
	T Pop();  // извлечь значение
};

template<class T>
inline TStack<T>::TStack()
{
	top = -1;
	memSize = 1;
	pMem = new T[memSize];
}

template<class T>
inline TStack<T>::TStack(size_t _memSize)
{
		top = -1;
		memSize = _memSize;
		pMem = new T[memSize];
}

template<class T>
inline TStack<T>::TStack(const TStack<T>& p)
{
	if (p.pMem == 0) 
	{
		pMem = 0;
		memSize = 0;
		top = -1;
	}
	else 
	{
		memSize = p.memSize;
		top = p.top;
		pMem = new T[memSize];
		for (int i = 0; i < Size(); i++) 
		{
			pMem[i] = p.pMem[i];
		}
	}
}

template<class T>
inline TStack<T>::TStack(TStack&& p)
{
	pMem = p.pMem;
	memSize = p.memSize;
	top = p.top;
	p.pMem = nullptr;
	p.memSize = 0;
	p.top = 0;
}

template<class T>
inline TStack<T>::~TStack()
{
	if (pMem != 0) 
	{
		delete []pMem;
		pMem = 0;
	}
	memSize = 0;
	top = -1;
}

template<class T>
inline bool TStack<T>::IsFull(void) const
{
	return  top + 1 == memSize;
}


template<class T>
inline bool TStack<T>::IsEmpty() const
{
	return top + 1 == 0;
}

template<class T>
inline void TStack<T>::Push(const T& value)
{
	if (IsFull()) 
	{
		T* tmpMem = new T[memSize * 2];
		std::copy(pMem, pMem + memSize, tmpMem);
		delete[]pMem;
		pMem = tmpMem;
		memSize *= 2;
	}
	pMem[++top] = value;
}

template<class T>
inline int TStack<T>::Size() const
{
	return top + 1;
}

template<class T>
inline T TStack<T>::TopElem() const
{
	if (IsEmpty())
		throw "Err";
	else
		return pMem[top];
}

template<class T>
inline T TStack<T>::Pop()
{
	if (IsEmpty())
		throw "Err";
	return pMem[top--];
}
#endif

