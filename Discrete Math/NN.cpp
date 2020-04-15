#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

constexpr unsigned char Enter = 13, Backspace = 8, Esc = 27, Delete = 83, Up = 72, Down = 80, Left = 75, Right = 77;
char ch;

/*
	��������� ������
	n - ����� ������� ������� �������
	a - ������ �������� � �����
*/
struct NN {
	int n = 0;
	vector<char> a = { '0' };
};

//�����: ����� �����
/*
	���������� ������������ �����

	��������� ������������ ����������� �����
*/
NN* readNN() {
	NN* num = new NN();
	do {
		cout << "���� �����: ";
		for (int i = num->a.size() - 1; i >= 0; --i) cout << num->a[i];
		cout << endl << "���������� ��������: " << num->n << endl;

		ch = _getch();

		//���������� ����� � ����o
		if (ch >= '0' && ch <= '9') {
			if (num->n == 0 && ch != '0') {
				num->a[0] = ch;
				++num->n;
			}
			else if (num->n != 0){
				num->a.emplace(num->a.cbegin(), ch);
				++num->n;
			}
		}

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
void printNN(NN* n){
	cout << "���� �����: ";
	for (int i = n->a.size() - 1; i >= 0; --i) cout << n->a[i];
	cout << endl;
}

//N-1 �����: ������� ��������
/*
    ��������� ����������� �����: 2 - ���� ������ ������ �������, 0, ���� �����, 1 �����

    ��������� �� ���� 2 ����������� �����
*/
int COM_NN_D(NN* n, NN* m) {
	if (n->a.size() > m->a.size()) return 2;
	else if (n->a.size() < m->a.size()) return 1;

	for (int i = n->a.size() - 1; i > 0; --i) {
		if (n->a[i] > m->a[i]) return 2;
		else if (n->a[i] < m->a[i]) return 1;
	}

	return 0;
}

//N-2 �����: ��������� ����������
/*
	�������� �� ����: ���� ����� �� ����� ����, �� ��� ����� ����

	��������� �� ���� ����������� �����
*/
void NZER_N_B(NN* n) {
	cout << (n->n != 0 ? "��" : "���") << endl;
}

//N-3 �����: ���� ���������
/*
	���������� 1 � ������������ �����

	��������� �� ���� ���������� �����
*/
NN* ADD_1N_N(NN* n) {
	for (int i = 0; i < n->a.size(); ++i)
		if (n->a[i] < '9') {
			++n->a[i];
			break;
		}
		else {
			n->a[i] = '0';
			if (i < n->a.size() - 1) {
				++n->a[i + 1];
				if (n->a[i + 1] < '9') break;
			}
			else {
				n->a.push_back('1');
				++n->n;
			}
		}

	return n;
}