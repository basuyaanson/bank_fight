// 銀行大戰 製作陳政鴻
#pragma once
#include<iostream>
#include<graphics.h> //easyx
#include<vector>
#include<conio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")//靜態庫
using namespace std;

//定義畫面長寬
constexpr auto swidth = 600;
constexpr auto sheight = 1100;

constexpr auto hurttime = 400;//受到攻擊後,添加無敵幀
unsigned int xhp = 5;//主角血量
unsigned int frequency = 30;//主角子彈頻率
unsigned int killnum = 130;//勝利條件

//按鈕點擊判定
bool pointinrect(int x, int y, RECT& r)
{
	return(r.left <= x && x <= r.right && r.top <= y && y <= r.bottom);
}

//碰撞檢測
bool rectcrashrect(RECT& r1, RECT& r2)
{
	RECT r;
	r.left = r1.left - (r2.right - r2.left);
	r.right = r1.right;
	r.top = r1.top - (r2.bottom - r2.top);
	r.bottom = r1.bottom;

	return(r.left < r2.left&& r2.left <= r.right && r.top <= r2.top && r2.top <= r.bottom);
}



