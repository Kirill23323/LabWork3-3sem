#include <iostream>
#ifndef TQueue_H 
#define TQueue_H
template<class T>
class TQueue 
{
protected:
	int start; //индекс начала очереди
	int end; // индекс конца очереди
	T* pMem; // указатель на массив элементов
	size_t memSize; // размер памяти для массива
	int dataCount; // кол - во элементов в очереди
public:
	TQueue(); // конструктор по умолчанию
	TQueue(size_t _memSize); // конструктор инициализатор
	~TQueue(); // деструктор
	TQueue(const TQueue<T>& p); // конструктор копирования
	TQueue(TQueue&& p); // конструктор перемещения
	bool IsFull(void) const; // контроль переполнения
	bool IsEmpty() const; // контроль пустоты
	void Push(const T value); // добавить значение
	int Size(); //  количество элементов в очереди
	T StartElem(); //   элемент в начале очереди
	T Pop(); // извлечь значение

};

template<class T>
inline TQueue<T>::TQueue()
{
	start = 0;
	end = -1;
	memSize = 1;
	pMem = new T[memSize];
	dataCount = 0;
}

template<class T>
inline TQueue<T>::TQueue(size_t _memSize)
{
	if (_memSize > 0)
	{
		start = 0;
		end = -1;
		memSize = _memSize;
		pMem = new T[memSize];
		dataCount = 0;
	}
	else
		throw "Err";
}

template<class T>
inline TQueue<T>::~TQueue()
{
	if (pMem != 0) 
	{
		delete [] pMem;
		pMem = 0;
	}
	memSize = 0;
	start = 0;
	end = -1;
	dataCount = 0;
}

template<class T>
inline TQueue<T>::TQueue(const TQueue<T>& p)
{
	if (p.pMem == 0) 
	{
		pMem = 0;
		memSize = 0;
		start = 0;
		end = -1;
		dataCount = 0;
	}
	else 
	{
		memSize = p.memSize;
		start = p.start;
		end = p.end;
		dataCount = p.dataCount;
		pMem = new T[memSize];
		for (int i = 0; i < dataCount; i++) 
		{
			pMem[i] = p.pMem[i];
		}
	}
}

template<class T>
inline TQueue<T>::TQueue(TQueue&& p)
{
	pMem = p.pMem;
	start = p.start;
	end = p.end;
	memSize = p.memSize;
	dataCount = p.dataCount;
	p.pMem = nullptr;
	p.start = p.end = p.memSize = p.dataCount = 0;
}

template<class T>
inline bool TQueue<T>::IsFull(void) const
{
	return dataCount == memSize;
}

template<typename T>
inline bool TQueue<T>::IsEmpty() const
{
	return dataCount == 0;
}

template<class T>
inline void TQueue<T>::Push(const T value)
{
	if (IsFull())
		throw "Err";
	pMem[++end] = value;
	dataCount++;
}

template<class T>
inline int TQueue<T>::Size()
{
	return dataCount;
}

template<class T>
inline T TQueue<T>::StartElem()
{
	if (IsEmpty())
		throw "Err";
	else
		return pMem[start];
}

template<class T>
inline T TQueue<T>::Pop()
{
	if (IsEmpty())
		throw "Err";
	dataCount--;
	return pMem[start++];
}
#endif


