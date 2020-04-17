#ifndef NN_H
#define NN_H

struct NN;

//����� �����
NN* readNN();
void printNN(NN* n);
NN* delNN(NN* n);

//������� ��������
int COM_NN_D(NN* n, NN* m);
NN* ADD_NN_N(NN* n, NN* m);
NN* MUL_Nk_N(NN* n, const unsigned int& k);

//��������� ����������
void NZER_N_B(NN* n);
NN* SUB_NN_N(NN* n, NN* m);

//���� ���������
NN* ADD_1N_N(NN* n);
NN* MUL_ND_N(NN* n, const char& num);

#endif