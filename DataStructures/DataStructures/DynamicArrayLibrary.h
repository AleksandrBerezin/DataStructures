#pragma once

#include <iostream>
#include "DynamicArray.h"

using namespace std;

/*
	������� ��� ������������� �������
*/

//��������, ��� ������ �� ������ ��� ����
bool IsArrayNotCreateOrEmpty(DynamicArray* array)
{
	if (array == nullptr || array->IsEmpty())
	{
		cout << "������ ������� ���������.\n";
		return true;
	}

	return false;
}

//��������, ��� ������ ����
bool IsArrayEmpty(DynamicArray* array)
{
	if (array->IsEmpty())
	{
		cout << "������ ������� ���������.\n";
		return true;
	}

	return false;
}

//��������, ���� ������ ��� �� ������, �� ���������
void CheckArrayOnCreate(DynamicArray* array)
{
	if (array == nullptr)
	{
		array = new DynamicArray();
	}
}

//����� ������� �� �����
void Print(DynamicArray* array)
{
	cout << "\n���������� ������: ";
	for (int i = 0; i < array->Length; i++)
	{
		cout << array->Array[i] << " ";
	}
	cout << "\n";
}