// travel_plan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<fstream>
#include<string>
#include<cassert>
#define maxnum 16
#define maxint 9999
using namespace std;


string address[15] = { "BJ", "CQ", "CS", "HF", "HZ", "JN", "NJ", "SH", "SJ", "SZ", "TJ", "WH", "XA", "XZ", "ZZ" };
string ADDRESS[15] = { "北京", "重庆", "长沙", "合肥", "杭州", "济南", "南京", "上海", "石家庄", "苏州", "天津", "武汉", "西安", "徐州", "郑州"};

	class Time_cost {
	public:
		double begin_time;
		double time_cost;
	};

	class vehicle {
	public:
		string Vec[1000];

		string Departure_Station[1000];

		string Terminus[1000];

		string vehicle_number[1000];

		string time_begin[1000];

		double time_cost[1000];

		double money_cost[1000];

		friend class city;

		friend class Passenger;

		vehicle (){}

		~vehicle(){}
	};

	class route {
	public:
		string Vec;
		string Departure_Station;
		string Terminus;
		string vehicle_number;
		string time_begin;
		double time_cost;
		double money_cost;
		route(){}

		~route(){}
		friend class city;
		friend class Passenger;
	};

	class Passenger {
	public:
		string name;
		string current_city;
		string Departure_place;
		string Terminus;
		route Stortest_time;
		route Min_cost;
		route time_min_cost;
		vehicle current_vheicle;
	};

	class city {
	public:
		string City_Name;

		vehicle train;
		vehicle car;
		vehicle plane;

		route min_cost[15];
		route min_time[15];
		route time_and_cost[15];

		city (){}

		~city(){}

		void init_city(string file_1, string file_2, string file_3,  string city_name); //file_1,file_2,file_3分别表示火车、汽车、飞机的数据文件名，city_name表示出发城市的名字
	};

	void city::init_city(string file_1, string file_2, string file_3, string city_name) {
		City_Name = city_name;
	
		ifstream infile1;
		infile1.open(file_1.data());   //将文件流对象与文件连接起来 
		assert(infile1.is_open());   //若失败,则输出错误消息,并终止程序运行 

		char c;
		infile1 >> noskipws;

		int i = 0, flag = 0;
		for (i = 0; i < 1000; i++) {
			train.vehicle_number[i] = "";
			train.Departure_Station[i] = "";
			train.Terminus[i] = "";
			train.time_begin[i] = "";
			train.time_cost[i] = 0;
			train.money_cost[i] = 0;
			plane.vehicle_number[i] = "";
			plane.Departure_Station[i] = "";
			plane.Terminus[i] = "";
			plane.time_begin[i] = "";
			plane.time_cost[i] = 0;
			plane.money_cost[i] = 0;
			car.vehicle_number[i] = "";
			car.Departure_Station[i] = "";
			car.Terminus[i] = "";
			car.time_begin[i] = "";
			car.time_cost[i] = 0;
			car.money_cost[i] = 0;

		}
		i = 0;
		double j = 0, k = 0;
		string s = "", ss = "";

		infile1 >> c;
		while (!infile1.eof()) {

			while ((c == ' ') || (c == '\t')) {
				infile1 >> c;
			}
			while ((c != ' ') && (c != '\t')) {
				if(c != '\n')
					s += c;
				infile1 >> c;
			}

			while ((c == ' ') || (c == '\t')) {
				infile1 >> c;
			}
			while ((c != ' ') && (c != '\t')) {
				ss += c;
				infile1 >> c;
			}

			if (ss == city_name) {
				train.Vec[i] = "train";
				train.vehicle_number[i] += s;
				train.Departure_Station[i] += ss;
				s = "";
				ss = "";
				while ((c == ' ') || (c == '\t')) {
					infile1 >> c;
				}

				while ((c != ' ') && (c != '\t')) {
					train.Terminus[i] += c;
					infile1 >> c;
				}

				while ((c == ' ') || (c == '\t')) {
					infile1 >> c;
				}

				while ((c != ' ') && (c != '\t')) {
					train.time_begin[i] += c;
					infile1 >> c;
				}

				while ((c == ' ') || (c == '\t')) {
					infile1 >> c;
				}

				while ((c != ' ') && (c != '\t')) {
					s += c;
					infile1 >> c;
				}
				j = atof(s.substr(3, 2).c_str()) - atof(train.time_begin[i].substr(3, 2).c_str());
				if (j < 0) {
					j += 60;
					if (atof(s.substr(0, 2).c_str()) > atof(train.time_begin[i].substr(0, 2).c_str()))
						k = atof(s.substr(0, 2).c_str()) - 1 - atof(train.time_begin[i].substr(0, 2).c_str());
					else
						k = atof(s.substr(0, 2).c_str()) + 24 - 1 - atof(train.time_begin[i].substr(0, 2).c_str());
				}
				else {
					if (atof(s.substr(0, 2).c_str()) > atof(train.time_begin[i].substr(0, 2).c_str()))
						k = atof(s.substr(0, 2).c_str()) - atof(train.time_begin[i].substr(0, 2).c_str());
					else
						k = atof(s.substr(0, 2).c_str()) + 24 - atof(train.time_begin[i].substr(0, 2).c_str());
				}
				train.time_cost[i] = j / 60 + k;
				j = 0;
				k = 0;
				s = "";

				while ((c == ' ') || (c == '\t')) {
					infile1 >> c;
				}

				while ((c != ' ') && (c != '\t')) {
					s += c;
					infile1 >> c;
				}
				train.money_cost[i] = atof(s.c_str());
				i++;
				flag = 1;
			}
			else {
				while (c != '\n') {
					infile1 >> c;
				}
				if (flag == 1)
					flag = 2;
			}
			s = "";
			ss = "";
			infile1 >> c;
			if (flag == 2) {
				flag = 0;
				break;
			}
		}
		infile1.close();
		std::cout << "*" << endl;
	
		ifstream infile2;
		infile2.open(file_2.data());   //将文件流对象与文件连接起来 
		assert(infile2.is_open());   //若失败,则输出错误消息,并终止程序运行 

		infile2 >> noskipws;
		s = "";
		ss = "";
		i = 0;

		infile2 >> c;
		while (!infile2.eof()) {

			while ((c == ' ') || (c == '\t') || (c == '\n'))
				infile2 >> c;
			while ((c != ' ') && (c != '\t')) {
				s += c;
				infile2 >> c;
			}

			if (s == city_name) {
				train.Vec[i] = "car";
				car.Departure_Station[i] += s;
				s = "";
				ss = "";
				while ((c == ' ') || (c == '\t'))
					infile2 >> c;

				while ((c != ' ') && (c != '\t')) {
					car.Terminus[i] += c;
					infile2 >> c;
				}

				while ((c == ' ') || (c == '\t'))
					infile2 >> c;
				while ((c != ' ') && (c != '\t')) {
					car.time_begin[i] += c;
					infile2 >> c;
				}

				while ((c == ' ') || (c == '\t'))
					infile2 >> c;
				while ((c != ' ') && (c != '\t')) {
					s += c;
					infile2 >> c;
				}
				j = atof(s.substr(3, 2).c_str()) - atof(car.time_begin[i].substr(3, 2).c_str());
				if (j < 0) {
					j += 60;
					if(atof(s.substr(0, 2).c_str()) > atof(car.time_begin[i].substr(0, 2).c_str()))
						k = atof(s.substr(0, 2).c_str()) - 1 - atof(car.time_begin[i].substr(0, 2).c_str());
					else
						k = atof(s.substr(0, 2).c_str()) + 24 - 1 - atof(car.time_begin[i].substr(0, 2).c_str());
				}
				else {
					if (atof(s.substr(0, 2).c_str()) > atof(car.time_begin[i].substr(0, 2).c_str()))
						k = atof(s.substr(0, 2).c_str()) - atof(car.time_begin[i].substr(0, 2).c_str());
					else
						k = atof(s.substr(0, 2).c_str()) + 24 - atof(car.time_begin[i].substr(0, 2).c_str());
				}
				car.time_cost[i] = j / 60 + k;
				j = 0;
				k = 0;
				s = "";

				while ((c == ' ') || (c == '\t'))
					infile2 >> c;
				while ((c != ' ') && (c != '\t')) {
					s += c;
					infile2 >> c;
				}
				car.money_cost[i] = atof(s.c_str());
				i++;
				flag = 1;
			}
			else {
				while (c != '\n') {
					infile2 >> c;
				}
				if (flag == 1)
					flag = 2;
			}
			s = "";
			infile2 >> c;
			if (flag == 2) {
				flag = 0;
				break;
			}
		}
		infile2.close();
	
		ifstream infile;
		infile.open(file_3.data());   //将文件流对象与文件连接起来 
		assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

		infile >> noskipws;
		s = "";
		ss = "";
		i = 0;

		infile >> c;
		while (!infile.eof()) {

			while ((c == ' ') || (c == '\t') || (c == '\n'))
				infile >> c;
			while ((c != ' ') && (c != '\t')) {
				s += c;
				infile >> c;
			}

			while ((c == ' ') || (c == '\t'))
				infile >> c;
			while ((c != ' ') && (c != '\t')) {
				ss += c;
				infile >> c;
			}

			if (ss == city_name) {
				train.Vec[i] = "plane";
				plane.vehicle_number[i] += s;
				plane.Departure_Station[i] += ss;
				s = "";
				ss = "";
				while ((c == ' ') || (c == '\t'))
					infile >> c;

				while ((c != ' ') && (c != '\t')) {
					plane.Terminus[i] += c;
					infile >> c;
				}

				while ((c == ' ') || (c == '\t'))
					infile >> c;

				while ((c != ' ') && (c != '\t')) {
					plane.time_begin[i] += c;
					infile >> c;
				}

				while ((c == ' ') || (c == '\t'))
					infile >> c;

				while ((c != ' ') && (c != '\t')) {
					s += c;
					infile >> c;
				}
				j = atof(s.substr(3, 2).c_str()) - atof(plane.time_begin[i].substr(3, 2).c_str());
				if (j < 0) {
					j += 60;
					if (atof(s.substr(0, 2).c_str()) > atof(plane.time_begin[i].substr(0, 2).c_str()))
						k = atof(s.substr(0, 2).c_str()) - 1 - atof(plane.time_begin[i].substr(0, 2).c_str());
					else
						k = atof(s.substr(0, 2).c_str()) + 24 - 1 - atof(plane.time_begin[i].substr(0, 2).c_str());
				}
				else {
					if (atof(s.substr(0, 2).c_str()) > atof(plane.time_begin[i].substr(0, 2).c_str()))
						k = atof(s.substr(0, 2).c_str()) - atof(plane.time_begin[i].substr(0, 2).c_str());
					else
						k = atof(s.substr(0, 2).c_str()) + 24 - atof(plane.time_begin[i].substr(0, 2).c_str());
				}
				plane.time_cost[i] = j / 60 + k;
				j = 0;
				k = 0;
				s = "";

				while ((c == ' ') || (c == '\t'))
					infile >> c;

				while ((c != ' ') && (c != '\t')) {
					s += c;
					infile >> c;
				}
				plane.money_cost[i] = atof(s.c_str());
				i++;
				flag = 1;
			}
			else {
				while (c != '\n') {
					infile >> c;
				}
				if (flag == 1)
					flag = 2;
			}
			s = "";
			ss = "";
			infile >> c;
			if (flag == 2) {
				flag = 0;
				break;
			}

		}
		infile.close();
	}

city CITY[15];

double find_min_cost_cities(int A, string B, int j, int hour, int minute) { //A是出发地城市,B是目的地城市名  begin_time 表示当前旅客的查询时间
	double min = 9999;
	double begin, current;
	if (CITY[A].City_Name == B)
		return 0;
	else
		for (int i = 0; i < 1000; i++) {
			if (CITY[A].car.Terminus[i] == B) {
				begin = hour + minute / 60;
				current = atof(CITY[A].car.time_begin[i].substr(0, 2).c_str()) + atof(CITY[A].car.time_begin[i].substr(3, 2).c_str()) / 60;
				//if (begin <= current) {
					if (CITY[A].car.money_cost[i] < min) {
						min = CITY[A].car.money_cost[i];
						CITY[A].min_cost[j].Vec = "car";
						CITY[A].min_cost[j].Departure_Station = CITY[A].car.Departure_Station[i];
						CITY[A].min_cost[j].vehicle_number = CITY[A].car.vehicle_number[i];
						CITY[A].min_cost[j].Terminus = B;
						CITY[A].min_cost[j].time_begin = CITY[A].car.time_begin[i];
						CITY[A].min_cost[j].time_cost = CITY[A].car.time_cost[i];
						CITY[A].min_cost[j].money_cost = CITY[A].car.money_cost[i];
					}
				//}
				/*else 
					if (CITY[A].car.money_cost[i] < min) {
						min = CITY[A].car.money_cost[i];
						CITY[A].min_cost[j].Vec = "car";
						CITY[A].min_cost[j].Departure_Station = CITY[A].car.Departure_Station[i];
						CITY[A].min_cost[j].Terminus = B;
						CITY[A].min_cost[j].time_begin = CITY[A].car.time_begin[i];
						CITY[A].min_cost[j].time_cost = CITY[A].car.time_cost[i] + current - begin + 24;
						CITY[A].min_cost[j].money_cost = CITY[A].car.money_cost[i];
					}*/
			}
			if (CITY[A].plane.Terminus[i] == B) {
				begin = hour + minute / 60;
				current = atof(CITY[A].plane.time_begin[i].substr(0, 2).c_str()) + atof(CITY[A].plane.time_begin[i].substr(3, 2).c_str()) / 60;
				//if (begin <= current) {
					if (CITY[A].plane.money_cost[i] < min) {
						min = CITY[A].plane.money_cost[i];
						CITY[A].min_cost[j].Vec = "plane";
						CITY[A].min_cost[j].Departure_Station = CITY[A].plane.Departure_Station[i];
						CITY[A].min_cost[j].vehicle_number = CITY[A].plane.vehicle_number[i];
						CITY[A].min_cost[j].Terminus = B;
						CITY[A].min_cost[j].time_begin = CITY[A].plane.time_begin[i];
						CITY[A].min_cost[j].time_cost = CITY[A].plane.time_cost[i] ;
						CITY[A].min_cost[j].money_cost = CITY[A].plane.money_cost[i];
					}
				//}
				/*else
					if (CITY[A].plane.money_cost[i] < min) {
						min = CITY[A].plane.money_cost[i];
						CITY[A].min_cost[j].Vec = "plane";
						CITY[A].min_cost[j].Departure_Station = CITY[A].plane.Departure_Station[i];
						CITY[A].min_cost[j].Terminus = B;
						CITY[A].min_cost[j].time_begin = CITY[A].plane.time_begin[i];
						CITY[A].min_cost[j].time_cost = CITY[A].plane.time_cost[i] + current - begin + 24;
						CITY[A].min_cost[j].money_cost = CITY[A].plane.money_cost[i];
					}*/
			}
			if (CITY[A].train.Terminus[i] == B) {
				begin = hour + minute / 60;
				current = atof(CITY[A].train.time_begin[i].substr(0, 2).c_str()) + atof(CITY[A].train.time_begin[i].substr(3, 2).c_str()) / 60;
				//if (begin <= current) {
					if (CITY[A].train.money_cost[i] < min) {
						min = CITY[A].train.money_cost[i];
						CITY[A].min_cost[j].Vec = "train";
						CITY[A].min_cost[j].Departure_Station = CITY[A].train.Departure_Station[i];
						CITY[A].min_cost[j].vehicle_number = CITY[A].train.vehicle_number[i];
						CITY[A].min_cost[j].Terminus = B;
						CITY[A].min_cost[j].time_begin = CITY[A].train.time_begin[i];
						CITY[A].min_cost[j].time_cost = CITY[A].train.time_cost[i];
						CITY[A].min_cost[j].money_cost = CITY[A].train.money_cost[i];
					}
				//}
				/*else
					if (CITY[A].train.money_cost[i] < min) {
						min = CITY[A].train.money_cost[i];
						min = CITY[A].train.money_cost[i];
						CITY[A].min_cost[j].Vec = "train";
						CITY[A].min_cost[j].Departure_Station = CITY[A].train.Departure_Station[i];
						CITY[A].min_cost[j].Terminus = B;
						CITY[A].min_cost[j].time_begin = CITY[A].train.time_begin[i];
						CITY[A].min_cost[j].time_cost = CITY[A].train.time_cost[i] + current - begin + 24;
						CITY[A].min_cost[j].money_cost = CITY[A].train.money_cost[i];
					}*/
			}
		}
	return min;
}

Time_cost find_shortest_time_cities(int A, string B, int j, int hour, int minute) { //A是出发地城市,B是目的地城市名  begin_time 表示当前旅客的查询时间
	double MIN = 9999;
	Time_cost min;
	min.time_cost = 9999;
	double begin, current;
	if (CITY[A].City_Name == B) {
		min.time_cost = 0;
		return min;
	}
	else
		for (int i = 0; i < 1000; i++) {
			if (CITY[A].car.Terminus[i] == B) {
				begin = hour + minute / 60;
				current = atof(CITY[A].car.time_begin[i].substr(0, 2).c_str()) + atof(CITY[A].car.time_begin[i].substr(3, 2).c_str()) / 60;
				//if (begin <= current){
					MIN = CITY[A].car.time_cost[i];
					if (MIN < min.time_cost) {
						min.time_cost = MIN;
						min.begin_time = current;
						CITY[A].min_time[j].Vec = "car";
						CITY[A].min_time[j].Departure_Station = CITY[A].car.Departure_Station[i];
						CITY[A].min_time[j].vehicle_number = CITY[A].car.vehicle_number[i];
						CITY[A].min_time[j].Terminus = B;
						CITY[A].min_time[j].time_begin = CITY[A].car.time_begin[i];
						CITY[A].min_time[j].time_cost = CITY[A].car.time_cost[i];
						CITY[A].min_time[j].money_cost = CITY[A].car.money_cost[i];
					}
				//}
				/*else {
					MIN = CITY[A].car.time_cost[i];
					if (MIN < min.time_cost) {
						min.time_cost = MIN;
						min.begin_time = current;
						CITY[A].min_time[j].Departure_Station = CITY[A].car.Departure_Station[i];
						CITY[A].min_time[j].Terminus = B;
						CITY[A].min_time[j].time_begin = CITY[A].car.time_begin[i];
						CITY[A].min_time[j].time_cost = CITY[A].car.time_cost[i];
						CITY[A].min_time[j].money_cost = CITY[A].car.money_cost[i];
					}
				}*/
			}
			if (CITY[A].plane.Terminus[i] == B) {
				begin = hour + minute / 60;
				current = atof(CITY[A].plane.time_begin[i].substr(0, 2).c_str()) + atof(CITY[A].plane.time_begin[i].substr(3, 2).c_str()) / 60;
				//if (begin <= current) {
					MIN = CITY[A].plane.time_cost[i];
					if (MIN < min.time_cost) {
						min.time_cost = MIN;
						min.begin_time = current;
						CITY[A].min_time[j].Vec = "plane";
						CITY[A].min_time[j].Departure_Station = CITY[A].plane.Departure_Station[i];
						CITY[A].min_time[j].vehicle_number = CITY[A].plane.vehicle_number[i];
						CITY[A].min_time[j].Terminus = B;
						CITY[A].min_time[j].time_begin = CITY[A].plane.time_begin[i];
						CITY[A].min_time[j].time_cost = CITY[A].plane.time_cost[i];
						CITY[A].min_time[j].money_cost = CITY[A].plane.money_cost[i];
					}
				//}
				/*else {
					MIN = current - begin + 24 + CITY[A].plane.time_cost[i];
					if (MIN < min.time_cost) {
						min.time_cost = MIN;
						min.begin_time = current;
						CITY[A].min_time[j].Departure_Station = CITY[A].plane.Departure_Station[i];
						CITY[A].min_time[j].Terminus = B;
						CITY[A].min_time[j].time_begin = CITY[A].plane.time_begin[i];
						CITY[A].min_time[j].time_cost = CITY[A].plane.time_cost[i];
						CITY[A].min_time[j].money_cost = CITY[A].plane.money_cost[i];
					}
				}*/
			}
			if (CITY[A].train.Terminus[i] == B) {
				begin = hour + minute / 60;
				current = atof(CITY[A].train.time_begin[i].substr(0, 2).c_str()) + atof(CITY[A].train.time_begin[i].substr(3, 2).c_str()) / 60;
				//if (begin <= current) {
					MIN = CITY[A].train.time_cost[i];
					if (MIN < min.time_cost) {
						min.time_cost = MIN;
						min.begin_time = current;
						CITY[A].min_time[j].Vec = "train";
						CITY[A].min_time[j].Departure_Station = CITY[A].train.Departure_Station[i];
						CITY[A].min_time[j].vehicle_number = CITY[A].train.vehicle_number[i];
						CITY[A].min_time[j].Terminus = B;
						CITY[A].min_time[j].time_begin = CITY[A].train.time_begin[i];
						CITY[A].min_time[j].time_cost = CITY[A].train.time_cost[i];
						CITY[A].min_time[j].money_cost = CITY[A].train.money_cost[i];
					}
				//}
				/*else {
					MIN = current - begin + 24 + CITY[A].train.time_cost[i];
					if (MIN < min.time_cost) {
						min.time_cost = MIN;
						min.begin_time = current;
						CITY[A].min_time[j].Departure_Station = CITY[A].train.Departure_Station[i];
						CITY[A].min_time[j].Terminus = B;
						CITY[A].min_time[j].time_begin = CITY[A].train.time_begin[i];
						CITY[A].min_time[j].time_cost = CITY[A].train.time_cost[i];
						CITY[A].min_time[j].money_cost = CITY[A].train.money_cost[i];
					}
				}*/
			}
		}
	return min;
}


void Dijkstra(int n, int v, double *dist, int *prev, double c[maxnum - 1][maxnum - 1])
{//n表示矩阵的行列数，v表示起始点，dist[i]表示起始点到i的距离，prev[i]表示i的前一个节点号为prev[i]，c[][]是矩阵
	bool s[maxnum];    // 判断是否已存入该点到S集合中
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = c[v - 1][i - 1];
		s[i] = 0;     // 初始都未用过该点
		if (dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = 1;

	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
	// 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
		 // 注意是从第二个节点开始，第一个为源点
	for (int i = 2; i <= n; ++i)
	{
		double tmp = maxint;
		int u = v;
		// 找出当前未使用的点j的dist[j]最小值
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[j] < tmp)
			{
				u = j;              // u保存当前邻接点中距离最小的点的号码
				tmp = dist[j];
			}
		s[u] = 1;    // 表示u点已存入S集合中

		// 更新dist
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && c[u - 1][j - 1] < maxint)
			{
				double newdist = dist[u] + c[u - 1][j - 1];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
	}
}

void Dijkstra_2(int n, int v, double *dist, int *prev, Time_cost c[maxnum - 1][maxnum - 1], double start_time)
{
	bool s[maxnum];    // 判断是否已存入该点到S集合中
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = c[v - 1][i - 1].time_cost;
		dist[i] = c[v - 1][i - 1].time_cost;
		s[i] = 0;     // 初始都未用过该点
		if (dist[i] == maxint)
			prev[i] = 0;
		else {
			prev[i] = v;
			if (c[v - 1][i - 1].begin_time >= start_time)
				dist[i] += +c[v - 1][i - 1].begin_time - start_time;
			else
				dist[i] += +c[v - 1][i - 1].begin_time - start_time + 24;
		}
	}
	dist[v] = 0;
	s[v] = 1;

	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
	// 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
		 // 注意是从第二个节点开始，第一个为源点
	for (int i = 2; i <= n; ++i)
	{
		double tmp = maxint;
		int u = v;
		// 找出当前未使用的点j的dist[j]最小值
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[j] < tmp)
			{
				u = j;              // u保存当前邻接点中距离最小的点的号码
				tmp = dist[j];
			}
		s[u] = 1;    // 表示u点已存入S集合中

		// 更新dist
		int prev_time, wait_time;
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && c[u - 1][j - 1].time_cost < maxint)
			{
				prev_time = c[prev[u] - 1][u - 1].begin_time + c[prev[u] - 1][u - 1].time_cost;
				if (prev_time > c[u - 1][j - 1].begin_time)
					wait_time = c[u - 1][j - 1].begin_time - prev_time + 24;
				else
					wait_time = c[u - 1][j - 1].begin_time - prev_time;
				double newdist = dist[u] + c[u - 1][j - 1].time_cost + wait_time;
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
	}
}


void print_city(string city) {
	for(int i = 0; i < 15; i++)
		if (address[i] == city) {
			std::cout << ADDRESS[i];
			break;
		}
}
int find_address(string CITY) {
	for (int i = 0; i < 15; i++) {
		if (ADDRESS[i] == CITY) {
			return i;
		}
	}
	return maxnum;//大于16即可
}

// 查找从源点v到终点u的路径，并输出
void searchPath(int *prev, int v, int u, int day, int hour, int minute)
{//prev[i]表示i的前一个节点号为prev[i]，v表示起始点，u表示终点，day、hour、minute分别表示开始查询的天数、小时、分钟
	int que[maxnum];
	int reque[maxnum];
	for (int i = 0; i < maxnum; i++) {
		reque[i] = -1;
	}
	int tot = 1, j = 1;
	que[tot] = u;
	tot++;
	int tmp = prev[u];
	while (tmp != v)
	{
		que[tot] = tmp;
		tot++;
		tmp = prev[tmp];
	}
	que[tot] = v;
	//构造顺序的路线序号
	for (int i = tot; i >= 1; i--) {
		reque[j] = que[i] - 1;
		j++;
	}
	for (int i = tot; i >= 1; --i)
		if (i != 1) {
			print_city(address[que[i] - 1]);
			std::cout << " -> ";
		}
		else {
			print_city(address[que[i] - 1]);
			std::cout << endl;
		}
	int d = 0, h = 0, m = 0;
	double begin_1, begin_2, end;
	double time = atof(CITY[reque[1]].min_cost[reque[2]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[1]].min_cost[reque[2]].time_begin.substr(3, 2).c_str()) / 60;
	double time_1 = hour + minute / 60;
	if (time_1 > time)
		time = time - time_1 + 24;
	else
		time = time - time_1;
	for (int i = 1; reque[i + 1] != -1; i++) {
		begin_1 = atof(CITY[reque[i]].min_cost[reque[i + 1]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[i]].min_cost[reque[i + 1]].time_begin.substr(3, 2).c_str()) / 60;
		if (reque[i + 2] != -1)
			begin_2 = atof(CITY[reque[i + 1]].min_cost[reque[i + 2]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[i + 1]].min_cost[reque[i + 2]].time_begin.substr(3, 2).c_str()) / 60;
		else
			begin_2 = 0;
		end = begin_1 + CITY[reque[i]].min_cost[reque[i + 1]].time_cost;
		if (begin_2 != 0) {
			if ((end - 24) > begin_2)
				time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - (end - 24) + 24;
			else {
				if (end <= begin_2)
					time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - end;
				else
					time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - (end - 24);
			}
		}
		else
			time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost;
	}

	time += time_1;
	d = time / 24;
	h = time - d * 24;
	m = (time - d * 24 - h) * 60;

	for (int i = 1; reque[i + 1] != -1; i++) {
		std::cout << CITY[reque[i]].min_cost[reque[i + 1]].Departure_Station << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].Vec << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].vehicle_number << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].Terminus << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].time_begin << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].time_cost << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].money_cost;
		std::cout << endl;
	}
	std::cout << "第" << d + day << "天 " << h << ":" << m << "  到达" << ADDRESS[u - 1] << endl;
}

void searchPath_2(int *prev, int v, int u, int day, int hour, int minute, double t)
{//prev[i]表示i的前一个节点号为prev[i]，v表示起始点，u表示终点，day、hour、minute分别表示开始查询的天数、小时、分钟，t表示起始站到终点站的时间
	int que[maxnum];
	int reque[maxnum];
	for (int i = 0; i < maxnum; i++) {
		reque[i] = -1;
	}
	int tot = 1, j = 1;
	que[tot] = u;
	tot++;
	int tmp = prev[u];
	while (tmp != v)
	{
		que[tot] = tmp;
		tot++;
		tmp = prev[tmp];
	}
	que[tot] = v;
	//构造顺序的路线序号
	for (int i = tot; i >= 1; i--) {
		reque[j] = que[i] - 1;
		j++;
	}
	for (int i = tot; i >= 1; --i)
		if (i != 1) {
			print_city(address[que[i] - 1]);
			std::cout << " -> ";
		}
		else {
			print_city(address[que[i] - 1]);
			std::cout << endl;
		}
	int d = 0, h = 0, m = 0;
	//double begin_1, begin_2, end;
	//double time = atof(CITY[reque[1]].min_time[reque[2]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[1]].min_time[reque[2]].time_begin.substr(3, 2).c_str()) / 60;
	double time_1 = hour + minute / 60;
	/*if (time_1 > time)
		time = time - time_1 + 24;
	else
		time = time - time_1;
	for (int i = 1; reque[i + 1] != -1; i++) {
		begin_1 = atof(CITY[reque[i]].min_time[reque[i + 1]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[i]].min_time[reque[i + 1]].time_begin.substr(3, 2).c_str()) / 60;
		if (reque[i + 2] != -1)
			begin_2 = atof(CITY[reque[i + 1]].min_time[reque[i + 2]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[i + 1]].min_time[reque[i + 2]].time_begin.substr(3, 2).c_str()) / 60;
		else
			begin_2 = 0;
		end = begin_1 + CITY[reque[i]].min_time[reque[i + 1]].time_cost;
		if (begin_2 != 0) {
			if ((end - 24) > begin_2)
				time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - (end - 24) + 24;
			else {
				if (end <= begin_2)
					time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - end;
				else
					time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - (end - 24);
			}
		}
		else
			time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost;
	}*/

	t += time_1;
	d = t / 24;
	h = t - d * 24;
	m = (t - d * 24 - h) * 60;

	for (int i = 1; reque[i + 1] != -1; i++) {
		std::cout << CITY[reque[i]].min_time[reque[i + 1]].Departure_Station << '\t' << CITY[reque[i]].min_time[reque[i + 1]].Vec << '\t' << CITY[reque[i]].min_time[reque[i + 1]].vehicle_number << '\t' << CITY[reque[i]].min_time[reque[i + 1]].Terminus << '\t' << CITY[reque[i]].min_time[reque[i + 1]].time_begin << '\t' << CITY[reque[i]].min_time[reque[i + 1]].time_cost << '\t' << CITY[reque[i]].min_time[reque[i + 1]].money_cost;
		std::cout << endl;
	}
	std::cout << "第" << d + day << "天 " << h << ":" << m << "  到达" << ADDRESS[u - 1] << endl;
}

double start_t, limit_t;
double min = maxint;
int prev_3[15];
int visit[15];
int path_3[15], path3[15];
int node;
double money_co, time_sp;

double trans_time(string A) {
	return (atof(A.substr(0, 2).c_str()) + atof(A.substr(3, 2).c_str()) / 60);
}

void DFS(int departure, int terminus, double spend, double cost, double current_time) {
	if (departure == terminus) {
		//cout << "spend:" << spend << "\tcost:" << cost << endl;
		if (spend <= limit_t)
			if (cost < min) {
				min = cost;
				money_co = cost;
				time_sp = spend;
				for (int i = 0; path_3[i] != -1; i++) {
					path3[i] = path_3[i];
				}
				for (int i = 0; path_3[i] != -1; i++)
					cout << path_3[i] << "\t";
				cout << endl;
				return;
			}
	}
	if (spend > limit_t) return;
	int j = 0;
	double temp_spend = 0;
	for (int i = 0; i < 15; i++) {
		if (visit[i] == -1) {
			path_3[node] = i;
			visit[i] = 1;
			node++;
			/*while ((address[i] != CITY[departure].car.Terminus[j]) && (j < 999))
				j++;
			if (j < 900) {
				for (; CITY[departure].car.Terminus[j] == address[i]; j++) {
					if (current_time > trans_time(CITY[departure].car.time_begin[j]))
						temp_spend = trans_time(CITY[departure].car.time_begin[j]) + 24 - current_time;
					else
						temp_spend = trans_time(CITY[departure].car.time_begin[j]) - current_time;
					temp_spend += spend;
					CITY[departure].time_and_cost[i].Departure_Station = address[departure];
					CITY[departure].time_and_cost[i].money_cost = CITY[departure].car.money_cost[j];
					CITY[departure].time_and_cost[i].Terminus = address[i];
					CITY[departure].time_and_cost[i].time_begin = CITY[departure].car.time_begin[j];
					CITY[departure].time_and_cost[i].time_cost = temp_spend;
					CITY[departure].time_and_cost[i].Vec = "car";
					CITY[departure].time_and_cost[i].vehicle_number = CITY[departure].car.vehicle_number[j];
					double ts = spend + temp_spend;
					while (ts > 24)
						ts -= 24;
					DFS(i, terminus, temp_spend, cost + CITY[departure].car.money_cost[j], ts);
					CITY[departure].time_and_cost[i].Departure_Station = "";
					CITY[departure].time_and_cost[i].money_cost = 0;
					CITY[departure].time_and_cost[i].Terminus = "";
					CITY[departure].time_and_cost[i].time_begin = "";
					CITY[departure].time_and_cost[i].time_cost = 0;
					CITY[departure].time_and_cost[i].Vec = "";
					CITY[departure].time_and_cost[i].vehicle_number = "";
				}
			}*/
			j = 0;
			while ((address[i] != CITY[departure].train.Terminus[j]) && (j < 100))
				j++;
			if (j < 99) {
				for (; CITY[departure].train.Terminus[j] == address[i]; j++) {
					if (current_time > trans_time(CITY[departure].train.time_begin[j]))
						temp_spend = trans_time(CITY[departure].train.time_begin[j]) + 24 - current_time;
					else
						temp_spend = trans_time(CITY[departure].train.time_begin[j]) - current_time;
					temp_spend += spend;
					CITY[departure].time_and_cost[i].Departure_Station = address[departure];
					CITY[departure].time_and_cost[i].money_cost = CITY[departure].train.money_cost[j];
					CITY[departure].time_and_cost[i].Terminus = address[i];
					CITY[departure].time_and_cost[i].time_begin = CITY[departure].train.time_begin[j];
					CITY[departure].time_and_cost[i].time_cost = temp_spend;
					CITY[departure].time_and_cost[i].Vec = "car";
					CITY[departure].time_and_cost[i].vehicle_number = CITY[departure].train.vehicle_number[j];
					double ts = spend + temp_spend;
					while (ts > 24)
						ts -= 24;
					DFS(i, terminus, temp_spend, cost + CITY[departure].train.money_cost[j], ts);
					CITY[departure].time_and_cost[i].Departure_Station = "";
					CITY[departure].time_and_cost[i].money_cost = 0;
					CITY[departure].time_and_cost[i].Terminus = "";
					CITY[departure].time_and_cost[i].time_begin = "";
					CITY[departure].time_and_cost[i].time_cost = 0;
					CITY[departure].time_and_cost[i].Vec = "";
					CITY[departure].time_and_cost[i].vehicle_number = "";
				}
			}
			/*j = 0;
			while ((address[i] != CITY[departure].plane.Terminus[j]) && (j < 999))
				j++;
			if (j < 900) {
				for (; CITY[departure].plane.Terminus[j] == address[i]; j++) {
					if (current_time > trans_time(CITY[departure].plane.time_begin[j]))
						temp_spend = trans_time(CITY[departure].plane.time_begin[j]) + 24 - current_time;
					else
						temp_spend = trans_time(CITY[departure].plane.time_begin[j]) - current_time;
					temp_spend += spend;
					CITY[departure].time_and_cost[i].Departure_Station = address[departure];
					CITY[departure].time_and_cost[i].money_cost = CITY[departure].plane.money_cost[j];
					CITY[departure].time_and_cost[i].Terminus = address[i];
					CITY[departure].time_and_cost[i].time_begin = CITY[departure].plane.time_begin[j];
					CITY[departure].time_and_cost[i].time_cost = temp_spend;
					CITY[departure].time_and_cost[i].Vec = "plane";
					CITY[departure].time_and_cost[i].vehicle_number = CITY[departure].plane.vehicle_number[j];
					double ts = spend + temp_spend;
					while (ts > 24)
						ts -= 24;
					DFS(i, terminus, temp_spend, cost + CITY[departure].plane.money_cost[j], ts);
					CITY[departure].time_and_cost[i].Departure_Station = "";
					CITY[departure].time_and_cost[i].money_cost = 0;
					CITY[departure].time_and_cost[i].Terminus = "";
					CITY[departure].time_and_cost[i].time_begin = "";
					CITY[departure].time_and_cost[i].time_cost = 0;
					CITY[departure].time_and_cost[i].Vec = "";
					CITY[departure].time_and_cost[i].vehicle_number = "";
				}
			}*/
			node--;
			path_3[node] = -1;
			visit[i] = -1;
		}
	}
}

void plan_3(int departure, int terminus, double current_time, double limit) {
	start_t = current_time;
	limit_t = limit;
	node = 0;
	for (int i = 0; i < 15; i++) {
		prev_3[i] = -1;
		visit[i] = -1;
		path_3[i] = -1;
		path3[i] = -1;
	}
	path_3[0] = departure;
	visit[departure] = 1;
	node++;
	DFS(departure, terminus, 0, 0, current_time);
	for (int i = 0; path3[i] != -1; i++)
		cout << path3[i] << "->";
	cout << endl;
}

double dist_1[maxnum];
int prev_1[maxnum];
int reque[16];
double temp;

double searchpath_3(int v, int u, int hour, int minute) {
	//v表示起始点，u表示终点，hour、minute分别表示开始查询的小时、分钟
	int que[maxnum];
	for (int i = 0; i < maxnum; i++) {
		reque[i] = -1;
	}
	int tot = 1, j = 1;
	que[tot] = u;
	tot++;
	int tmp = prev_1[u];
	while (tmp != v)
	{
		que[tot] = tmp;
		tot++;
		tmp = prev_1[tmp];
	}
	que[tot] = v;
	//构造顺序的路线序号
	for (int i = tot; i >= 1; i--) {
		reque[j] = que[i] - 1;
		j++;
	}
	int d = 0, h = 0, m = 0;
	double begin_1, begin_2, end;
	if (reque[2] != -1) {
		double time = atof(CITY[reque[1]].min_cost[reque[2]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[1]].min_cost[reque[2]].time_begin.substr(3, 2).c_str()) / 60;
		double time_1 = hour + minute / 60;
		if (time_1 > time)
			time = time - time_1 + 24;
		else
			time = time - time_1;
		for (int i = 1; reque[i + 1] != -1; i++) {
			begin_1 = atof(CITY[reque[i]].min_cost[reque[i + 1]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[i]].min_cost[reque[i + 1]].time_begin.substr(3, 2).c_str()) / 60;
			if (reque[i + 2] != -1)
				begin_2 = atof(CITY[reque[i + 1]].min_cost[reque[i + 2]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[i + 1]].min_cost[reque[i + 2]].time_begin.substr(3, 2).c_str()) / 60;
			else
				begin_2 = 0;
			end = begin_1 + CITY[reque[i]].min_cost[reque[i + 1]].time_cost;
			if (begin_2 != 0) {
				if ((end - 24) > begin_2)
					time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - (end - 24) + 24;
				else {
					if (end <= begin_2)
						time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - end;
					else
						time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - (end - 24);
				}
			}
			else
				time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost;
		}
		return time;
	}
	return 0;
}

void find_limit_time_min_cost(int departure, int terminus, int hour, int minute, double limit, double cost[maxnum - 1][maxnum - 1]) {
	//departure表示起始站，terminus表示终点站，hour、minute表示查询的小时和分钟，limit表示用户的规定时间，cost[][]表示最小花费矩阵
	Dijkstra(15, departure + 1, dist_1, prev_1, cost);
	if (searchpath_3(departure + 1, terminus + 1, hour, minute) <= limit) {
		return;
	}
	else {
		for (int i = 1; reque[i + 1] != -1; i++) {
			if (searchpath_3(departure + 1, terminus + 1, hour, minute) > 40)
				break;
			if (searchpath_3(departure + 1, terminus + 1, hour, minute) > limit) {
				if (i == 1) {
					temp = cost[reque[i]][reque[i + 1]];
					cost[reque[i]][reque[i + 1]] = 9999;
					cout << i << endl;
					find_limit_time_min_cost(departure, terminus, hour, minute, limit, cost);
				}
				else {
					cost[reque[i - 1]][reque[i]] = temp;
					temp = cost[reque[i]][reque[i + 1]];
					cost[reque[i]][reque[i + 1]] = 9999;
					Dijkstra(15, departure + 1, dist_1, prev_1, cost);
					cout << i << endl;
					find_limit_time_min_cost(departure, terminus, hour, minute, limit, cost);
				}
			}
			else
				break;
		}
	}
}

void plan3(int departure, int terminus, int day, int hour, int minute, double limit, double cost[maxnum - 1][maxnum - 1]) {
	//departure表示起始站，terminus表示终点站，day、hour、minute表示查询的天数、小时和分钟，limit表示用户的规定时间，cost[][]表示最小花费矩阵
	for (int i = 0; i < maxnum; i++) {
		dist_1[i] = maxint;
		prev_1[i] = 0;
	}
	find_limit_time_min_cost(departure, terminus, hour, minute, limit, cost);
	for (int i = 1; reque[i] != -1; i++)
		cout << reque[i] << "\t";
	cout << endl;
	int d = 0, h = 0, m = 0;
	double begin_1, begin_2, end;
	double time = atof(CITY[reque[1]].min_cost[reque[2]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[1]].min_cost[reque[2]].time_begin.substr(3, 2).c_str()) / 60;
	double time_1 = hour + minute / 60;
	if (time_1 > time)
		time = time - time_1 + 24;
	else
		time = time - time_1;
	for (int i = 1; reque[i + 1] != -1; i++) {
		begin_1 = atof(CITY[reque[i]].min_cost[reque[i + 1]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[i]].min_cost[reque[i + 1]].time_begin.substr(3, 2).c_str()) / 60;
		if (reque[i + 2] != -1)
			begin_2 = atof(CITY[reque[i + 1]].min_cost[reque[i + 2]].time_begin.substr(0, 2).c_str()) + atof(CITY[reque[i + 1]].min_cost[reque[i + 2]].time_begin.substr(3, 2).c_str()) / 60;
		else
			begin_2 = 0;
		end = begin_1 + CITY[reque[i]].min_cost[reque[i + 1]].time_cost;
		if (begin_2 != 0) {
			if ((end - 24) > begin_2)
				time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - (end - 24) + 24;
			else {
				if (end <= begin_2)
					time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - end;
				else
					time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost + begin_2 - (end - 24);
			}
		}
		else
			time += CITY[reque[i]].min_cost[reque[i + 1]].time_cost;
	}
	time += time_1;
	d = time / 24;
	h = time - d * 24;
	m = (time - d * 24 - h) * 60;

	for (int i = 1; reque[i + 1] != -1; i++) {
		std::cout << CITY[reque[i]].min_cost[reque[i + 1]].Departure_Station << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].Vec << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].vehicle_number << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].Terminus << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].time_begin << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].time_cost << '\t' << CITY[reque[i]].min_cost[reque[i + 1]].money_cost;
		std::cout << endl;
	}
	std::cout << "第" << d + day << "天 " << h << ":" << m << "  到达" << ADDRESS[terminus] << endl;

}

int main()
{
	double dist[maxnum];
	int prev[maxnum] = { 0 };
	int i = 0;
	cout << maxnum + 22 << endl;

	//将文件信息输入，初始化所有城市的信息
	string file1 = "train.txt", file2 = "car.txt", file3 = "plane.txt";
	
	for(i = 0; i < 15; i++)
		CITY[i].init_city(file1, file2, file3, address[i]);
	for (i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << CITY[i].car.Terminus[j] << '\t';
		}
		std::cout << endl;
	}
	
	for (i = 0; i < maxnum; i++)
		dist[i] = maxint;

	int hour, minute, day;

	std::cout << "请输入查询时间（格式如同12：00）：" << endl;
	std::cin >> day;
	std::cin >> hour;
	std::cin >> minute;

	//算法一
	/*
	//建立每个城市到每个城市的最少花费的矩阵
	double cost[15][15] = { 0 };
	for (i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cost[i][j] = find_min_cost_cities(i, address[j], j, hour, minute);
		}
	}

	//输出最少花费矩阵
	for (i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << CITY[i].car.vehicle_number[j] << '\t';
		}
		std::cout << endl;
	}

	for (i = 0; i < maxnum; i++)
		prev[i] = 0;

	//用户的输入与线路查询
	string  Departure, Terminus;
	int begin, end;
	std::cout << "请输入出发地 目的地城市名字（输入###退出）：" << endl;
	std::cin >> Departure >> Terminus;
	begin = find_address(Departure);
	end = find_address(Terminus);
	while ((Departure != "###")  || (Terminus != "###")) {
		if (begin < 15) {
			std::cout << ADDRESS[begin] << "到" << ADDRESS[end] << "的最少花费：";
			Dijkstra(15, begin + 1, dist, prev, cost);// 最短路径长度
			std::cout << dist[end + 1] << endl;
			std::cout << ADDRESS[begin] << "到" << ADDRESS[end] << "的路径为：";
			searchPath(prev, begin + 1, end + 1, day, hour, minute);// 路径
			std::cout << endl;
			std::cout << "请输入出发地 目的地城市名字（输入###退出）：" << endl;
			std::cin >> Departure >> Terminus;
			begin = find_address(Departure);
			end = find_address(Terminus);
		}
		else if((Departure != "###") || (Terminus != "###")){
			if (begin > 14)
				std::cout << "输入未知城市--" << Departure << endl;
			if(end > 14)
				std::cout << "输入未知城市--" << Terminus << endl;
			std::cout << "请重新输入：" << endl << endl;
			std::cout << "请输入出发地 目的地城市名字（输入###退出）：" << endl;
			std::cin >> Departure >> Terminus;
			begin = find_address(Departure);
			end = find_address(Terminus);
		}
	} */

	//算法二
	/*
	//建立每个城市到每个城市的最少花费的矩阵
	Time_cost cost[15][15] = { 0 };
	for (i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cost[i][j] = find_shortest_time_cities(i, address[j], j, hour, minute);
		}
	}

	for (i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			std::cout << cost[i][j].time_cost << '\t';
		}
		std::cout << endl;
	}

	for (i = 0; i < maxnum; i++)
		prev[i] = 0;

	//用户的输入与线路查询
	string  Departure, Terminus;
	int begin, end;
	std::cout << "请输入出发地 目的地城市名字（输入###退出）：" << endl;
	std::cin >> Departure >> Terminus;
	begin = find_address(Departure);
	end = find_address(Terminus);
	while ((Departure != "###") || (Terminus != "###")) {
		if (begin < 15) {
			std::cout << ADDRESS[begin] << "到" << ADDRESS[end] << "的最少花费：";
			Dijkstra_2(15, begin + 1, dist, prev, cost, hour + minute / 60);// 最短路径长度
			std::cout << dist[end + 1] << endl;
			std::cout << ADDRESS[begin] << "到" << ADDRESS[end] << "的路径为：";
			searchPath_2(prev, begin + 1, end + 1, day, hour, minute, dist[end + 1]);// 路径
			std::cout << endl;
			std::cout << "请输入出发地 目的地城市名字（输入###退出）：" << endl;
			std::cin >> Departure >> Terminus;
			begin = find_address(Departure);
			end = find_address(Terminus);
		}
		else if ((Departure != "###") || (Terminus != "###")) {
			if (begin > 14)
				std::cout << "输入未知城市--" << Departure << endl;
			if (end > 14)
				std::cout << "输入未知城市--" << Terminus << endl;
			std::cout << "请重新输入：" << endl << endl;
			std::cout << "请输入出发地 目的地城市名字（输入###退出）：" << endl;
			std::cin >> Departure >> Terminus;
			begin = find_address(Departure);
			end = find_address(Terminus);
		}
	}*/

	//算法三
	
	int de, te;
	double li;
	std::cin >> de >> te;
	std::cin >> li;
	//plan_3(de, te, (day - 1) * 24 + hour + minute / 60, li);
	//建立每个城市到每个城市的最少花费的矩阵
	double cost[15][15] = { 0 };
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cost[i][j] = find_min_cost_cities(i, address[j], j, hour, minute);
		}
	}
	plan3(de, te, day, hour, minute, li, cost);
	cout << endl << CITY[2].min_cost[5].time_cost;
}
/*string file = "1BJ.txt";
	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

	char c;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		if (c == '\t')
			cout << "    ";
		else if (c == ' ')
			cout << " ";
		else
			cout << c;

	}
	infile.close();             //关闭文件输入流

	string A = "12   ";
	int n = atoi(A.c_str()) + 1;
	cout << n;
	std::cout << "Hello World!\n"; */

