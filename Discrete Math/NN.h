#ifndef NN_H
#define NN_H

struct NN;

//����� �����
NN* readNN();
void printNN(NN* n);

//������� ��������
int COM_NN_D(NN* n, NN* m);

//��������� ����������
void NZER_N_B(NN* n);

//���� ���������
NN* ADD_1N_N(NN* n);


#endif