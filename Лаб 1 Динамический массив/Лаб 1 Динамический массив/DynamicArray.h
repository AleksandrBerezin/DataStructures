#pragma once
struct DynamicArray
{
	int Length;
	int Capacity;
	int* Array;

	void Add(int element);
	void Resize();
	//TODO: Naming
	void Sort();
	void Insert(int element, int index);
	void Delete(int index);
	int LineSearch(int element);
	int BinarySearch(int element);

	bool IsSorted;

	DynamicArray()
	{
		Length = 0;
		Capacity = 4;
		Array = new int[Capacity];
		IsSorted = false;
	}
};

void Print(DynamicArray* array);