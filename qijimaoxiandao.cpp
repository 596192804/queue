#include<stdio.h>
#include<windows.h>
#pragma comment(lib, "winmm.lib")
#include<stdlib.h>
#include<time.h>
#include"resource.h"
#include<mmsystem.h> 
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#define PI 3.1415926535898
#include<math.h>
IMAGE beijing;
//***********************************************************************
//                             函数声明
//***********************************************************************
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();
void test11();
void test12();
void test13();
void finish();
//***********************************************************************
//                             文字变色
//***********************************************************************
void color()
{
	Sleep(500);
	system("color 01");
	Sleep(500);
	system("color 02");
	Sleep(500);
	system("color 03");
	Sleep(500);
	system("color 04");
	Sleep(500);
	system("color 0E");
	Sleep(500);
}
void colourRed()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);

}

//***********************************************************************
//                           进度条系列
//***********************************************************************

void Gotoxy(int x, int y)//光标定位
{
	HANDLE hout;	//定义句柄变量hout
	COORD coord;	//定义结构体coord
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);		//获得标准输出（屏幕）句柄
	SetConsoleCursorPosition(hout, coord);		//移动光标
}

void HideCursor()//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};	//后边的0代表光标不可见
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


void progress()
{
	int len;
	HideCursor();
	printf("╔══════════════════════════════════════════════════╗\n");
	
	printf("║                                                  ║\n");

	printf("╚══════════════════════════════════════════════════╝\n");
	for(len=1;len<=25;len++)
	{
		Gotoxy(2*len, 6);
		printf("█");
		Gotoxy(7, 10);
		printf("已完成%d%%", 4 * len);
		Sleep(100);
		HideCursor();
	}
}
void baojian()
{
	initgraph(640, 480);
	IMAGE baojian,texiao;
	loadimage(&baojian, _T("baojian.jpg"), 640, 480);  // 没有读到数据，以后还是把图片放在项目文件夹中吧
	putimage(0, 0, &baojian);
	Sleep(1000);
	loadimage(&texiao, _T("texiao.jpg"), 640, 480);
	putimage(0, 0, &texiao);
	Sleep(500);
	setbkcolor(BLACK);	                       // 用背景色清空屏幕
	cleardevice();
	settextcolor(WHITE);
	settextstyle(32, 0, _T("宋体"));
	outtextxy(0, 10, _T("大保健闪瞎了你的狗眼，你被引路人杀死。"));
	Sleep(1000);
}

void fazhang()
{
	initgraph(640, 480);
	IMAGE baojian, texiao;
	loadimage(&baojian, _T("fazhang.jpg"), 640, 480);  // 没有读到数据，以后还是把图片放在项目文件夹中吧
	putimage(0, 0, &baojian);
	Sleep(1000);
	loadimage(&texiao, _T("texiao2.jpg"), 640, 480);
	putimage(0, 0, &texiao);
	Sleep(500);
	setbkcolor(BLACK);	                       // 用背景色清空屏幕
	cleardevice();
	settextcolor(WHITE);
	settextstyle(32, 0, _T("宋体"));
	outtextxy(0, 10, _T("法杖发出一道神秘的光，将你吞噬。"));
	Sleep(1000);
}
void test1()
{
	initgraph(640, 480);
	IMAGE beijing,boy,boy2,guide,guide2;
	loadimage(&beijing, _T("beijing.jpg"),640,480);  // 没有读到数据，以后还是把图片放在项目文件夹中吧
	loadimage(&boy, _T("boy.jpg"),160,200);
	loadimage(&boy2,_T("boy2.jpg"), 160, 200);
	loadimage(&guide, _T("guide.jpg"), 220, 250);
	loadimage(&guide2, _T("guide2.jpg"), 220, 250);
	putimage(0, 0, &beijing);
	int pt0_x = 0, pt1_x = 320,i=0;
	 BeginBatchDraw();
	while (pt0_x + i < pt1_x) //移动图片
	{
		putimage(400, 200, &guide2, NOTSRCERASE);
		putimage(400, 200, &guide, SRCINVERT);
		putimage(pt0_x + i, 250, &boy2, NOTSRCERASE);
		putimage(pt0_x + i, 250, &boy, SRCINVERT);
		i += 40;
		FlushBatchDraw();
		Sleep(300);
		cleardevice();
		putimage(0, 0, &beijing);
	}
	EndBatchDraw();
	closegraph();
	system("color 0E");
	system("cls");
	printf("引路人：亲爱的勇士，很不幸运来到奇迹冒险岛，这是充满危险，但又充满奇遇，记住一点：不要相信这里的每一个人。\n只要你一颗勇敢的心和聪明的头脑，你就一定能成功找到岛里的宝藏!\n现在呢这有两件装备让你挑选，请给出你的选择\n");
	int m=0;
	
	while(m!=3)
	{
		colourRed();
		printf("1.闪瞎钛金狗眼的大保健\n");
		printf("2.带着神秘气息的法杖\n");
        printf("3.不要意思，我不需要。\n");
        scanf_s("%d",&m);
	
		switch(m)
		{
		case 3:test2();break;
		case 1:system("cls"); baojian(); finish(); break;
			 
        case 2:system("cls"); fazhang(); finish(); break;
		default:printf("别乱来0.0，再给你一次机会\n");
		}
	}
}

void test2()
{
	initgraph(640, 480);
	IMAGE beijing, boy, boy2;
	loadimage(&beijing, _T("anbian.jpg"), 640, 480);  
	loadimage(&boy, _T("boy.jpg"), 160, 200);
	loadimage(&boy2, _T("boy2.jpg"), 160, 200);
	putimage(0, 0, &beijing);
	int pt0_x = 0, pt1_x = 320, i = 0;
	BeginBatchDraw();
	while (pt0_x + i < pt1_x) //移动图片
	{
		putimage(pt0_x + i, 280, &boy2, NOTSRCERASE);
		putimage(pt0_x + i, 280, &boy, SRCINVERT);
		i += 40;
		FlushBatchDraw();
		Sleep(300);
		cleardevice();
		putimage(0, 0, &beijing);
	}
	EndBatchDraw();
	closegraph();
	system("color 0E");
	system("cls");
	puts("你告别引路人。说你还有事，必须先走了。\n引路人惋惜的叹了一口气，走开了。\n你继续走着。\n你刚巧路过一个鱼很多的地方。你走到岸边蹲下身子。\n你准备下水摸鱼了！摸了好久好久，你才抓到了一条大鱼。\n没有火，你准备钻木取火。又是过了好久，你吃着自己烤出来的大鱼。\n心里又放心又满足。\n冒险了一天，天黑了下来，你要找一个地方安居。\n树影在这时候就像鬼影，走了几圈也没见到一个合适的地方。\n就在这时，远方不远处闪烁着微光\n你向前走，发现是月光在水上的投影\n你看着眼前两个地方，不知道该睡在哪。\n一个是树丛里，温暖而且还有树遮阴。\n一个是紧靠水边的岸上，容易扎营");
	int m = 0;
	while(m!=1)
	{
		colourRed();
		puts("1.树丛");
		puts("2.岸上");
		scanf_s("%d",&m);
	
		switch(m)
		{
		case 1:printf("恭喜你，喂孤魂野鬼去吧\n"); Sleep(1000); finish();
		case 2:test3();break;
			default:printf("别乱来0.0，再给你一次机会\n");
		}
	}
}

void test3()
{
	system("color 0E");
	system("cls");
	puts("在你睡了几个小时后，还是半夜。\n你突然听到一些声音，从睡梦中惊醒过来。\n你仔细追寻声音的源，不久后你看到前方有两个人在交谈，似乎是昨天的引路人跟一个少女\n你决定");
	int m = 0;
	while(m!=2)
	{
		colourRed();
		printf("1：躲进树后继续听他们说话\n");
		printf("2：赶紧跑\n");
		scanf_s("%d",&m);
	
		switch(m)
		{
		case 1:test9();break;
		case 2:printf("你站起身来马不停蹄的跑。\n你头也不回，最后被一块石头绊倒\n掉进一个黑洞，然后莫名其妙的死了\n"); Sleep(3000); finish();
		default:printf("别乱来0.0，再给你一次机会\n");
		}
	}
}

void test4()
{
	initgraph(640, 480);
	IMAGE beijing2, boy, boy2,girl,girl2;
	loadimage(&beijing2, _T("beijing2.jpg"), 640, 480);  // 没有读到数据，以后还是把图片放在项目文件夹中吧
	loadimage(&boy, _T("boy.jpg"), 160, 200);
	loadimage(&boy2, _T("boy2.jpg"), 160, 200);
	loadimage(&girl, _T("girl.jpg"), 200, 250);
	loadimage(&girl2, _T("girl2.jpg"), 200, 250);
	putimage(0, 0, &beijing2);
	int pt0_x = 0, pt1_x = 320, i = 0;
	BeginBatchDraw();
	while (pt0_x + i < pt1_x) //移动图片
	{
		putimage(380, 240, &girl2, NOTSRCERASE);
		putimage(380, 240, &girl, SRCINVERT);
		putimage(pt0_x + i, 280, &boy2, NOTSRCERASE);
		putimage(pt0_x + i, 280, &boy, SRCINVERT);
		i += 40;
		FlushBatchDraw();
		Sleep(300);
		cleardevice();
		putimage(0, 0, &beijing2);	
	}
	EndBatchDraw();
	closegraph();
	system("color 0E");
	system("cls");
	printf("你断然跟着少女走，不久后她似乎意识到有人在跟踪她，她回过头来，一眼就发现了你\n哇，好精致的五官，你忍不住的赞叹道，身材妖娆，皮肤白皙，就是白的有点过分了\n你走过去，跟她招呼并为追踪她感到抱歉，然后似乎意识到她或许听不懂自己的话，你开始，手舞足蹈\n忽然，她扑哧一笑，我知道你在说什么啦！\n你十分吃惊，那刚刚你们说的是什么话\n那是我们种族的语言，刚刚那个是我的父亲啦\n我看你似乎是外来人，要不要进我家坐坐呢\n");
	int m = 0;
	while (m != 1)
	{
		colourRed();
		m = 0;
		printf("1.要\n");
		printf("2.不要,你要回到岸边的家，然后想办法逃离这个古怪的岛屿\n");
		scanf_s("%d", &m);

		switch (m)
		{
		case 1:test10(); break;
		case 2:test5(); break;
		default:printf("别乱来0.0，再给你一次机会\n");
		}
	}
}
	void test5()
	{
		initgraph(640, 480);
		IMAGE beijing, boy, boy2;
		loadimage(&beijing, _T("gui.jpg"), 640, 480);
		loadimage(&boy, _T("boy.jpg"), 160, 200);
		loadimage(&boy2, _T("boy2.jpg"), 160, 200);
		putimage(0, 0, &beijing);
		int pt0_x = 0, pt1_x = 100, i = 0;
		BeginBatchDraw();
		while (pt0_x + i < pt1_x) //移动图片
		{
			putimage(pt0_x + i, 180, &boy2, NOTSRCERASE);
			putimage(pt0_x + i, 180, &boy, SRCINVERT);
			i += 40;
			FlushBatchDraw();
			Sleep(300);
			cleardevice();
			putimage(0, 0, &beijing);
		}
		EndBatchDraw();
		closegraph();
		system("color 0E");
		system("cls");
		puts("你开始走路回家，天慢慢地变黑了\n深夜，你思考着怎么才能抓紧回到家中。\n就在此时，一个孤魂野鬼朝你飘来~~~\n你猛地一回头，被吓得差点晕倒。你爬起来没命的跑。\n可那只鬼怎么也甩不掉。\n你赶紧打开你身上背着的背包。\n里面有几样东西。\n指南针、枪（没子弹）、小刀、蜡烛、打火机。\n你思来想去，能用的也就几个。");
		PlaySound(MAKEINTRESOURCE(IDR_WAVE2), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
		int m = 0;
		while (m != 1 || 3)
		{
			colourRed();
			printf("1.蜡烛\n");
			printf("2.打火机\n");
			puts("3.小刀（鬼能透过去吧。）\n");
			scanf_s("%d", &m);
			while (getchar() != '\n');
			switch (m)
			{
			case 1:printf("你傻不拉几的拿一蜡烛……\n你被吃了，恭喜你。"); Sleep(3000); finish();
			case 2:test6(); break;
			case 3:printf("你傻不拉几的拿小刀去刺。\n穿了……你被吃了，祝贺你！"); Sleep(3000); finish();
			default:printf("别乱来0.0，再给你一次机会\n");
			}
		}
	}

void test6()
{
	initgraph(640, 480);
	IMAGE beijing, boy, boy2;
	loadimage(&beijing, _T("chuan.jpg"), 640, 480);
	loadimage(&boy, _T("boy.jpg"), 160, 200);
	loadimage(&boy2, _T("boy2.jpg"), 160, 200);
	putimage(0, 0, &beijing);
	int pt0_x = 0, pt1_x = 100, i = 0;
	BeginBatchDraw();
	while (pt0_x + i < pt1_x) //移动图片
	{
		putimage(pt0_x + i, 120, &boy2, NOTSRCERASE);
		putimage(pt0_x + i, 120, &boy, SRCINVERT);
		i += 40;
		FlushBatchDraw();
		Sleep(300);
		cleardevice();
		putimage(0, 0, &beijing);
	}
	EndBatchDraw();
	closegraph();
	system("color 0E");
	system("cls");
	puts("你拿起打火机，生起了火。鬼显然不知道这是个毛玩意~\n伸手去碰，结果化成了灰烬。\n虚惊一场，你拍了拍自己的胸脯，期待着天亮。\n天终于亮了，你先是吃了一条鱼，然后开始准备逃离这个危险的岛屿。\n可是由于你这几天从没睡好过，已经没多少精力了。\n你看到面前有一艘现成的小船，但是好几个地方打了补丁。\n你看到补丁打得还算牢固。你有看到水面上漂着一个很粗的木棍。\n也许你可以抓着木棍离开。可是你觉得那样太费力了。\n你想去坐船。可你不知道那船是不是别人故意来坑你的。");
	int m=0;
	while(m!=1)
	{
		colourRed();
        puts("1.坐船\n");
		puts("2.抓着木棍\n");
		scanf_s("%d",&m);
		
		switch(m)
		{
		case 1:printf("你坐上了小船，可惜，那些补丁居然漏了！你最终被淹死了。\n"); Sleep(3000); finish();
		case 2:test7();break;
		default:printf("别乱来0.0，再给你一次机会\n");
		}
	}
}

void test7()
{
	system("color 0E");
	system("cls");
	puts("你犹豫不决的抱住木棍，跳进了水里。\n想着对这个小岛这么快就走了，你居然还想再刺激点。\n老天成全了你- -。你一个抓不稳，丢去了木棍。\n你瞎扑腾，终于扑腾到了岸上。结果你又回到了冒险岛！\n你急的都快跪到了地上，心里默念：老天啊，我开玩笑的！我不要刺激了！我要回家！\n你急的哭了出来，这个时候，你被一棵树上的字条给吸引了。\n你慢慢走了过去，读出上面的字：\n你别想逃脱这里，这里是逃不出去的！\n但我也很有原则，看到树后面的路标了么！它将指引你离开。\n如果你能选择对的话。\n哈哈哈哈【奸笑】\n你看了看路标，一个指左，一个指右。\n\n左边和右边几乎没什么差距，只是左边一棵树上有血做的标记，右边却没有。");
	int m=0;
	while(m!=2)
	{
		colourRed();
		printf("1.左\n");
		printf("2.右\n");
		scanf_s("%d",&m);
		
		switch(m)
		{
		case 1:test8();break;
		case 2:puts("不知道大家有没有这种感觉？就是看着都会怕！话说我就这样啊。\n你走向了没有血迹的那一条路，很可惜，你被藏在树后面的鬼吃掉了。"); Sleep(3000); finish();
		default:printf("别乱来0.0，再给你一次机会\n");
		}
	}
}

void test8()
{
	system("color 0E");
	system("cls");
	printf("你战战兢兢地走向有血迹的那条路，希望能看到好的一面。\n渐渐地，你来到一个不认识的地方。（这岛还真尼玛大！）\n这里没有人，没有树，没有水。你渐渐意识到你离开了那座小岛。\n你很感谢当初你做的选择，你离开了，虽然没有找到宝藏，但你成功活了下来\n");
	Sleep(5000);
	printf("You are the Winner");
	Sleep(1000);
	initgraph(640, 480);
	IMAGE img;
	loadimage(&img, _T("victory.jpg"), 640, 480);
	putimage(0, 0, &img);
	Sleep(2000);
	exit(0);
}


void test9()
{
	system("color 0E");
	system("cls");
	printf("你躲在草丛里细听，原来他们似乎在为一些事情发生争执\n而他们说着一些奇怪的语言，你并不知道他们在吵什么\n突然，那名少女愤然而去。引路人也走向了另外一个方向\n你决定\n");
	int m=0;
	while(m!=3)
	{
		colourRed();
		printf("1.跟着少女走\n");
		printf("2.跟着引路人走\n");
        printf("3.赶紧离开，不惹事生非\n");
        scanf_s("%d",&m);
	
		switch(m)
		{
		case 3:printf("你站起身来赶紧离开，你头也不回，最后被一块石头绊倒掉进一个黑洞，然后莫名其妙的死了\n"); Sleep(3000); finish();
		case 1:test4();break;
        case 2:test12();break;
		default:printf("别乱来0.0，再给你一次机会");
		}
	}
}
void test10()
{
	initgraph(640, 480);
	IMAGE beijing2, boy, boy2, girl, girl2;
	loadimage(&beijing2, _T("chengbao.jpg"), 640, 480);  // 没有读到数据，以后还是把图片放在项目文件夹中吧
	loadimage(&boy, _T("boy.jpg"), 160, 200);
	loadimage(&boy2, _T("boy2.jpg"), 160, 200);
	loadimage(&girl, _T("girl.jpg"), 150, 200);
	loadimage(&girl2, _T("girl2.jpg"), 150, 200);
	putimage(0, 0, &beijing2);
	int pt0_x = 0, pt1_x = 320, i = 0;
	BeginBatchDraw();
	while (pt0_x + i < pt1_x) //移动图片
	{
		putimage(380, 240, &girl2, NOTSRCERASE);
		putimage(380, 240, &girl, SRCINVERT);
		putimage(pt0_x + i, 280, &boy2, NOTSRCERASE);
		putimage(pt0_x + i, 280, &boy, SRCINVERT);
		i += 40;
		FlushBatchDraw();
		Sleep(300);
		cleardevice();
		putimage(0, 0, &beijing2);
	}
	EndBatchDraw();
	closegraph();
	system("color 0E");
	system("cls");
	printf("你跟着少女走到家中，房子很大，里面却没有人，有一种阴森森的感觉\n少女热情地招待了你，她的举手投足间带着优雅的气息，妩媚的眼神也让你欲罢不能，酒过三巡后，你内心有股火,少女也双颊微醺，无时无刻都在挑拨着你\n");
	int m=0;
	while(m!=3)
	{
		colourRed();
		printf("1.去厕所里解决\n");
		printf("2.不怂，直接上\n");
        printf("3.此女十分危险，赶紧离开，不惹事生非\n");
        scanf_s("%d",&m);
	
		switch(m)
		{
		case 3:test5();finish();
		case 2:printf("你跟少女大干了一场，你觉得十分快活，并没有注意到少女露出的险恶的表情，最后你被少女吸干了，暴毙而亡\n"); Sleep(3000); finish();
        case 1:test11();break;
		default:printf("别乱来0.0，再给你一次机会\n");
		}
	}
}
void test11()
{
	system("color 0E");
	system("cls");
	printf("你在厕所解决了生理需求，累得有些困了\n");
	int m=0;
	while(m!=2)
	{
		colourRed();
		printf("1.在少女家里过夜\n");
		printf("2.离开少女家\n");
		scanf_s("%d",&m);
		
		switch(m)
		{
		case 1:printf("少女在你睡着的时候吸干了你，你暴毙而亡\n"); Sleep(3000); finish();
		case 2:printf("你离开少女家，发现了引路人，你悄悄地跟上了他\n"); Sleep(3000); test12();
		default:printf("别乱来0.0，再给你一次机会\n");
		}
	}
}
void test12()
{
	initgraph(640, 480);
	IMAGE beijing2, boy, boy2, girl, girl2;
	loadimage(&beijing2, _T("dongxue.jpg"), 640, 480);  // 没有读到数据，以后还是把图片放在项目文件夹中吧
	loadimage(&boy, _T("boy.jpg"), 160, 200);
	loadimage(&boy2, _T("boy2.jpg"), 160, 200);
	loadimage(&girl, _T("guide.jpg"), 150, 200);
	loadimage(&girl2, _T("guide2.jpg"), 150, 200);
	putimage(0, 0, &beijing2);
	int pt0_x = 0, pt1_x = 150, i = 0;
	BeginBatchDraw();
	while (pt0_x + i < pt1_x) //移动图片
	{
		putimage(220, 100, &girl2, NOTSRCERASE);
		putimage(220, 100, &girl, SRCINVERT);
		putimage(pt0_x + i, 280, &boy2, NOTSRCERASE);
		putimage(pt0_x + i, 280, &boy, SRCINVERT);
		i += 40;
		FlushBatchDraw();
		Sleep(300);
		cleardevice();
		putimage(0, 0, &beijing2);
	}
	EndBatchDraw();
	closegraph();
	system("color 0E");
	system("cls");
	printf("你跟着引路人，不知不觉来到了一个洞穴入口，里面黑漆漆\n你跟着走了进去，洞穴里很潮湿，随着深入，你越能感受到一股奇异的波动\n到最后，引路人停了下来，来到一个地方，嘴里在默念着什么，像是要开启一个阵法，你注意到靠近你的墙壁一侧有个放着东西的凹槽\n");
	int m=0;
	while(m!=2)
	{
		colourRed();
		printf("1.取出凹槽里的东西\n");
		printf("2.静观其变\n");
		scanf_s("%d",&m);
		
		switch(m)
		{
		case 1:test13();break;
		case 2:printf("你成为了阵法血祭的牺牲品\n") ; Sleep(3000); finish();
		default:printf("别乱来0.0，再给你一次机会\n");
		}
	}
}
void test13()
{
	system("color 0E");
	system("cls");
	printf("你发现了一个说明书，哦，原来这是一个藏着宝藏的洞穴，要打开宝藏的封印就需要血祭\n你赶紧掏出背包里的小刀，捅死了引路人，并按说明树上的口诀血祭了引路人，拿到了宝藏\n");
	printf("You are the Winner");
	Sleep(5000);
	initgraph(640, 480);
	IMAGE img;
	loadimage(&img, _T("victory.jpg"), 640, 480);
	putimage(0, 0, &img);
	Sleep(2000);
	exit(0);
}
void finish()
{
	initgraph(640, 480);
	IMAGE img;
	loadimage(&img, _T("gameover.jpg"), 640, 480);
	putimage(0, 0, &img);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);//添加音乐
	Sleep(1500);
	setbkcolor(BLACK);	                       // 用背景色清空屏幕
	cleardevice();
	settextcolor(BLUE);
	settextstyle(30, 0, _T("宋体"));
	outtextxy(0, 10, _T("如果你想重新开始，请输入y"));
	outtextxy(0, 50, _T("如果你想退出，请输入任意键"));
	Sleep(1000);
	getchar();
	if (getchar() == 'y') 
	{
		PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
		test1();
	}
	else exit(0);
}

int main()
{
    system("mode con cols=55 lines=30");
	printf("*******************************************************\n");
	printf("                欢迎来到奇迹冒险岛!\n");
	printf("*******************************************************\n");
	color();          //文字变色
	Sleep(500);
	printf("             如果准备好了就按下你的回车吧！    \n");
	system("pause");
	progress();//进度条
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
	Sleep(500);
	test1();
	return 0;
}