#include <bits/stdc++.h>int main() {	int directions[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};	int n, m, k;	int fire[109][109], people[109][109];	int ex, ey;	int biNahayat = 0x3f3f3f3f;	char s[109];			scanf("%d%d%d", &n, &m, &k);		std::queue<std::tuple<int, int>> fire_queue, people_queue;	memset(fire, 0x3f, sizeof(fire));	memset(people, 0x3f, sizeof(people));		int kk = 1;	while (kk <= n) 	{		scanf(" %s", s + 1);				int tt = 1;		while (tt <= m) 		{			//This is fire			if (s[tt] == 'f') 			{				fire_queue.emplace(kk, tt), fire[kk][tt] = 0;			}			//This is mohsen's friend			else if (s[tt] == 's') 			{				people_queue.emplace(kk, tt), people[kk][tt] = 0;			}			//This is mohsen			else if (s[tt] == 't') 			{				ex = kk, ey = tt;			}			tt++;		}		kk++;	}		int x, y, nx, ny;	while (!fire_queue.empty()) 	{		std::tie(x, y) = fire_queue.front();		fire_queue.pop();				for (int i = 0; i < 8; i++) 		{			nx = x + directions[i][0], ny = y + directions[i][1];			if (1 <= nx && nx <= n && 1 <= ny && ny <= m && fire[nx][ny] == biNahayat) 			{				fire[nx][ny] = fire[x][y] + k;				fire_queue.emplace(nx, ny);			}		}	}		while (!people_queue.empty()) 	{		std::tie(x, y) = people_queue.front();		people_queue.pop();		for (int i = 0; i < 4; i++) 		{			nx = x + directions[i][0], ny = y + directions[i][1];			if (1 <= nx && nx <= n && 1 <= ny && ny <= m && people[nx][ny] == biNahayat) 			{				if (people[x][y] + 1 < fire[nx][ny]) 				{					people[nx][ny] = people[x][y] + 1;					people_queue.emplace(nx, ny);				}			}		}	}		if (people[ex][ey] == biNahayat) 	{		printf("Impossible");	}	else 	{		printf("%d", people[ex][ey]);	}    return 0;}