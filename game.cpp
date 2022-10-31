#include "main.h"

//������
class music
{
public:
	 
//�D������
void bgm1()
		{
			mciSendString(L"close ./music/victory.mp3", 0, 0, 0);
			mciSendString(L"close ./music/defeat.mp3", 0, 0, 0);
			mciSendString(L"open ./music/starbgm.mp3", 0, 0, 0);
			mciSendString(L"play ./music/starbgm.mp3 repeat", 0, 0, 0);
		}

//�԰�����
void bgm2()
		{
			mciSendString(L"close ./music/starbgm.mp3", 0, 0, 0);
			mciSendString(L"open ./music/battlebgm.mp3", 0, 0, 0);
			mciSendString(L"play ./music/battlebgm.mp3 repeat", 0, 0, 0);
		}

//�Աѭ���
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

//�ӧQ����
void bgm4()
		{
			mciSendString(L"close ./music/battlebgm.mp3", 0, 0, 0);
			mciSendString(L"open ./music/victory.mp3", 0, 0, 0);
			mciSendString(L"play ./music/victory.mp3 repeat", 0, 0, 0);
		}

//�Աѻy��
void hurtsound()
		{
			mciSendString(L"close ./music/hero_hurt.mp3", 0, 0, 0);
			mciSendString(L"open ./music/hero_hurt.mp3", 0, 0, 0);
			mciSendString(L"play ./music/hero_hurt.mp3", 0, 0, 0);//Sleep(1200);

		}

};

//������
class ui
{
public:
	//�}�l����
void welcome()
	{		
		loadimage(&startimg, L"./img/start.jpg", 600, 1200);
		RECT tplayr, texitr, taboutr, tintroducer; //���s

		while (true)
		{
			BeginBatchDraw();
			setbkcolor(WHITE);
			cleardevice();
			putimage(0, 0, &startimg);
			settextstyle(80, 0, _T("����"), 0, 0, 600, 0, 0, 0);

			settextcolor(BLACK);
			setbkmode(TRANSPARENT);

			outtextxy(swidth / 2 - textwidth(title) / 2, sheight / 8, title);//�奻��m

			//�]�w���s��m
			settextstyle(60, 0, _T("����"));
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
				if (pointinrect(mess.x, mess.y, tplayr))//�}�l�C��
				{
					return;
				}
				else if (pointinrect(mess.x, mess.y, texitr))//�h�X�C��
				{
					exit(0);
				}
				else if (pointinrect(mess.x, mess.y, taboutr))//�h�X�C��
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

//�ӧQ����
void victory(unsigned long long& kill)
{
	IMAGE victoryimg;
	loadimage(&victoryimg, L"./img/victory.jpg", 900, 1200);

	setbkcolor(WHITE);
	cleardevice();

	putimage(-150, 0, &victoryimg);

	settextcolor(BLACK);
	settextstyle(100, 0, _T("����"));
	outtextxy(100, 100, L"���ȧ���");
	settextstyle(30, 0, _T("����"));
	settextstyle(30, 0, _T("����"));
	setbkmode(OPAQUE);
	outtextxy(180, 600, L"��Enterc��^�D�ɭ�");
	setbkmode(TRANSPARENT);
	TCHAR* str = new TCHAR[128];
	_stprintf_s(str, 128, _T("������:% llu"), kill);
	settextcolor(RED);
	settextstyle(60, 0, _T("����"));
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
//��������
void over(unsigned long long& kill)
{
	IMAGE endimg;
	loadimage(&endimg, L"./img/end.jpg", 600, 1100);
	putimage(0, 0, &endimg);

	TCHAR* str = new TCHAR[128];
	_stprintf_s(str, 128, _T("������:% llu"), kill);
	settextcolor(RED);
	outtextxy(swidth / 2 - textwidth(str) / 2, sheight / 5, str);

	//���^������^
	//LPCTSTR info = _T("��Enterc��^");
	settextstyle(30, 0, _T("����"));
	setbkmode(OPAQUE);
	outtextxy(180, 300, L"��Enterc��^�D�ɭ�");
	setbkmode(TRANSPARENT);
	settextstyle(100, 0, _T("����"));
	outtextxy(100, 100, L"���ȥ���");
	
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

void about()
{
	IMAGE aboutimg;
	loadimage(&aboutimg, L"./img/about.jpg", 600, 1200);
	putimage(0, -100, &aboutimg);

	settextstyle(100, 0, _T("����"));
	outtextxy(swidth / 3, 50, L"����");
	settextstyle(30, 0, _T("����"));
	outtextxy(swidth / 2.3, 200, L"�Ϸ�");
	outtextxy(swidth / 10, 250, L"@itaco_G  @parang9494  @haejooncho");
	outtextxy(swidth / 3.5, 300, L" P:15317640    P:7054606");
	outtextxy(swidth / 2.3, 350, L"����");
	outtextxy(swidth / 4, 400, L"[Blue Archive] Theme_23 ");
	outtextxy(swidth / 4, 450, L"[Blue Archive]Theme_27 ");
	outtextxy(swidth / 4, 500, L"[fanmade]�K�Q��68Party!! ");
	outtextxy(0, 550, L"[Blue Archive]Unwelcome School_Piano Jazz Ver.");
	outtextxy(swidth / 3, 600, L"�s�@:���F�E");
	setbkmode(OPAQUE);
	outtextxy(180, 700, L"��Enterc��^�D�ɭ�");
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

void introduce()
{
	IMAGE introduceimg;
	loadimage(&introduceimg, L"./img/cg.jpg", 800, 1067);

	putimage(-100, 0, &introduceimg);
	settextstyle(100, 0, _T("����"));
	outtextxy(swidth / 3, 50, L"����");
	settextstyle(30, 0, _T("����"));

	outtextxy(swidth / 4.5, 200, L"�����e�ӷm�Ȧ檺�o��");
	outtextxy(swidth / 4.5, 250, L"�ؼЬO�O����60�H�N�⦨�\");
	outtextxy(swidth / 4.5, 300, L"���O�Ъ`�N,�A�u��3���R");
	outtextxy(swidth / 4.5, 350, L"�Q����,����o�ǳ��|��֥ͩR��");
	outtextxy(swidth / 4.5, 400, L"�ϥηƹ�����D��");
	outtextxy(swidth / 4.5, 450, L"�Ů���Ȱ�");
	setbkmode(OPAQUE);
	outtextxy(180, 600, L"��Enterc��^�D�ɭ�");
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

private:
		LPCTSTR title = _T("�Ȧ�O�þ�");
		LPCTSTR tplay = _T("�}�l�C��");
		LPCTSTR texit = _T("�h�X�C��");
		LPCTSTR tabout = _T("����");
		LPCTSTR tintroduce = _T("����");
		IMAGE startimg;
};

//�귽�� 
class BK //�I��
{
public:
	//��l��
	BK(IMAGE& img)
	:img(img), y(-sheight)
	{
	}
	//�I���ϦV�U��
	void show()
	{
		if (y == 0) { y = -sheight; }
		y += 4; //�Ϥ��U�Ƴt��
		putimage(0, y, &img);

	}

private:
	IMAGE& img;
	int y;
};
class hero
{
public:
	hero(IMAGE& img)
		:img(img), hp(xhp)
	{
	}

	void show()
	{
		setlinecolor(RED);//��q
		setlinestyle(PS_SOLID, 10);//��q�ʲ�
		line(rect.left, rect.top - 2, rect.left + (img.getwidth() / xhp * hp), rect.top - 2);

		putimage(rect.left, rect.top, &img); //�N�D����m�b���Ц�m
	}

	void control()//�ϥι��б���D��
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

	bool hurt()//�������
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
	bool show() //���ĤH����
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
			return false;//���}�e����P��
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
		rect.top -= 15; //�l�u�t��
		rect.bottom -= 15;
		putimage(rect.left, rect.top, &img);

		return true;
	}

	RECT& getrect() { return rect; }
protected:
	IMAGE& img;
	RECT rect;
};
class ebullet : public bullet
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
		rect.top += 5; //�l�u�t��
		rect.bottom += 5;
		putimage(rect.left, rect.top, &img);

		return true;
	}


};

//�ͦ��ĤH
bool addenemy(vector<enemy*>& es, IMAGE& enemyimg, IMAGE* boom)
{
	enemy* e = new enemy(enemyimg, abs(rand()) % (swidth - enemyimg.getwidth()), boom);//��{�ĤH�H���ͦ�
	for (auto& i : es)
	{
		if (rectcrashrect(i->getrect(), e->getrect()))//�P�_�O�_���|
		{
			delete e;
			return false;
		}
	}
	es.push_back(e);
	return true;
}

//�C������
bool play()
{
	ui uii;
	setbkcolor(WHITE);
	cleardevice();
	bool is_play = true;
	IMAGE heroimg, enemyimg, bkimg, bulletimg, bulletimg2; //���J�Ϥ�: �D�� �ĤH �I���� �l�u 
	IMAGE eboom[3]; //�z���ĪG

	loadimage(&heroimg, L"./img/hero.png", 70, 85);
	loadimage(&enemyimg, L"./img/em1.png");
	loadimage(&bkimg, L"./img/bk2.png", swidth, sheight * 2); //�榡��
	loadimage(&bulletimg, L"./img/bullet1.png");
	loadimage(&bulletimg2, L"./img/bullet2.png");
	loadimage(&eboom[0], L"./img/boom1.png");
	loadimage(&eboom[1], L"./img/boom2.png");
	loadimage(&eboom[2], L"./img/boom3.png");

	unsigned long long  kill = 0;
	

	BK bk = BK(bkimg);
	hero hp = hero(heroimg);
	vector<enemy*> es;//�ĤH
	vector<bullet*> bs;//�D���l�u
	vector<ebullet*>ebs;//�ĤH�l�u
	int bsing = 0;//�l�u�W�v

	clock_t hurtlast = clock();//�L�ĴV

	music mus;
	mus.bgm2();

	for (int i = 0; i < 5; i++) //�}���ͦ��ĤH
	{
		addenemy(es, enemyimg, eboom);
	}
	
	while (is_play)
	{
		if (kill == 60)
		{
			break;
		}
			
		bsing++;

		if (bsing % 30 == 0)//�D���l�u�W�v
		{
			bs.push_back(new bullet(bulletimg, hp.getrect()));//�ͦ��s���l�u
		}

		
		if (bsing == 120)//�ĤH�l�u�W�v
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

		//���ťհ��Ȱ�
		if (_kbhit())
		{
			char v = _getch();
			if (v == 0x20)
			{
				Sleep(500);
				while (true)
				{
					if (_kbhit())
					{
						v == _getch();
						if (v == 0x20)
						{
							break;
						}
						Sleep(16);
					}
				}
			}
		}

		hp.show();

		auto bsit = bs.begin();//�D���l�u
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

		auto ebsit = ebs.begin();//��l�ƼĤH�l�u
		while (ebsit != ebs.end())
		{
			if (!(*ebsit)->show())//��ĤH�l�u�W�X����,�P��
			{
				ebsit = ebs.erase(ebsit);
			}
			else
			{
				if (rectcrashrect((*ebsit)->getrect(), hp.getrect()))//�I���ĤH�l�u,�����a�ͩR
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
		_stprintf_s(str, 128, _T("������:% llu /60"), kill);
		settextcolor(RED);
		settextstyle(30, 0, _T("����"));
		outtextxy(0, 0, str);

		auto it = es.begin();//�w�q(�ĤH)�e������l��m
		while (it != es.end())
		{
			if (rectcrashrect((*it)->getrect(), hp.getrect()))//�I����ĤH,�����a�ͩR
			{
				if (clock() - hurtlast >= hurttime)
				{
					is_play = hp.hurt();
				}
				hurtlast = clock();
			}
			
			
			auto bit = bs.begin(); ////�w�q(�D���l�u)�e������l��m
			while (bit != bs.end())
			{
				if (rectcrashrect((*bit)->getrect(), (*it)->getrect()))//�ĤH�I����D���l�u,�P��
				{
					(*it)->Isdie();
					delete(*bit);
					bs.erase(bit);

					kill++;
					break;
				}
				bit++;
			}

			if (!(*it)->show())//��ĤH�W�X����,�P��
			{
				delete(*it);
				es.erase(it);
				it = es.begin();
			}
			it++;
		}

		for (int i = 0; i < 5 - es.size(); i++)//��ĤH���`,�۰ʷs�W�s�ĤH
		{
			addenemy(es, enemyimg, eboom);
		}
		EndBatchDraw();
	}

	//�ӧQ����
	if (kill >= 60)
	{
		uii.victory(kill);
	}
	else
	{
		uii.over(kill);
	}
	return true;
}

int main()
{
	ui uii;
	
	initgraph(swidth, sheight, EW_NOMINIMIZE | EW_SHOWCONSOLE);  //easyx��l��
	bool is_live = true;   //��C���}�l�i��

	ui ui;
	while (is_live)
	{
		ui.welcome();
		is_live = play();
	}

	return 0;
}
