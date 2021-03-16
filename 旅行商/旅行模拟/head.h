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
	int startnode, arrivenode, passnode[9];//��ʼ���У��յ���к�;�����б��
	int true_pass[70];//����ʵ�ʾ����Ľڵ�˳��
}Tour;


typedef struct
{
	int min_time;
	int min_cost;
	int porder[70];//��·��˳�򴢴�ĳ��нڵ�
	int city_save[70][2];//city_save[i][0]���浽��ó��е�ʱ��,city_save[i][1]����Ӹó��г�����ʱ��
	int ptrans[70];//require[]�������������i���ڵ�����Ľ�ͨ���ߴ���
}Plan;







void input(Route mat[][10][6]);//ʱ�̱��ʼ������
void show_city(int);//��ʾ��Ӧ���ŵĳ���
void show_tran(char);//��ʾ��Ӧ���ŵĽ�ͨ��ʽ����
void swap(int &a, int &b);//����a,b��ֵ
void show_city1(int, ostream &);
void show_tran1(char, ostream &);



Tour count(Tour &,int less[][10]);//����Ҫ��;����ʱ����
void count_min(Tour&, int,int,int[][10],int[]);//�󻨷������õĸ�������
int get_money(const Tour & ,int[], int[][10]);//��ǰ����������Ǯ
void set_tour(Tour &, int[], int[][10]);//����·����ʵ�ʾ����Ľڵ�
Tour count1_two(Tour &, int[][10]);//��û��Ҫ��;���㣬����ʼ����յ�û��ֱ��·��ʱ����
Plan cheap_plan(const Tour&,int[][10]);
void show_cheap(Plan &,ostream &);

void get_leasttime(Tour & tr, Plan &p, int current_time);//û��;����ʱ����
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