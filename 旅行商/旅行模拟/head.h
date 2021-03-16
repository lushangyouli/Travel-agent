#ifndef HEAD_00_
#define HEAD_00_

#include<iostream>
#include<string>
#include<cstring>
#include<fstream>

using namespace std;
const int numofcity = 10;
const int infinity = 99999;

typedef struct 
{
	string name;
	int cost;
	int start_hour;
	int travel_hour;
}Route;

typedef struct
{
	int startnode, arrivenode, passnode[9];//起始城市，终点城市和途径城市编号
	int true_pass[70];//储存实际经过的节点顺序
}Tour;


typedef struct
{
	int min_time;
	int min_cost;
	int porder[70];//按路径顺序储存的城市节点
	int city_save[70][2];//city_save[i][0]储存到达该城市的时间,city_save[i][1]储存从该城市出发的时间
	int ptrans[70];//require[]矩阵用来储存第i个节点出发的交通工具代号
}Plan;







void input(Route mat[][10][6]);//时刻表初始化函数
void show_city(int);//显示相应代号的城市
void show_tran(char);//显示相应代号的交通方式名称
void swap(int &a, int &b);//交换a,b的值
void show_city1(int, ostream &);
void show_tran1(char, ostream &);



Tour count(Tour &,int less[][10]);//当有要求途径点时调用
void count_min(Tour&, int,int,int[][10],int[]);//求花费最少用的辅助函数
int get_money(const Tour & ,int[], int[][10]);//求当前方案花多少钱
void set_tour(Tour &, int[], int[][10]);//设置路线中实际经过的节点
Tour count1_two(Tour &, int[][10]);//当没有要求途径点，且起始点和终点没有直接路径时调用
Plan cheap_plan(const Tour&,int[][10]);
void show_cheap(Plan &,ostream &);

void get_leasttime(Tour & tr, Plan &p, int current_time);//没有途径点时调用
void get_leasttime2(const Tour&, Plan &, int current_time);
void permutation1(Tour &, Plan &,const int, int, int, int[]);
int get_time(int, int, int);
void set_leasttime_plan(Plan &, int, int, int);
void show_leasttime(int, Plan &,ostream &);

void get_limittime1(Tour &, Plan &p, int, int);
void Dfs1(int, int, int, int, int,Plan &);
void get_limittime2(Tour &, Plan &, int, int);
void permutation2(Tour &, Plan &, int, int, int[]);
void Dfs2(int, int, int, int, int, int, Plan &, int[]);

void simulation1(const Plan &,ostream &);
void simulation2(const Plan &, int,ostream &);




#endif