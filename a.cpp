#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define INF 1000000000
using namespace std;
typedef long double Ld;

Ld cal(Ld x, Ld y, int op) {
//0�����INF�Ŏ������Ă���̂ŁA0������ƃo�O�邱�Ƃ�����܂��B
	if (op == 0)return x + y;
	else if (op == 1)return x - y;
	else if(op==2)return x*y;
	else {
		if (!y)return INF;
		else return x / y;
	}
}

int main() {
	Ld a, b, c, d;
	cout << "X puzzle..." << endl;
	cout << "written by A.D.509" << endl;
	cout << "puts 4 number..." << endl;
	cout << "����0�������Ă���ꍇ�A����ɓ����Ȃ��ꍇ������܂�..." << endl;
	cout << "0��4�ŏI��" << endl;
	while (cin >> a >> b >> c >> d) {
		if (a == 0 && b == 0 && c == 0 && d == 0)break;
		cout << "What number do you want to make?" << endl;
		Ld n;
		cin >> n;
		vector<Ld>k;

		k.push_back(a);
		k.push_back(b);
		k.push_back(c);
		k.push_back(d);
		sort(k.begin(), k.end());

		string o[4] = { " + "," - "," * " ,"/"};
		int flg = 1;

		do {
			for (int i = 0; i<4; i++) {//op1
				for (int j = 0; j < 4; j++) {//op2
					for (int l = 0; l < 4; l++) {//op3
							Ld e = cal(cal(cal(k[0], k[1], i), k[2], j), k[3], l);
							Ld f = cal(cal(k[0], k[1], i), cal(k[2], k[3], l), j);
							Ld g = cal(cal(k[0], cal(k[1], k[2], j), i), k[3], l);
							Ld h = cal(k[0], cal(cal(k[1], k[2], j), k[3], l), i);
							Ld m = cal(k[0], cal(k[1], cal(k[2], k[3], l), j), i);

							if (e == n) {
								cout << "(((" << k[0] << o[i] << k[1] << ")" << o[j] << k[2] << ')' << o[l] << k[3] << ')' << endl;
									flg = 0;
									goto FINLOOP;
							}
							else if (f == n) {
								cout << "((" << k[0] << o[i] << k[1] << ')' << o[j] << '(' << k[2] << o[l] << k[3] << "))" << endl;
								flg = 0;
								goto FINLOOP;
							}
							else if (g == n) {
								cout << "((" << k[0] << o[i] << '(' << k[1] << o[j] << k[2] << "))" << o[l] << k[3] << ')' << endl;
								flg = 0;
								goto FINLOOP;
							}
							else if (h == n) {
								cout << "(" << k[0] << o[i] << "((" << k[1] << o[j] << k[2] << ")" << o[l] << k[3] << "))" << endl;
								flg = 0;
								goto FINLOOP;
							}
							else if (m == n) {
								cout << "(" << k[0] << o[i] << "(" << k[1] << o[j] << "(" << k[2] << o[l] << k[3] << ")))" << endl;
								flg = 0;
								goto FINLOOP;
							}
					}
				}
			}
		} while (next_permutation(k.begin(), k.end()));

	FINLOOP:;
		if (flg == 1)cout << "No Answer" << endl;
	}
	return 0;
}
