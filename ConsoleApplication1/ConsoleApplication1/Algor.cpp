#include "pch.h"
#include "Algor.h"
using namespace std;



void Algor::additional(bool value[8], int index) {
	int temp1[8], temp2[8];
	bool tempo[8];
	for (int i = 0; i < 8; i++) {
		temp1[i] = vect[index].arr[i];
		temp2[i] = value[i];
	}
	for (int i = 7; i >= 0; i--) {
		temp1[i] += temp2[i];
		if (temp1[i] == 2) {
			temp1[i - 1] += 1;
			temp1[i] = 0;
		}
		if (temp1[i] == 3) {
			temp1[i - 1] += 1;
			temp1[i] = 1;
		}
	}
	for (int i = 0; i < 8; i++) { tempo[i] = temp1[i]; }
	push(tempo);
}

void Algor::setVectValue() {
	bool temp[8];
	for (int i = 0; i < 8; i++) temp[i] = 0;
	for (int i = 3; i >= 0; i--) {
		if (secondNumber[3]) temp[i + 4] = firstNumber[i];
		else temp[i + 4] = 0;
	}
	push(temp);					//0
	push(temp);					//1
	push(temp);					//2
	for (int i = 0; i < 8; i++) temp[i] = 0;
	for (int i = 3; i >= 0; i--) {
		if (secondNumber[2]) temp[i + 4] = firstNumber[i];
		else temp[i + 4] = 0;
	}
	push(temp);					//3
	rightShift(temp);
	push(temp);					//4
	additional(temp, 2);		//5
	for (int i = 0; i < 8; i++) temp[i] = 0;
	for (int i = 3; i >= 0; i--) {
		if (secondNumber[1]) temp[i + 4] = firstNumber[i];
		else temp[i + 4] = 0;
	}
	push(temp);					//6
	rightShift(temp);
	rightShift(temp);
	push(temp);					//7
	additional(temp, 5);		//8
	for (int i = 0; i < 8; i++) temp[i] = 0;
	for (int i = 3; i >= 0; i--) {
		if (secondNumber[0]) temp[i + 4] = firstNumber[i];
		else temp[i + 4] = 0;
	}
	push(temp);					//9
	rightShift(temp);
	rightShift(temp);
	rightShift(temp);
	push(temp);					//10
	additional(temp, 8);		//11
}


void Algor::showVector(int index) {
	for (int i = 0; i < 8; i++) {
		cout << vect[index].arr[i];
		if (i == 3) cout << " ";
	}
}


void Algor::push(bool ar[8]) {
	container cont;
	for (int i = 0; i < 8; i++) {
		cont.arr[i] = ar[i];
	}
	vect.push_back(cont);
}


void Algor::rightShift(bool mas[8]) {
	for (int i = 0; i < 7; i++) {
		bool temp = mas[i];
		mas[i] = mas[i + 1];
		mas[i + 1] = temp;
	}
}

void Algor::showInitialCondition() {
	cout << "\n\nПервый множитель: " << setw(2) << firstN << " = ";
	showFirst();
	cout << endl;
	cout << "Второй множитель: " << setw(2) << secondN << " = ";
	showSecond();
	cout << endl;
}


void Algor::showFirst() {
	for (int i = 0; i < 4; i++) {
		cout << firstNumber[i];
	}
}


void Algor::showSecond() {
	for (int i = 0; i < 4; i++) {
		cout << secondNumber[i];
	}
}

void Algor::showTable(int counter) {
	switch (counter) {
	default: cout << "  -----          |          -----          |          -----          |" << endl;
		break;
	}
}

void Algor::setResult() {
	for (int i = 7, j = 0; i >= 0; i--, j++) {
		Result += vect[11].arr[i] * pow(2, j);
	}
}

void Algor::showResult(int numOfpair) {
	cout << numOfpair + 1 << " пара: " << setw(2) << firstN << " * " << setw(2) << secondN << " = " << setw(3) << Result << " = ";
	for (int i = 0; i < 8; i++) {
		cout << vect[11].arr[i];
		if (i == 3)cout << " ";
	}
	cout << endl;
}