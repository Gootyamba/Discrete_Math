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

	��������� ����������� ����������� �����
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
	cout << endl << "���������� ��������: " << n->n << endl;
}

//�����: ����� �����
/*
	�������� ������������ ����� �� ������������ ������
*/
NN* delNN(NN* n) {
	n->a.clear();
	delete n;
	return nullptr;
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

//N-4 �����: ������� ��������
/*
	�������� ����������� �����
	��� �������� �������������� ������� COM_NN_D

	��������� �� ���� 2 ����������� �����
*/
NN* ADD_NN_N(NN* n, NN* m) {
	NN* res = new NN();
	res->a.erase(res->a.begin());
	for (int i = 0; i < (COM_NN_D(n, m) == 2 ? n->n : m->n); ++i) {
		//���� ���������� ������� � ���� 3 ���������
		if (n->n > i && m->n > i && res->n > i)
			//���� ����� ����� �������� ������ 10
			if (n->a[i] + m->a[i] + res->a[i] - 3 * '0' < 10) res->a[i] += n->a[i] + m->a[i] - 2 * '0';
			else {
				++res->n;
				res->a[i] = res->a[i] + n->a[i] + m->a[i] - 2 * '0' - 10;
				res->a.push_back('1');
			}
		//���� ���������� ������� ������ � ���������
		else if (n->n > i && m->n > i) 
			//���� ����� �������� ��������� ������ 10
			if (n->a[i] + m->a[i] - 2 * '0' < 10) {
				++res->n;
				res->a.push_back(n->a[i] + m->a[i] - '0');
			}
			else {
				res->n += 2;
				res->a.push_back(n->a[i] + m->a[i] - '9' - 1);
				res->a.push_back('1');
			}
		//���� ���������� ������� � ������ �� ���� ���������
		else
			//���� ���������� ������ ����������
			if (res->n > i)
				//���� ����� �������� ������ 10
				if (res->a[i] + (n->n > m->n ? n->a[i] : m->a[i]) - 2 * '0' < 10) res->a[i] += (n->n > m->n ? n->a[i] : m->a[i]) - '0';
				else {
					++res->n;
					res->a[i] += (n->n > m->n ? n->a[i] : m->a[i]) - '0' - 10;
					res->a.push_back('1');
				}
			else {
				++res->n;
				res->a.push_back(n->n > m->n ? n->a[i] : m->a[i]);
			}
	}

	if (res->a.size() == 0) res->a.push_back('0');

	return res;
}

//N-5 �����: ��������� ����������
/*
	��������� �� ������� �������� ������������ ����� ������� �������� ��� �������
	���������� COM_NN_D

	��������� �� ���� 2 ����������� �����
*/
NN* SUB_NN_N(NN* n, NN* m) {
	NN* res = new NN();
	if (COM_NN_D(n, m) == 0) return res;

	res->a.erase(res->a.begin());
	bool swap = false;
	if (COM_NN_D(n, m) == 1) {
		NN* temp = n;
		n = m;
		m = temp;
		swap = true;
	}

	for (int i = 0; i < n->n; ++i) {
		//���� ���������� ������� �����������
		if (m->n > i) {
			//���� ���������� ������� � ������
			if (res->n > i) {
				//���� �������� ������ ������������ ������ �������� ������� �����������
				if (n->a[i] > m->a[i]) {
					res->a[i] += n->a[i] - m->a[i] + '0';
				}
				//���� �������� ������ ������������ ������ ��� ����� �������� ������� �����������
				else {
					res->a[i] += n->a[i] + 10 - m->a[i] + '0';
					//��������
					int ind = i;
					do {
						//���� ���������� ������� � ������
						if (res->n > ind) {
							--res->a[i];
						}
						//���� � ������ ��� ��������
						else {
							++res->n;
							res->a.push_back(-1);
						}
					} while (n->a[++ind] == '0');
				}
			}
			//���� �������� � ������ ���
			else {
				//���� �������� ������ ������������ ������ ��� ����� �������� ������� �����������
				if (n->a[i] >= m->a[i]) {
					++res->n;
					res->a.push_back(n->a[i] - m->a[i] + '0');
				}
				//���� �������� ������ ������������ ������ �������� ������� �����������
				else {
					++res->n;
					res->a.push_back(n->a[i] + 10 - m->a[i] + '0');
					//�������� ���������
					int ind = i;
					do {
						++res->n;
						res->a.push_back(-1);
					} while (n->a[++ind] == '0');
				}
			}
		}
		//���� �������� ����������� �� ���������� 
		else {
			//���� ���������� ������� � ������
			if (res->n > i) {
				res->a[i] = '9' + 1 + res->a[i] + n->a[i] -'0';
				if (res->a[i] == '9' + 1) res->a[i] = '0';
			}
			//���� �������� � ������ �� ����������
			else {
				++res->n;
				res->a.push_back(n->a[i]);
			}
		}
	}

	//�������� ����� ������� �����
	while (res->a[res->n - 1] == '0') {
		--res->n;
		res->a.erase(res->a.end() - 1);
	}

	if (swap) {
		NN* temp = n;
		n = m;
		m = temp;
	}

	return res;
}

//N-6 �����: ���� ���������
/*
	��������� ������������ ����� �� �����

	��������� �� ���� ����������� ����� � �����
*/
NN* MUL_ND_N(NN* n, const char& num) {
	NN* res = new NN;
	if (n->n == 0 || num == '0') return res;
	res->a.erase(res->a.begin());

	for (int i = 0; i < n->n; ++i) {
		//���� ������ ������ ����������
		if (res->n > i) {
			//���� ������������ ������ 8
			if ((n->a[i] - '0') * (num - '0') < 8) {
				res->a[i] += (n->a[i] - '0') * (num - '0') + '0';
			}
			//���� ������������ ������ 8
			else {
				++res->n;
				res->a.push_back(((n->a[i] - '0') * (num - '0') + res->a[i]) / 10);
				res->a[i] = ((n->a[i] - '0') * (num - '0') + res->a[i]) % 10 + '0';
			}
		}
		//���� ������ ������ �� ����������
		else {
			//���� ������������ ������ 10
			if ((n->a[i] - '0') * (num - '0') < 10) {
				++res->n;
				res->a.push_back((n->a[i] - '0') * (num - '0') + '0');
			}
			//���� ������������ ������ 10
			else {
				res->n += 2;
				res->a.push_back((n->a[i] - '0') * (num - '0') % 10 + '0');
				res->a.push_back((n->a[i] - '0') * (num - '0') / 10);
			}
		}
	}

	if (res->a[res->n - 1] < '0') res->a[res->n - 1] += '0';

	return res;
}

//N-7 �����: ������� ��������
/*
	��������� ������������ ����� �� 10^k

	��������� �� ���� ���������� ����� � ������� � ������� ��� ����� ���������
*/
NN* MUL_Nk_N(NN* n, const unsigned int& k) {
	NN* res = new NN();
	if (n->n == 0) return res;
	res->a.erase(res->a.begin());
	res->n = n->n + k;
	for (int i = 0; i < n->n; ++i) res->a.push_back(n->a[i]);
	for (int i = 0; i < k; ++i) res->a.emplace(res->a.cbegin(), '0');
	return res;
}