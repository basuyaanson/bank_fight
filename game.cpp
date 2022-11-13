#include "main.h"
//音樂類
class music
{
public:
//主頁音樂
void bgm1()
		{
			mciSendString(L"open ./music/starbgm.mp3", 0, 0, 0);
			mciSendString(L"close ./music/victory.mp3", 0, 0, 0);
			mciSendString(L"close ./music/defeat.mp3", 0, 0, 0);
			Sleep(2);
			mciSendString(L"play ./music/starbgm.mp3 repeat", 0, 0, 0);
		}
//戰鬥音樂
void bgm2()
		{
			mciSendString(L"close ./music/starbgm.mp3", 0, 0, 0);
			mciSendString(L"open ./music/battlebgm.mp3", 0, 0, 0);
			mciSendString(L"play ./music/battlebgm.mp3 repeat", 0, 0, 0);
		}
//戰敗音樂
void bgm3()
		{
			mciSendString(L"close ./music/herodeat.mp3", 0, 0, 0);
			mciSendString(L"close ./music/battlebgm.mp3", 0, 0, 0);
			mciSendString(L"open ./music/defeat.mp3", 0, 0, 0);
			mciSendString(L"play ./music/defeat.mp3 repeat", 0, 0, 0);
			mciSendString(L"open .music//herodeat.mp3", 0, 0, 0);
			Sleep(320);
			mciSendString(L"play ./music/herodeat.mp3", 0, 0, 0);

		}
//勝利音樂
void bgm4()
		{
			mciSendString(L"close ./music/battlebgm.mp3", 0, 0, 0);
			mciSendString(L"open ./music/victory.mp3", 0, 0, 0);
			mciSendString(L"play ./music/victory.mp3 repeat", 0, 0, 0);
		}
//戰敗語音
void hurtsound()
		{
			mciSendString(L"close ./music/hero_hurt.mp3", 0, 0, 0);
			mciSendString(L"open ./music/hero_hurt.mp3", 0, 0, 0);
			mciSendString(L"play ./music/hero_hurt.mp3", 0, 0, 0);

		}
//技能音效
void skill()
{
	mciSendString(L"close ./music/skill.mp3", 0, 0, 0);
	mciSendString(L"open ./music/skill.mp3", 0, 0, 0);
	mciSendString(L"play ./music/skill.mp3", 0, 0, 0);
}
//標題語音
void title()
{
	mciSendString(L"close ./music/title.mp3", 0, 0, 0);
	mciSendString(L"open ./music/title.mp3", 0, 0, 0);
	mciSendString(L"play ./music/title.mp3", 0, 0, 0);
}
//擊殺音效
void sound()
{
	mciSendString(L"close ./music/kill.mp3", 0, 0, 0);
	mciSendString(L"open ./music/kill.mp3", 0, 0, 0);
	mciSendString(L"play ./music/kill.mp3", 0, 0, 0);
}
//技能語音
void skillline()
{
	mciSendString(L"close ./music/skillline.mp3", 0, 0, 0);
	mciSendString(L"open ./music/skillline.mp3", 0, 0, 0);
	mciSendString(L"play ./music/skillline.mp3", 0, 0, 0);
}
};
//介面類
class ui
{
public:
//開始介面
void welcome()
	{		
	  
		LPCTSTR title = _T("銀行保衛戰");
		LPCTSTR tplay = _T("開始遊戲");
		LPCTSTR texit = _T("退出遊戲");
		LPCTSTR tabout = _T("關於");
		LPCTSTR tintroduce = _T("說明");
		IMAGE startimg;
		loadimage(&startimg, L"./img/start.jpg", 600, 1200);
		RECT tplayr, texitr, taboutr, tintroducer; //按鈕

		while (true)
		{
			BeginBatchDraw();
			setbkcolor(WHITE);
			cleardevice();
			putimage(0, 0, &startimg);
			settextstyle(80, 0, _T("黑體"), 0, 0, 600, 0, 0, 0);

			settextcolor(BLACK);
			setbkmode(TRANSPARENT);

			outtextxy(swidth / 2 - textwidth(title) / 2, sheight / 8, title);//文本位置

			//設定按鈕位置
			settextstyle(60, 0, _T("黑體"));
			tplayr.left = swidth / 2 - textwidth(tplay) / 2;
			tplayr.right = tplayr.left + textwidth(tplay);
			tplayr.top = sheight / 8 * 2.5;
			tplayr.bottom = tplayr.top + textheight(texit);

			texitr.left = swidth / 2 - textwidth(tplay) / 2;
			texitr.right = texitr.left + textwidth(tplay);
			texitr.top = sheight / 8 * 3.3;
			texitr.bottom = texitr.top + textheight(tabout);

			taboutr.left = swidth / 2 - textwidth(texit) / 4;
			taboutr.right = taboutr.left + textwidth(texit);
			taboutr.top = sheight / 8 * 4;
			taboutr.bottom = taboutr.top + textheight(tintroduce);

			tintroducer.left = swidth / 2 - textwidth(tabout) / 2;
			tintroducer.right = tintroducer.left + textwidth(tabout);
			tintroducer.top = sheight / 8 * 4.8;
			tintroducer.bottom = tintroducer.top + textheight(tintroduce);

			outtextxy(tplayr.left, tplayr.top, tplay);
			outtextxy(texitr.left, texitr.top, texit);
			outtextxy(taboutr.left, taboutr.top, tabout);
			outtextxy(tintroducer.left, tintroducer.top, tintroduce);

			EndBatchDraw();

			music mus;
			mus.bgm1();

			ExMessage mess;
			getmessage(&mess, EM_MOUSE);

			if (mess.lbutton)
			{
				if (pointinrect(mess.x, mess.y, tplayr))//開始遊戲
				{
					return;
				}
				else if (pointinrect(mess.x, mess.y, texitr))//退出遊戲
				{
					exit(0);
				}
				else if (pointinrect(mess.x, mess.y, taboutr))//退出遊戲
				{
					about();
				}
				else if (pointinrect(mess.x, mess.y, tintroducer))
				{
					introduce();
				}

			}
		}

	}
//勝利介面
void victory(unsigned long long& kill)
{
	IMAGE victoryimg;
	loadimage(&victoryimg, L"./img/victory.jpg", 900, 1200);
	setbkcolor(WHITE);
	cleardevice();
	putimage(-150, 0, &victoryimg);
	LPCTSTR t1 = _T("任務完成");
	LPCTSTR t2 = _T("按Enterc返回主界面");

	settextcolor(BLACK);
	settextstyle(100, 0, _T("黑體"));
	outtextxy(swidth/2 - textwidth(t1)/2, 100, t1);
	setbkmode(OPAQUE);
	settextstyle(50, 0, _T("黑體"));
	outtextxy(swidth / 2 - textwidth(t2) / 2, 600, t2);
	setbkmode(TRANSPARENT);
	TCHAR* str = new TCHAR[128];
	_stprintf_s(str, 128, _T("擊殺數:% llu"), kill);
	settextcolor(RED);
	settextstyle(60, 0, _T("黑體"));
	outtextxy(swidth / 6, sheight / 5, str);

	music mus;
	mus.bgm4();
	while (true)
	{
		ExMessage mess;
		getmessage(&mess, EM_KEY);
		if (mess.vkcode == 0x0D)
		{
			return;
		}
	}
}
//結束介面
void over(unsigned long long& kill)
{
	IMAGE endimg;
	loadimage(&endimg, L"./img/end.jpg", 600, 1100);
	putimage(0, 0, &endimg);

	TCHAR* str = new TCHAR[128];
	_stprintf_s(str, 128, _T("擊殺數:% llu"), kill);
	settextcolor(RED);
	outtextxy(swidth / 2 - textwidth(str) / 2, sheight / 5, str);

	//按回車健返回
	//LPCTSTR info = _T("按Enterc返回");
	settextstyle(30, 0, _T("黑體"));
	setbkmode(OPAQUE);
	outtextxy(180, 300, L"按Enterc返回主界面");
	setbkmode(TRANSPARENT);
	settextstyle(100, 0, _T("黑體"));
	outtextxy(100, 100, L"任務失敗");
	
	music mus;
	mus.bgm3();
	while (true)
	{
		ExMessage mess;
		getmessage(&mess, EM_KEY);
		if (mess.vkcode == 0x0D)
		{
			return;
		}
	}
}
//關於
void about()
{
	IMAGE aboutimg;
	loadimage(&aboutimg, L"./img/about.jpg", 600, 1200);
	putimage(0, -100, &aboutimg);

	settextstyle(100, 0, _T("黑體"));
	outtextxy(swidth / 3, 50, L"關於");
	settextstyle(30, 0, _T("黑體"));
	outtextxy(swidth / 2.3, 200, L"圖源");
	outtextxy(swidth / 10, 250, L"@itaco_G  @parang9494  @haejooncho");
	outtextxy(swidth / 3.5, 300, L" P:15317640    P:7054606");
	outtextxy(swidth / 2.3, 350, L"音樂");
	outtextxy(swidth / 4, 400, L"[Blue Archive] Theme_23 ");
	outtextxy(swidth / 4, 450, L"[Blue Archive]Theme_27 ");
	outtextxy(swidth / 4, 500, L"[fanmade]便利屋68Party!! ");
	outtextxy(0, 550, L"[Blue Archive]Unwelcome School_Piano Jazz Ver.");
	outtextxy(swidth / 3, 600, L"製作:陳政鴻");
	setbkmode(OPAQUE);
	outtextxy(180, 700, L"按Enterc返回主界面");
	setbkmode(TRANSPARENT);

	while (true)
	{
		ExMessage mess;
		getmessage(&mess, EM_KEY);
		if (mess.vkcode == 0x0D)
		{
			break;
		}
	}
}
//介紹
void introduce()
{
	IMAGE introduceimg;
	loadimage(&introduceimg, L"./img/cg.jpg", 800, 1067);

	putimage(-100, 0, &introduceimg);
	settextstyle(100, 0, _T("黑體"));
	outtextxy(swidth / 3, 50, L"說明");
	settextstyle(30, 0, _T("黑體"));

	LPCTSTR t1 = _T("打擊前來搶銀行的罪犯");
	LPCTSTR t2 = _T("目標是是阻止130人就算成功");
	LPCTSTR t3 = _T("但是請注意,你只有5條命");
	LPCTSTR t4 = _T("被攻擊,撞到罪犯都會減少生命值");
	LPCTSTR t5 = _T("使用滑鼠控制主角");
	LPCTSTR t6 = _T("空格鍵暫停");
	LPCTSTR t7 = _T("s鍵施放技能");
	

	outtextxy(swidth /2-textwidth(t1)/2, 200,t1 );
	outtextxy(swidth / 2 - textwidth(t2)/2, 250, t2);
	outtextxy(swidth / 2 - textwidth(t3)/2, 300, t3);
	outtextxy(swidth / 2 - textwidth(t4)/2, 350,t4);
	outtextxy(swidth / 2 - textwidth(t5)/2, 400, t5);
	outtextxy(swidth / 2 - textwidth(t6)/2, 450, t6);
	outtextxy(swidth / 2 - textwidth(t7)/2, 500, t7);

	setbkmode(OPAQUE);
	outtextxy(180, 600, L"按Enterc返回主界面");
	setbkmode(TRANSPARENT);
	while (true)
	{
		ExMessage mess;
		getmessage(&mess, EM_KEY);
		if (mess.vkcode == 0x0D)
		{
			break;
		}
	}
}
//開場動畫
bool opening()
{
	music mu;
	setbkcolor(WHITE);
	cleardevice();
	TCHAR imgname[256];
	vector<IMAGE> run;
	
	for (int i = 0; i < 66; i++)
	{
		_stprintf_s(imgname, L"./opening/(%d).jpg", i);
		IMAGE g1;
		loadimage(&g1, imgname, 600, 500);
		run.push_back(g1);
	}
	IMAGE imgshow;
	int i = 0;
	Sleep(1000);
	mu.title();
	while (1)
	{
		if (i == 66)
		{
			break;
		}
		imgshow = run[i];
		putimage(0, 50, &imgshow);
		i++;
		Sleep(60);
	}
	return false;
}

private:
};
//資源類 
class BK //背景
{
public:
	//使用建構子初始化
	BK(IMAGE& img)
	:img(img), y(-sheight)
	{
	}
	//背景圖向下動
	void show()
	{
		if (y == 0) { y = -sheight; }
		y += 4; //圖片下滑速度
		putimage(0, y, &img);

	}

private:
	IMAGE& img;
	int y;
};
class hero //主角
{
public:
	hero(IMAGE& img) 
		:img(img), hp(xhp)
	{
	}

	void show()
	{
		TCHAR* str = new TCHAR[128];
		_stprintf_s(str, 128, _T("血量:% d"),hp);
		settextcolor(RED);
		outtextxy(0, 60, str);
		setlinecolor(RED);//血量
		setlinestyle(PS_SOLID, 10);//血量粗細
		line(rect.left, rect.top - 2, rect.left + (img.getwidth() / xhp * hp), rect.top - 2);
		putimage(rect.left, rect.top, &img); //將主角放置在鼠標位置
	}
	void control()//使用鼠標控制主角
	{
		ExMessage mess;
		if (peekmessage(&mess, EM_MOUSE))
		{
			rect.left = mess.x - img.getwidth() / 2;
			rect.top = mess.y - img.getheight() / 2;
			rect.right = rect.right = rect.left + img.getheight();
			rect.bottom = rect.top + img.getheight();
		}
	}
	bool hurt()//受到攻擊
	{
		hp--;	
		music mus;
		mus.hurtsound();
		return (hp == 0) ? false : true;
	}
	RECT& getrect() { return rect; }
private:
	IMAGE& img;
	RECT rect;
	unsigned int hp;
};
class enemy
{
public:
	enemy(IMAGE& img, int x, IMAGE*& boom)
		:img(img), isdie(false), boomsum(0)
	{
		selfboom[0] = boom[0];
		selfboom[1] = boom[1];
		selfboom[2] = boom[2];
		rect.left = x;
		rect.right = rect.left + img.getwidth();
		rect.top = -img.getheight();
		rect.bottom = 0;
	}
	bool show() //讓敵人移動
	{
		if (isdie)
		{
			if (boomsum == 3)
			{
				return false;
			}
			putimage(rect.left, rect.top, selfboom - boomsum);
			boomsum++;
			return true;
		}

		if (rect.top >= sheight)
		{
			return false;//離開畫面後銷毀
		}
		rect.top += 1;
		rect.bottom += 1;
		putimage(rect.left, rect.top, &img);

		return true;
	}

	void Isdie()
	{
		isdie = true;
	}

	RECT& getrect() { return rect; }

private:
	IMAGE& img;
	RECT rect;
	IMAGE selfboom[3];

	bool isdie;
	int boomsum;

};
class bullet                        
{
public:
	bullet(IMAGE& img, RECT pr)
		:img(img)
	{
		rect.left = pr.left + (pr.right - pr.left) / 3 - img.getwidth() / 3;
		rect.right = rect.left + img.getwidth();
		rect.top = pr.top - img.getheight();
		rect.bottom = rect.top + img.getheight();
	}
	bool show()
	{
		if (rect.bottom <= 0)
		{
			return false;
		}
		rect.top -= 15; //子彈速度
		rect.bottom -= 15;
		putimage(rect.left, rect.top, &img);

		return true;
	}

	RECT& getrect() { return rect; }
protected:
	IMAGE& img;
	RECT rect;
};
class ebullet  : public bullet //繼承
{
public:
	ebullet(IMAGE& img, RECT pr)
		:bullet(img, pr)
	{
		rect.left = pr.left + (pr.right - pr.left) / 2 - img.getwidth() / 2;
		rect.right = rect.left + img.getwidth();
		rect.top = pr.bottom;
		rect.bottom = rect.top + img.getheight();
	}
	bool show()
	{
		if (rect.top >= sheight)
		{
			return false;
		}
		rect.top += 5; //子彈速度
		rect.bottom += 5;
		putimage(rect.left, rect.top, &img);

		return true;
	}

};
//技能動畫
void skill1()
	{

	music mu;
	TCHAR imgname[256];
	vector<IMAGE> run;// 圖片容器
		for (int i = 0; i < 23; i++)
	    {
			_stprintf_s(imgname, L"./skill/(%d).jpg", i);
			IMAGE g1;
			loadimage(&g1, imgname, 400,300 );
			run.push_back(g1);
		}
		mu.skill();
		mu.skillline();
		IMAGE imgshow;
		int i = 0;
		while (1)
		{
			if (i == 23)
			{
				break;
			}

			imgshow = run[i];
			putimage(swidth/6,sheight/4, &imgshow);
			i++;
			Sleep(100);
		}

	}
//生成敵人
bool addenemy(vector<enemy*>& es, IMAGE& enemyimg, IMAGE* boom)
{
	enemy* e = new enemy(enemyimg, abs(rand()) % (swidth - enemyimg.getwidth()), boom);//實現敵人隨機生成
	for (auto& i : es)
	{
		if (rectcrashrect(i->getrect(), e->getrect()))//判斷是否重疊
		{
			delete e;
			return false;
		}
	}
	es.push_back(e);
	return true;
}
//遊戲介面
bool play()
{
	ui uii;
	setbkcolor(WHITE);
	cleardevice();
	bool is_play = true;
	IMAGE heroimg, enemyimg, bkimg, bulletimg, bulletimg2; //插入圖片: 主角 敵人 背景圖 子彈 
	IMAGE eboom[3]; //爆炸效果

	loadimage(&heroimg, L"./img/hero.png", 70, 85);
	loadimage(&enemyimg, L"./img/em1.png");
	loadimage(&bkimg, L"./img/bk2.png", swidth, sheight * 2); //格式化
	loadimage(&bulletimg, L"./img/bullet1.png");
	loadimage(&bulletimg2, L"./img/bullet2.png");

	loadimage(&eboom[0], L"./img/boom1.png");
	loadimage(&eboom[1], L"./img/boom2.png");
	loadimage(&eboom[2], L"./img/boom3.png");

	unsigned long long  kill = 0;

	BK bk = BK(bkimg);//背景
	hero hp = hero(heroimg);//主角
	vector<enemy*> es;//敵人列表
	vector<bullet*> bs;//主角子彈
	vector<ebullet*>ebs;//敵人子彈
	int bsing = 0;//子彈頻率

	clock_t hurtlast = clock();//無敵幀
	clock_t skilllast = clock();//超級報射 技能冷卻
	clock_t skilltime = clock();//超級爆射 技能時間

	music mus;
	mus.bgm2();
	
	for (int i = 0; i < 5; i++) //開局生成敵人
	{
		addenemy(es, enemyimg, eboom);
	}
	while (is_play)
	{

		bsing++;//使用幀數來實現自動發射

		if (bsing % frequency == 0)//主角子彈頻率  當幀數等於30的倍數時發射一次
		{
			bs.push_back(new bullet(bulletimg, hp.getrect()));//生成新的子彈
		}

		if (bsing == 120)//敵人子彈頻率
		{
			bsing = 0;
			for (auto& i : es) 
			{
				ebs.push_back(new ebullet(bulletimg2, i->getrect()));
			}
		}
		BeginBatchDraw();

		bk.show();
		Sleep(6);
		flushmessage();
		Sleep(2);
		hp.control();
		hp.show();

		auto bsit = bs.begin();//遍歷(主角子彈)容器
		while (bsit != bs.end())
		{
			if (!(*bsit)->show())
			{
				bsit = bs.erase(bsit);
			}
			else
			{
				bsit++;
			}
		}

		auto ebsit = ebs.begin();//遍歷(敵人子彈)容器
		while (ebsit != ebs.end())
		{
			if (!(*ebsit)->show())//當敵人子彈超出介面,銷毀
			{
				ebsit = ebs.erase(ebsit);
			}
			else
			{
				if (rectcrashrect((*ebsit)->getrect(), hp.getrect()))//碰撞敵人子彈,扣玩家生命
				{
					if (clock() - hurtlast >= hurttime)
					{
						is_play = hp.hurt();

					}
					hurtlast = clock();
				}
				ebsit++;
			}
		}

		TCHAR* str = new TCHAR[128];
		_stprintf_s(str, 128, _T("擊殺數:% llu /% d"), kill,killnum);
		settextcolor(RED);
		settextstyle(30, 0, _T("黑體"));
		outtextxy(0, 0, str);

		auto it = es.begin();////遍歷(敵人)容器
		while (it != es.end())
		{
			if (rectcrashrect((*it)->getrect(), hp.getrect()))//碰撞到敵人,扣玩家生命
			{
				if (clock() - hurtlast >= hurttime)
				{
					is_play = hp.hurt();
				}
				hurtlast = clock();
			}

			
			auto bit = bs.begin(); //遍歷(主角子彈)容器
			while (bit != bs.end())
			{
				if (rectcrashrect((*bit)->getrect(), (*it)->getrect()))//敵人碰撞到主角子彈,銷毀
				{
					(*it)->Isdie();
					delete(*bit);
					bs.erase(bit);
					mus.sound();
					kill++;
					break;
				}
				bit++;
			}
			if (!(*it)->show())//當敵人超出介面,銷毀
			{
				delete(*it);
				es.erase(it);
				it = es.begin();
			}
			it++;
		}



		for (int i = 0; i < 5 - es.size(); i++)//當敵人死亡,自動新增新敵人
		{
			addenemy(es, enemyimg, eboom);
		}

		while (clock() - skilllast >= hurttime * 50)//超級爆射 技能冷卻完畢提示
		{
			LPCTSTR skill = _T("超級爆射 技能冷卻完畢 按\"s\"施放");
			settextcolor(BLACK);

			outtextxy(swidth/2 - textwidth(skill)/2,700 , skill);
			break;
		}


		EndBatchDraw();

		if (clock() - skilltime >= hurttime * 20)//超級爆射 結束技能
		{
			frequency = 30;
		}
		

		//按建指令
		if (_kbhit())
		{
			int v = _getch();
			if (v == 115) //s鍵放技能
			{
				if (clock() - skilllast >= hurttime* 50)//超級爆射 技能冷卻
				{
					frequency = 10;
					while (true)
					{
						skill1();
						break;
					}
					skilllast = clock();
					skilltime = clock();
				}

			}

			if (v == 32)//空白鍵暫停
			{
				Sleep(500);
				while (true)
				{
					if (_kbhit())
					{
						v == _getch();
						if (v == 32)
						{
							break;
						}
						Sleep(16);
					}
				}
			}

		}
		//勝利
		if (kill >= killnum)
		{
			Sleep(200);
			uii.victory(kill);
			return true;
		}
	}

		if(kill<=killnum)
		{
			Sleep(200);
			uii.over(kill);
			return true;
		}
}

int main()
{
	system("color 70");
	initgraph(swidth, sheight, EW_NOMINIMIZE | EW_SHOWCONSOLE);  //easyx初始化
	bool is_live = true;   //當遊戲開始進行
	ui ui;
	ui.opening();
	while (is_live)
	{	
		ui.welcome();
		is_live = play();
	}
	return 0;
}
