#include <iostream>
#include <cstdlib>
#include "DynamicArray.h"

using namespace std;

const double growthFactor = 1.5;

//���������� �������� � ������
void DynamicArray::Add(int element)
{
	Length++;

	if (Length >= Capacity)
	{
		Resize();
	}

	Array[Length - 1] = element;
	IsSorted = false;
}

//��������� ������� ������ ��� �������
void DynamicArray::Resize()
{
	//TODO: �������� ��������� ����� �����������(Done)
	if (Length >= Capacity)
	{
		Capacity = Length * growthFactor;
	}
	else if (Length > 4)
	{
		Capacity = Length;
	}
	else
	{
		return;
	}

	int* newArray = new int[Capacity];
	for (int i = 0; i < Length; i++)
	{
		newArray[i] = Array[i];
	}

	delete[] Array;
	Array = newArray;
}

//���������� ������� �������
void DynamicArray::InsertionSort()
{
	for (int i = 0; i < Length; i++)
	{
		for (int j = i + 1; j < Length; j++)
		{
			if (Array[j] < Array[i])
			{
				int temp = Array[j];
				Array[j] = Array[i];
				Array[i] = temp;
			}
		}
	}

	IsSorted = true;
}

//������� �������� � ������ �� �������
void DynamicArray::Insert(int element, int index)
{
	Length++;

	if (Length >= Capacity)
	{
		Resize();
	}

	for (int i = Length - 1; i > index; i--)
	{
		Array[i] = Array[i - 1];
	}

	Array[index] = element;
}

//�������� �������� �� ������� �� �������
void DynamicArray::Delete(int index)
{
	for (int i = index; i < Length - 1; i++)
	{
		Array[i] = Array[i + 1];
	}

	Length--;
	Resize();
}

//�������� ����� �������� � �������
int DynamicArray::LineSearch(int element)
{
	for (int i = 0; i < Length; i++)
	{
		if (Array[i] == element)
		{
			return i;
		}
	}

	return -1;
}

//�������� ����� �������� � �������
int DynamicArray::BinarySearch(int element)
{
	int first = 0;
	int last = Length;
	//TODO: ������ �����?(Done)

	while (first < last)
	{
		int middle = (first + last) / 2;
		if (element <= Array[middle])
		{
			last = middle;
		}
		else
		{
			first = middle + 1;
		}
	}

	if (first == Length || Array[first] != element)
	{
		return -1;
	}
	else
	{
		return first;
	}
}

// ��������: ������ ������(true) ��� ���(false)
bool DynamicArray::IsEmpty()
{
	return Length == 0;
}

//����� ������� �� �����
//TODO: RSDN(Done)
void Print(DynamicArray* array) 
{
	cout << "\n���������� ������: ";
	for (int i = 0; i < array->Length; i++)
	{
		cout << array->Array[i] << " ";
	}
	cout << "\n";
}