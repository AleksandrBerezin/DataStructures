#include <iostream>
#include "Treap.h"
#include "TreapNode.h"
#include "MenuTreap.h"
#include "Functions.h"

using namespace std;

bool IsTreapNotCreateOrEmpty(Treap* treap);

void Menu(Treap*& treap)
{
	bool isBack = false;

	while (!isBack)
	{
		cout << "\n�������� �������:\n";
		cout << "1. ���������� �������� � �������������� " <<
			"������������������� ���������.\n"
			<< "2. ���������� �������� � �������������� " <<
			"����������������� ���������.\n"
			<< "3. �������� �������� � �������������� " <<
			"������������������� ���������.\n"
			<< "4. �������� �������� � �������������� " <<
			"����������������� ���������.\n"
			<< "5. ����� ��������.\n"
			<< "6. �������� ������.\n"
			<< "7. ����� ������ �� �����.\n"
			<< "0. �����.\n\n";

		switch (InputInt())
		{
			case 1:
			{
				if (treap == nullptr)
				{
					treap = new Treap();
				}

				cout << "������� ���� ��������: ";
				int key = InputInt();
				cout << "\n";

				TreapNode* node;

				do
				{
					node = treap->Find(key);

					if (node != nullptr)
					{
						cout << "������� � ����� ������ ������������ "
							<< "� ������, ������� ������ ����: ";
						key = InputInt();
						cout << "\n";
					}
				} while (node != nullptr);

				treap->SlowInsert(key);
				Print(treap->Root, 0);
				break;
			}
			case 2:
			{
				if (treap == nullptr)
				{
					treap = new Treap();
				}

				cout << "������� ���� ��������: ";
				int key = InputInt();
				cout << "\n";

				TreapNode* node;

				do
				{
					node = treap->Find(key);

					if (node != nullptr)
					{
						cout << "������� � ����� ������ ������������ "
							<< "� ������, ������� ������ ����: ";
						key = InputInt();
						cout << "\n";
					}
				} while (node != nullptr);
				srand(time(nullptr));
				int priority = rand() % 100;

				treap->FastInsert(treap->Root, nullptr, key, priority);
				Print(treap->Root, 0);
				break;
			}
			case 3:
			{
				if (IsTreapNotCreateOrEmpty(treap))
				{
					break;
				}

				cout << "������� ���� ��������: ";
				int key = InputInt();
				cout << "\n";

				treap->SlowRemove(key);
				Print(treap->Root, 0);
				break;
			}
			case 4:
			{
				if (IsTreapNotCreateOrEmpty(treap))
				{
					break;
				}

				cout << "������� ���� ��������: ";
				int key = InputInt();
				cout << "\n";

				treap->FastRemove(treap->Root, nullptr, key);
				Print(treap->Root, 0);
				break;
			}
			case 5:
			{
				if (IsTreapNotCreateOrEmpty(treap))
				{
					break;
				}

				cout << "������� ���� ��������: ";
				int key = InputInt();

				TreapNode* node = treap->Find(key);

				if (node == nullptr)
				{
					cout << "������ �������� ���.\n";
				}
				else
				{
					cout << "������� ������, ���� = " << node->Key
						<< ", ��������� = " << node->Priority << ".\n";
				}

				break;
			}
			case 6:
			{
				if (treap == nullptr)
				{
					break;
				}

				treap->Clear(treap->Root);
				delete treap;
				treap = nullptr;
				break;
			}
			case 7:
			{
				if (IsTreapNotCreateOrEmpty(treap))
				{
					break;
				}

				cout << "\n";
				Print(treap->Root, 0);
				break;
			}
			case 0:
			{
				isBack = true;
				break;
			}
			default:
			{
				cout << "������ �������� �������, ���������� ��� ���.\n";
				break;
			}
		}
	}

	return;
}

//��������, ��� ���� �� ������ ��� ����
bool IsTreapNotCreateOrEmpty(Treap* treap)
{
	if (treap == nullptr || treap->IsEmpty())
	{
		cout << "������ ������.\n";
		return true;
	}

	return false;
}