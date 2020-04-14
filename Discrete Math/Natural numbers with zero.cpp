#include "Natural numbers with zero.h"
#include <iostream>
using namespace std;

//N-1 �����: ������� ��������
/*
    ��������� ����������� �����: 2 - ���� ������ ������ �������, 0, ���� �����, 1 �����

    ��������� �� ���� 2 ����������� �����
*/
const int COM_NN_D(const unsigned long int& n, const unsigned long int& m) {
    return n > m ? 2 : m > n ? 1 : 0;
}

//N-2 �����: ��������� ����������
/*
    �������� �� ����: ���� ����� �� ����� ����, �� ��� ����� ����

    ��������� �� ���� ����������� �����
*/
void NZER_N_B(const unsigned long int& n) {
    cout << (n != 0 ? "��" : "���") << endl;
}

//N-3 �����: ���� ���������
/*
    ���������� 1 � ������������ �����

    ��������� �� ���� ���������� �����
*/
const unsigned long int ADD_1N_N(const unsigned long int& n) {
    return n + 1;
}

//N-4 �����: ������� ��������
/*
    �������� ����������� �����

    ��������� �� ���� 2 ����������� �����
*/
const unsigned long int ADD_NN_N(const unsigned long int& n, const unsigned long int& m) {
    return n + m;
}

//N-5 �����: ��������� ����������
/*
    ��������� �� ������� �������� ������������ ����� ������� �������� ��� �������
    ���������� COM_NN_D

    ��������� �� ���� 2 ����������� �����
*/
const unsigned long int SUB_NN_N(const unsigned long int& n, const unsigned long int& m) {
    return COM_NN_D(n, m) == 2 ? n - m : COM_NN_D(n, m) == 1 ? m - n : 0;
}

//N-6 �����: ���� ���������
/*
    ��������� ������������ ����� �� �����

    �������� �� ���� ����������� ����� � �����
*/
const long int MUL_ND_N(const unsigned long int& n, const long int& m) {
    return n * m;
}

//N-7 �����: ������� ��������
/*
    ��������� ������������ ����� �� 10^k

    ��������� �� ���� ���������� ����� � ������� � ������� ��� ����� ���������
*/
const unsigned long int MUL_Nk_N(const unsigned long int& n, const unsigned int& k) {
    return n * pow(10, k);
}

//N-8 �����: ��������� ����������
/*
    ��������� ����������� �����

    ��������� �� ���� 2 ����������� �����
*/
const unsigned long int MUL_NN_N(unsigned long int n, unsigned long int m) {
    if (n == 0 || m == 0) return 0;
    int digit = 0;
    unsigned long int number1 = n < m ? n : m, number2 = n > m ? n : m, composition = 0;
    while (number1 > 0) {
        ++digit;
        number1 /= 10;
    }
    number1 = n < m ? n : m;

    for (int i = digit - 1; i >= 0; --i) {
        composition = ADD_NN_N(composition, MUL_ND_N(number2, number1 / MUL_Nk_N(1, i) * MUL_Nk_N(1, i)));
        number1 %= MUL_Nk_N(1, i);
    }

    return composition;
}

//N-9 �����: ���� ���������
/*
    ��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������
    � ��������������� �����������
    � ������, ���� ��������� ���������� ����������, ���������� -1

    ��������� �� ����:
        1. ����������� ����� �� �������� ��������
        2. ����������� ����� ������� ��������
        3. ����������� ��� ������� ������������  ����� � ����� ������
*/
const long int SUB_NDN_N(const unsigned long int& n, const unsigned long int& m, const long int& k) {
    if (k > 0 && 1 == COM_NN_D(n, MUL_ND_N(m, k))) return -1;
    return k > 0 ? SUB_NN_N(n, MUL_ND_N(m, k)) : k < 0 ? ADD_NN_N(n, MUL_ND_N(m, -k)) : 0;
}

//N-10 �����: ������� ��������
/*
    ���������� ������ ����� ������� �������� ������������ �� �������, ����������� �� 10^k,
    ��� k - ����� ������� ���� ����� (����� ��������� � ����)

    �� ���� ����������� 2 ����������� ����� � ������������� �������
*/
const unsigned long int DIV_NN_Dk(unsigned long int& n, unsigned long int& m, unsigned int& k) {
    unsigned long int d = 10;
    d = n > m ? n / MUL_Nk_N(m, k) : m / MUL_Nk_N(n, k);
    while (d > 9) d = d / 10;
    return d;
}

//�����: ���� ���������
/*
    ������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � 
    ��������(�������� ������� �� ����)
    ���������� ����� ����� ������ � ������� ������� �� ������� ����� ����� �� ������ ����������� �����

    ��������� �� ���� 2 ����������� �����
*/
const unsigned long int  MOD_NN_N(const unsigned long int& n, const unsigned long int& m) {
    return n > m ? n % m : m % n;
}

//�����: ���� ���������
/*
    ��� ���� ����������� �����

    ��������� �� ���� 2 ����������� �����
*/
const unsigned long int  LCM_NN_N(const unsigned long int& n, const unsigned long int& m) {
    return 0;
    //return n * m / nod(n, m);
}