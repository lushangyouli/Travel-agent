#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include"head.h"

Route mat[10][10][6];//ʱ�̱�

int main()
{
	using namespace std;
	int i, j, k, temp;
	int a, choice;
	int start_time, limit_time, flag;
	input(mat);
	int less_money[10][10];//���ʱ�̱���ÿ�Գ��м�۸����ٵĽ�ͨ���ߵļ�Ǯ
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (i != j) {
				temp = mat[i][j][0].cost;
				for (k = 0; k < 6; k++) {
					if (mat[i][j][k].cost < temp)
						temp = mat[i][j][k].cost;
				}
				less_money[i][j] = temp;
			}
			else
				less_money[i][j] = 0;
		}
	}
	ofstream fout("daily.txt");
	Plan plan;
	Tour traveler,tour_temp;
	fout << "����Ϊ����������־\n\n";
	cout << "-------------------------------------------------------------\n";
	cout << "              *��ʼ��������ģ�����*" << endl;
	fout << "-------------------------------------------------------------\n";
	fout << "              *��ʼ��������ģ�����*" << endl;
	
	do {
		cout << "-------------------------------------------------------------\n";
		cout << "�����б�0-����   1-�Ϻ�   2-����   3-������   4-����   5-���   6-����   7-�ɶ�   8-����   9-�人" << endl;
		cout << "��������ʼ���ж�Ӧ������";
		fout << "-------------------------------------------------------------\n";
		fout << "�����б�0-����   1-�Ϻ�   2-����   3-������   4-����   5-���   6-����   7-�ɶ�   8-����   9-�人" << endl;
		fout << "��������ʼ���ж�Ӧ������";
		cin >> traveler.startnode;
		fout << traveler.startnode << endl;
		cout << "��������ֹ���ж�Ӧ������";
		fout << "��������ֹ���ж�Ӧ������";
		cin >> traveler.arrivenode;
		fout << traveler.arrivenode << endl;
		cout << "��������Ҫ;�����ж�Ӧ�������ո������-1����):";
		fout << "��������Ҫ;�����ж�Ӧ�������ո������-1����):";
		i = 0;
		cin >> a;
		while (a != -1) {
			traveler.passnode[i] = a;
			fout << traveler.passnode[i] << "  ";
			i++;
			cin >> a;
		}
		fout << endl;
		for (; i < 9; i++) {
			traveler.passnode[i] = -1;
		}
		cout << "���в���:" << endl;
		cout << "1�����ٻ��Ѳ��ԡ�" << endl;
		cout << "2������ʱ����ԡ�" << endl;
		cout << "3����ʱ���ٷ��ò��ԡ�" << endl;
		cout << "��ѡ�����в���:";
		fout << "���в���:" << endl;
		fout << "1�����ٻ��Ѳ��ԡ�" << endl;
		fout << "2������ʱ����ԡ�" << endl;
		fout << "3����ʱ���ٷ��ò��ԡ�" << endl;
		fout << "��ѡ�����в���:";
		cin >> choice;
		fout << choice << endl;
		if (choice == 1) {
			cout << "���������з���:" << endl;
			fout << "���������з���:" << endl;
			if (traveler.passnode[0] == -1) {
				tour_temp = count1_two(traveler, less_money);
				plan = cheap_plan(tour_temp, less_money);
				show_cheap(plan,fout);
			}
			else {
				tour_temp = count(traveler, less_money);
				plan = cheap_plan(tour_temp, less_money);
				show_cheap(plan,fout);
			}
			simulation1(plan, fout);
		}
		else if (choice == 2) {
			cout << "������������ʼʱ��(0ʱ����23ʱ����";//������ʼʱ�䣬�������õϽ�˹�����㷨
			fout << "������������ʼʱ��(0ʱ����23ʱ����";
			cin >> start_time;
			fout << start_time << endl;
			cout << "���������з���:" << endl;
			fout << "���������з���:" << endl;
			if (traveler.passnode[0] == -1) {
				for (int k = 0; k < 70; k++)
					plan.porder[k] = -1;
				get_leasttime(traveler, plan, start_time);
				show_leasttime(start_time, plan,fout);
			}
			else {
				plan.min_time = 0;
				get_leasttime2(traveler, plan, start_time);
				show_leasttime(start_time, plan,fout);
			}
			simulation2(plan, start_time,fout);
		}
		else if (choice == 3) {
			cout << "������������ʼʱ��(0ʱ����23ʱ����";
			fout << "������������ʼʱ��(0ʱ����23ʱ����";
			cin >> start_time;
			fout << start_time << endl;
			cout << "�������޶�ʱ�䣺";
			fout << "�������޶�ʱ�䣺";
			cin >> limit_time;
			fout << limit_time << endl;
			if (traveler.passnode[0] == -1) {
				for (int k = 0; k < 70; k++)
					plan.porder[k] = -1;
				get_leasttime(traveler, plan, start_time);
				while (plan.min_time > limit_time) {
					cout << "�޶�ʱ����٣�û�к���·�ߣ������������޶�ʱ�䣨����ʱ��Ϊ" << plan.min_time << "Сʱ)" << endl;
					fout << "�޶�ʱ����٣�û�к���·�ߣ������������޶�ʱ�䣨����ʱ��Ϊ" << plan.min_time << "Сʱ)" << endl;
					cin >> limit_time;
					fout << limit_time << endl;
				}
				cout << "���������з���:" << endl;
				fout << "���������з���:" << endl;
				get_limittime1(traveler, plan, start_time, limit_time);
				show_leasttime(start_time, plan,fout);

			}
			else {
				get_leasttime2(traveler, plan, start_time);
				while (plan.min_time > limit_time) {
					cout << "�޶�ʱ����٣�û�к���·�ߣ������������޶�ʱ�䣨����ʱ��Ϊ" << plan.min_time << "Сʱ)" << endl;
					fout << "�޶�ʱ����٣�û�к���·�ߣ������������޶�ʱ�䣨����ʱ��Ϊ" << plan.min_time << "Сʱ)" << endl;
					cin >> limit_time;
					fout << limit_time << endl;
				}
				cout << "���������з���:" << endl;
				fout << "���������з���:" << endl;
				get_limittime2(traveler, plan, start_time, limit_time);
				show_leasttime(start_time, plan,fout);
			}
			simulation2(plan, start_time,fout);
		}
		cout << "ѡ���Ƿ����ģ�⣨1������	2��ֹͣ����";
		fout << "ѡ���Ƿ����ģ�⣨1������	2��ֹͣ����";
		cin >> flag;
		fout << flag << endl;
	} while (flag == 1);
	cout << "����ģ�������";
	fout << "����ģ�������";
	fout.close();
	system("pause");
	return 0;
}


