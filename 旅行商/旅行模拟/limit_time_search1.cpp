#include<iostream>
#include<string>
#include<cstring>
#include"head.h"

static int start_time, limit_time;
static int min = infinity;
static int numofnode;
static int book[10];
static int path[10], tran[10];

extern Route mat[10][10][6];

using namespace std;

void get_limittime1(Tour & tr, Plan & p, int start, int limit)
{
	start_time = start;
	limit_time = limit;
	numofnode = 0;
	for (int i = 0; i < 10; i++) {
		path[i] = -1;
		book[i] = -1;
		tran[i] = -1;
	}
	path[0] = tr.startnode;
	book[tr.startnode] = 1;
	numofnode++;
	Dfs1(tr.startnode, tr.arrivenode, 0, 0, start_time,p);
}


void Dfs1(int cur, int dest, int spend, int cost, int current_time,Plan &p)//深度优先搜索
{
	if (cur == dest) {
		if (spend <= limit_time) {
			if (cost < min) {
				min = cost;
				p.min_time = spend;
				p.min_cost = cost;
				for (int m = 0; m < 70; m++) {
					p.porder[m] = -1;
					p.ptrans[m] = -1;
				}	
				for (int m = 0; path[m] != -1; m++)
					p.porder[m] = path[m];
				for (int m = 0; tran[m] != -1; m++)
					p.ptrans[m] = tran[m];
				p.city_save[0][0] = -1;
				int k;
				for (k = 0; p.porder[k + 1] != -1; k++) {
					p.city_save[k][1] = mat[p.porder[k]][p.porder[k + 1]][p.ptrans[k]].start_hour;
					p.city_save[k + 1][0] = (mat[p.porder[k]][p.porder[k + 1]][p.ptrans[k]].start_hour + mat[p.porder[k]][p.porder[k + 1]][p.ptrans[k]].travel_hour) % 24;
				}
				p.city_save[k][1] = -1;
				return;
			}
		}
	}
	if (spend > limit_time) return;
	int i, temp_spend;
	for (i = 0; i < 10; i++) {
		if (book[i] == -1 && mat[cur][i][0].start_hour != -1) {
			path[numofnode] = i;
			book[i] = 1;
			numofnode++;
			for (int k = 0; k < 6 && mat[cur][i][k].start_hour != -1; k++) {
				if (current_time > mat[cur][i][k].start_hour)
					temp_spend = mat[cur][i][k].start_hour - current_time + 24 + spend+mat[cur][i][k].travel_hour;
				else
					temp_spend = mat[cur][i][k].start_hour - current_time + spend+mat[cur][i][k].travel_hour;
				tran[numofnode - 2] = k;
				Dfs1(i, dest, temp_spend, cost + mat[cur][i][k].cost, (current_time + temp_spend) % 24,p);
				tran[numofnode - 2] = -1;
			}
			numofnode--;
			path[numofnode] = -1;
			book[i] = -1;

		}
	}
}
