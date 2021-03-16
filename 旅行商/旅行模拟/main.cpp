#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include"head.h"

Route mat[10][10][6];//时刻表

int main()
{
	using namespace std;
	int i, j, k, temp;
	int a, choice;
	int start_time, limit_time, flag;
	input(mat);
	int less_money[10][10];//存放时刻表上每对城市间价格最少的交通工具的价钱
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
	fout << "以下为程序运行日志\n\n";
	cout << "-------------------------------------------------------------\n";
	cout << "              *开始运行旅行模拟程序*" << endl;
	fout << "-------------------------------------------------------------\n";
	fout << "              *开始运行旅行模拟程序*" << endl;
	
	do {
		cout << "-------------------------------------------------------------\n";
		cout << "城市列表：0-北京   1-上海   2-广州   3-哈尔滨   4-沈阳   5-天津   6-兰州   7-成都   8-贵阳   9-武汉" << endl;
		cout << "请输入起始城市对应号数：";
		fout << "-------------------------------------------------------------\n";
		fout << "城市列表：0-北京   1-上海   2-广州   3-哈尔滨   4-沈阳   5-天津   6-兰州   7-成都   8-贵阳   9-武汉" << endl;
		fout << "请输入起始城市对应号数：";
		cin >> traveler.startnode;
		fout << traveler.startnode << endl;
		cout << "请输入终止城市对应号数：";
		fout << "请输入终止城市对应号数：";
		cin >> traveler.arrivenode;
		fout << traveler.arrivenode << endl;
		cout << "请输入需要途径城市对应号数（空格隔开，-1结束):";
		fout << "请输入需要途径城市对应号数（空格隔开，-1结束):";
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
		cout << "旅行策略:" << endl;
		cout << "1、最少花费策略。" << endl;
		cout << "2、最少时间策略。" << endl;
		cout << "3、限时最少费用策略。" << endl;
		cout << "请选择旅行策略:";
		fout << "旅行策略:" << endl;
		fout << "1、最少花费策略。" << endl;
		fout << "2、最少时间策略。" << endl;
		fout << "3、限时最少费用策略。" << endl;
		fout << "请选择旅行策略:";
		cin >> choice;
		fout << choice << endl;
		if (choice == 1) {
			cout << "以下是旅行方案:" << endl;
			fout << "以下是旅行方案:" << endl;
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
			cout << "请输入旅行起始时间(0时——23时）：";//设置起始时间，便于利用迪杰斯特拉算法
			fout << "请输入旅行起始时间(0时——23时）：";
			cin >> start_time;
			fout << start_time << endl;
			cout << "以下是旅行方案:" << endl;
			fout << "以下是旅行方案:" << endl;
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
			cout << "请输入旅行起始时间(0时——23时）：";
			fout << "请输入旅行起始时间(0时——23时）：";
			cin >> start_time;
			fout << start_time << endl;
			cout << "请输入限定时间：";
			fout << "请输入限定时间：";
			cin >> limit_time;
			fout << limit_time << endl;
			if (traveler.passnode[0] == -1) {
				for (int k = 0; k < 70; k++)
					plan.porder[k] = -1;
				get_leasttime(traveler, plan, start_time);
				while (plan.min_time > limit_time) {
					cout << "限定时间过少，没有合适路线，请重新输入限定时间（最少时间为" << plan.min_time << "小时)" << endl;
					fout << "限定时间过少，没有合适路线，请重新输入限定时间（最少时间为" << plan.min_time << "小时)" << endl;
					cin >> limit_time;
					fout << limit_time << endl;
				}
				cout << "以下是旅行方案:" << endl;
				fout << "以下是旅行方案:" << endl;
				get_limittime1(traveler, plan, start_time, limit_time);
				show_leasttime(start_time, plan,fout);

			}
			else {
				get_leasttime2(traveler, plan, start_time);
				while (plan.min_time > limit_time) {
					cout << "限定时间过少，没有合适路线，请重新输入限定时间（最少时间为" << plan.min_time << "小时)" << endl;
					fout << "限定时间过少，没有合适路线，请重新输入限定时间（最少时间为" << plan.min_time << "小时)" << endl;
					cin >> limit_time;
					fout << limit_time << endl;
				}
				cout << "以下是旅行方案:" << endl;
				fout << "以下是旅行方案:" << endl;
				get_limittime2(traveler, plan, start_time, limit_time);
				show_leasttime(start_time, plan,fout);
			}
			simulation2(plan, start_time,fout);
		}
		cout << "选择是否继续模拟（1、继续	2、停止）：";
		fout << "选择是否继续模拟（1、继续	2、停止）：";
		cin >> flag;
		fout << flag << endl;
	} while (flag == 1);
	cout << "旅行模拟结束！";
	fout << "旅行模拟结束！";
	fout.close();
	system("pause");
	return 0;
}


