/*
 * subseqmax.cpp
 *
 *  Created on: 15 de dez de 2017
 *      Author: ramide
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <vector>

unsigned long long count_ssm = 0;

using namespace std;

/* Pr�tica 10 - For�a Bruta -----------------*/

// start e finish: in�cio e final sendo testado agora;
// ini e end: onde s�o retornados o in�cio e final da melhor sequ�ncia
// retorno � a soma da maior sequ�ncia
int subseqMaxBF(const vector<int> &array, int &ini, int &end) {
	int n = array.size();
	int maior = 0;
	ini = 0;
	end = 0;

	for (int start = 0; start < n; start++) {
		for (int finish = start; finish < n; finish++) {
			int soma = 0;
			for (int z = start; z <= finish; z++) {
				soma += array[z];
			}
			if (soma > maior) {
				maior = soma;
				ini = start;
				end = finish;
			}
		}
	}

	return maior;
}

/* Pr�tica 11 - Dividir e Conquistar ----------------- */

int subseqMaxMiddle(const vector<int> &array, int start, int middle, int finish, int & ini, int & end) {
	// GIVEN
	int maxL = 0, maxR = 0;
	int sumL = 0, sumR = 0;

	ini = end = middle;

	for (int i = middle - 1; i >= start; i--) {
		count_ssm ++;
		sumL += array[i];
		if (sumL > maxL) {
			maxL = sumL;
			ini = i;
		}
	}

	for (int i = middle + 1; i <= finish; i++) {
		count_ssm ++;
		sumR += array[i];
		if (sumR > maxR) {
			maxR = sumR;
			end = i;
		}
	}

	return maxL + maxR + array[middle];
}

int subseqMaxDC_Rec(const vector<int> &array, int start, int finish, int & ini, int & end) {
	// TODO
	
	return -1;
}

int subseqMaxDC(const vector<int> &array, int & ini, int & end) {
	// GIVEN
	int len = (int)array.size();
	return subseqMaxDC_Rec(array, 0, len - 1, ini, end);
}

/* Pr�tica 12 - Rercusiva ----------------- */

int seqMax(const vector<int> &array, int pos, int & ini) {
	// GIVEN
	if (pos < 0) return 0;
	int sum, iniPrev;

	count_ssm ++;
	int x = array[pos];
	int sumPrev = x + seqMax(array, pos - 1, iniPrev);

	if ( x >= sumPrev) {		// come�a nova sequencia
		sum = array[pos];
		ini = pos;
	} else {				// continua sequencia anterior
		sum = sumPrev;
		ini = iniPrev;
	}

	return sum;
}

int subseqMaxRec(const vector<int> &array, int & ini, int & end) {
	// GIVEN
	int sum = 0;
	int len = (int)array.size();
	ini = end = -1;

	count_ssm = 0;

	for (int i = 0; i < len; i++) {
		int _ini, _sum;
		_sum = seqMax(array, i, _ini);

		if (_sum > sum) {
			sum = _sum;
			ini = _ini;
			end = i;
		}
	}

	return sum;
}

/* Pr�tica 12 - Memoization ----------------- */

int seqMaxMemo(const vector<int> &array, int pos, int & ini, vector<int> &SUM, vector<int> &INI) {
	// TODO
  

	return -1;
}

int subseqMaxMemo(const vector<int> &array, int & ini, int & end) {
	// TODO
	

	return -1;
}

/* Pr�tica 12 - Programa��o Din�mica ----------------- */

int subseqMaxPD(const vector<int> &array, int & ini, int & end) {
	// TODO
	

	return -1;
}

/* -------------------------------------- */

void runSubseqMax(const char * name, int subseqmax(const vector<int> &, int&, int&), const vector<int> & array, bool printSeq) {
	using namespace std::chrono;

	count_ssm = 0;

	int ini = 0, end = 0;

	auto start = high_resolution_clock::now();

	int max = subseqmax(array, ini, end);

	auto finish = high_resolution_clock::now();
	long elapsed = duration_cast<nanoseconds>(finish-start).count() / 1000;

	cout << name << ": " << max << " ";


	cout << "[time: "<< setw(6) << setfill(' ') << elapsed << "us] ";
	cout << "[count: " << setw(6) << setfill(' ') << count_ssm << "] ";

	if (printSeq) {
		cout << "[ ";
		for (int i = ini; i <= end; i++) cout << array[i] << " ";
		cout << "] ";
	}

	cout << endl;
}

// int main() {
int subseqmax() {
	bool printSeq = true;
	int size = 30;

	srand(12345);

	vector<int> array(size);

	cout << endl << "******* SUBSEQMAX *******" << endl << endl;

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < size; j++) {
			array[j] = (rand() % (3 * size)) - (rand() % (4 * size));
		}

		cout <<"Test " << i << ": ";
		if (printSeq) {
			for (auto v : array) cout << v << " ";
		}
		cout << endl;

		runSubseqMax("Bruteforce     ", subseqMaxBF, array, printSeq);
		runSubseqMax("Divide&Conquer ", subseqMaxDC, array, printSeq);
		runSubseqMax("Recursive      ", subseqMaxRec, array, printSeq);
		runSubseqMax("Memoization    ", subseqMaxMemo, array, printSeq);
		runSubseqMax("Dynamic Prog.  ", subseqMaxPD, array, printSeq);
	}

	return 0;
}
