#pragma once
// �Ȧ�O�þ� �s�@���F�E
#include<iostream>
#include<graphics.h> //easyx
#include<vector>
#include<conio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")//�R�A�w
using namespace std;

//�w�q�e�����e
constexpr auto swidth = 600;
constexpr auto sheight = 1100;

constexpr auto hurttime = 400;//���������,�K�[�L�ĴV
unsigned int xhp = 5;//�D����q

//���s�I���P�w
bool pointinrect(int x, int y, RECT& r)
{
	return(r.left <= x && x <= r.right && r.top <= y && y <= r.bottom);
}

//�I���˴�
bool rectcrashrect(RECT& r1, RECT& r2)
{
	RECT r;
	r.left = r1.left - (r2.right - r2.left);
	r.right = r1.right;
	r.top = r1.top - (r2.bottom - r2.top);
	r.bottom = r1.bottom;

	return(r.left < r2.left&& r2.left <= r.right && r.top <= r2.top && r2.top <= r.bottom);
}