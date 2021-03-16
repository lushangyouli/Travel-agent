#include<iostream>
#include<cstring>
#include<string>
#include"head.h"

static int limit_time, start_time;
static int total_node, node_num;
static int min = infinity;
static int book[10], temp_node[10];
static int path[70], temp_tran[70];

extern Route mat[10][10][6];
using namespace std;

void get_limittime2(Tour & tr, Plan &p, int start, int limit)
{
	Tour tour_temp;
	int i, numofnode;
	int node[9];
	numofnode = 0;
	limit_time = limit;
	start_time = start;
	tour_temp.startnode = tr.startnode;
	tour_temp.arrivenode = tr.arrivenode;
	for (i = 0; tr.passnode[i] != -1; i++)
	{
		tour_temp.passnode[i] = tr.passnode[i];
		node[i] = tr.passnode[i];
		numofnode++;
	}
	for (; i < 9; i++) {
		tour_temp.passnode[i] = -1;
		node[i] = -1;
	}
	total_node = numofnode + 2;
	permutation2(tour_temp, p, 0, numofnode - 1, node);
}

void permutation2(Tour & tr, Plan &p, int low, int high, int node[])
{
	if (low == high) {
		int m = 0;
		temp_node[m] = tr.startnode;
		for (; node[m] != -1 && m < 9; m++)
			temp_node[m + 1] = node[m];
		temp_node[m + 1] = tr.arrivenode;
		for (int m = 0; m < 70; m++) {
			path[m] = -1;
			temp_tran[m] = -1;
		}
		for (int m = 0; m < 10; m++)
			book[m] = -1;
		node_num = 0;
		path[0] = tr.startnode;
		book[tr.startnode] = 1;
		node_num++;
		Dfs2(temp_node[0], temp_node[1], 0, 0, start_time, 0, p, temp_node);
	}
	else {
		for (int i = low; i <= high; i++) {
			swap(node[i], node[low]);
			permutation2(tr, p, low + 1, high, node);
			swap(node[i], node[low]);
		}
	}
}

void Dfs2(int cur, int dest, int spend, int cost, int current_time, int times, Plan & p, int node[])
{
	if (cur == dest) {
		if (times == total_node - 2) {
			if (spend <= limit_time) {
				if (cost < min) {
					min = cost;
					p.min_cost = cost;
					p.min_time = spend;
					for (int k = 0; k < 70; k++) {
						p.porder[k] = -1;
						p.ptrans[k] = -1;
					}
					for (int k = 0; path[k] != -1; k++)
						p.porder[k] = path[k];
					for (int k = 0; temp_tran[k] != -1; k++)
						p.ptrans[k] = temp_tran[k];
					p.city_save[0][0] = -1;
					int k;
					for (k = 1; p.porder[k + 1] != -1; k++) {
						p.city_save[k - 1][1] = mat[p.porder[k - 1]][p.porder[k]][p.ptrans[k - 1]].start_hour;
						p.city_save[k][0] = (mat[p.porder[k - 1]][p.porder[k]][p.ptrans[k - 1]].start_hour + mat[p.porder[k - 1]][p.porder[k]][p.ptrans[k - 1]].travel_hour) % 24;
					}
				}
			}
		}
		else {
			for (int m = 0; m < 10; m++)
				book[m] = -1;
			book[node[times + 1]] = 1;
			Dfs2(node[times + 1], node[times + 2], spend, cost, current_time, times + 1, p, node);
		}
		return;
	}
	if (spend > limit_time || cost > min)return;
	int i, temp_spend;
	for (i = 0; i < 10; i++) {
		if (book[i] == -1 && mat[cur][i][0].start_hour != -1) {
			path[node_num] = i;
			book[i] = 1;
			node_num++;
			for (int k = 0; k < 6 && mat[cur][i][k].start_hour != -1; k++) {
				if (current_time > mat[cur][i][k].start_hour)
					temp_spend = mat[cur][i][k].start_hour - current_time + 24 + spend + mat[cur][i][k].travel_hour;
				else
					temp_spend = mat[cur][i][k].start_hour - current_time + spend + mat[cur][i][k].travel_hour;
				temp_tran[node_num - 2] = k;
				Dfs2(i, dest, temp_spend, cost + mat[cur][i][k].cost, (current_time + temp_spend) % 24, times, p, node);
				temp_tran[node_num - 2] = -1;
			}
			node_num--;
			path[node_num] = -1;
			book[i] = -1;

		}
	}
}