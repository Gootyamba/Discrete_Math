#include <iostream>
#include <vector>
#include <conio.h>
#include "NN.h"
using namespace std;

constexpr unsigned char Enter = 13, Backspace = 8, Esc = 27;

/*
	��������� ������
	sign - ���������� ����������, ���������� �� ���� �����: + = true, - = false
	n - ����� ������� ������� �������
	a - ������ �������� � �����
*/
struct Z {
	bool sign = true;
	int n = 0;
	vector<char> a = { '0' };
};

//�����: ����� �����
/*
	���������� ������ �����

	��������� ����������� ����� �����
*/
Z* readZ() {
	char ch;
	Z* num = new Z();
	do {
		cout << "���� �����: " << (num->n > 0 ? (num->sign ? "+" : "-") : "");
		for (int i = num->a.size() - 1; i >= 0; --i) cout << num->a[i];
		cout << endl << "���������� ��������: " << num->n << endl;

		ch = _getch();

		//���������� ����� � ����o
		if (ch >= '0' && ch <= '9') {
			if (num->n == 0 && ch != '0') {
				num->a[0] = ch;
				++num->n;
			}
			else if (num->n != 0) {
				num->a.emplace(num->a.cbegin(), ch);
				++num->n;
			}
		}

		//��������� ����� �����
		if (ch == '+' && !num->sign) num->sign = true;
		if (ch == '-' && num->sign) num->sign = false;

		//�������� ����� �� �����
		if (ch == Backspace && num->n > 0) {
			if (num->n == 1) num->a[0] = '0';
			else num->a.erase(num->a.cbegin());
			--num->n;
		}

		system("cls");
	} while (ch != Enter && ch != Esc);
	return num;
}

//�����: ����� �����
/*
	������� ������������ ����� �� �����
*/
void printZ(Z* n) {
	if (n != nullptr) {
		cout << "���� �����: " << (n->n > 0 ? (n->sign ? "+" : "-") : "");
		for (int i = n->a.size() - 1; i >= 0; --i) cout << n->a[i];
		cout << endl << "���������� ��������: " << n->n << endl;
	}
	else cout << "����� �� ����������" << endl;
}

//�����: ����� �����
/*
	�������� ������������ ����� �� ������������ ������
*/
Z* delZ(Z* n) {
	if (n != nullptr) {
		n->a.clear();
		delete n;
		return nullptr;
	}
	else cout << "����� �� ����������." << endl;
}