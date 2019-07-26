// 贪吃蛇.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "iostream"
#include "conio.h"
#include "vector"
#include "cstdlib"
#include "Windows.h"

#define YS 25
#define XS 50
#define SPEED 1//控制速度

using namespace std;
char map[YS][XS];//地图尺寸
vector<vector<int>> snake;//蛇身

/*
随机产生食物：
(rand() % (b-a+1))+ a 随机产生在[a,b]中的数
vector<int> food{ rand()%23+1,rand() % 48 + 1 };//  y：[1,23]    和    x：[1,48]
*/

//蛇
/*
蛇的轨迹 用vector来保存每个蛇身节点的位置（x,y）
蛇头 vector[0][0]
蛇吃果子 操作之后length+1，蛇的轨迹向前移
*/

//上下左右的移动方式
/*
1。每次移动，蛇整体向前移动一次
		另外使用空间存储
		int head_X,head_Y;
		head_X=vector[0][0];
		head_Y=vector[0][1];

		//vector[0]移动到下一个位置，即通过control来得到位置信息

		for(int i=1;i<size.size();++i)//首元素单独处理
			if(i==1)
				vector[i]=[head_X,head_Y];
			vector[i]=vector[i-1];//当前元素被赋予之前元素的位置

2。实现持续移动
		如果监听键盘输入为假，则继续先前的control操作，用一个char来记录之前的control操作
*/

int S_len = 0;//蛇长，等于全图网格数le-1就是你赢
int S_speed = 1;//蛇的速度
bool flag = false;//用来表示是否碰到墙壁
int food_Y = rand() % (YS-2) + 1;
int food_X = rand() % (XS-2) + 1;//食物的刷新位置

HANDLE hOutput, hOutBuf;  //控制台屏幕缓冲区句柄
HANDLE *houtpoint;
COORD coord = { 0,0 };
DWORD bytes = 0;

//刷新蛇身
inline void FreshSnake(vector<vector<int>> &a)
{
	if (a.size() == 1);
	else
	{
		for (auto i = a.size() - 1; i > 0; --i)
			for (auto j = 0; j < 2; ++j)
				a[i][j] = a[i - 1][j];
	}
}

void control(char &a)
{
	if (a == 'a')//左
	{
		Sleep(50);
		if (snake[0][1] > 1) {
			if (map[snake[0][0]][snake[0][1] - 1] == '+')//判断下一步操作是否使蛇吃到食物
			{
				//蛇长加一
				S_len += 1;
				//将食物加到蛇尾
				snake.push_back({ food_Y,food_X });
				//食物位置再生
				food_Y = rand() % (YS - 2) + 1;
				food_X = rand() % (XS - 2) + 1;
			}
			FreshSnake(snake);
			snake[0][1] -= SPEED;//蛇速度
		}
		else
		{
			flag = true;
			return;
		}
	}
	if (a == 'd')//右
	{
		Sleep(50);
		if (snake[0][1] < XS - 2) {
			if (map[snake[0][0]][snake[0][1] + 1] == '+')//判断下一步操作是否使蛇吃到食物
			{
				//蛇长加一
				S_len += 1;
				//将食物加到蛇尾
				snake.push_back({ food_Y,food_X });
				//食物位置再生
				food_Y = rand() % (YS-2) + 1;
				food_X = rand() % (XS-2) + 1;
			}
			FreshSnake(snake);
			snake[0][1] += SPEED;
		}
		else
		{
			flag = true;
			return;
		}
	}
	if (a == 'w')//上
	{
		Sleep(50);
		if (snake[0][0] > 1) {
			if (map[snake[0][0] - 1][snake[0][1]] == '+')//判断下一步操作是否使蛇吃到食物
			{
				//蛇长加一
				S_len += 1;
				//将食物加到蛇尾
				snake.push_back({ food_Y,food_X });
				//食物再生
				food_Y = rand() % (YS-2) + 1 ;
				food_X = rand() % (XS-2) + 1 ;
			}
			FreshSnake(snake);//更新蛇身
			snake[0][0] -= SPEED;//蛇头移动
		}
		else
		{
			flag = true;
			return;
		}
	}
	if (a == 's')//下
	{
		Sleep(50);
		if (snake[0][0] < YS - 2) {
			if (map[snake[0][0] + 1][snake[0][1]] == '+')//判断下一步操作是否使蛇吃到食物
			{
				//蛇长加一
				S_len += 1;
				//将食物加到蛇尾
				snake.push_back({ food_Y,food_X });
				//食物再生
				food_Y = rand() % (YS - 2) + 1;
				food_X = rand() % (XS - 2) + 1;
			}
			FreshSnake(snake);//更新蛇身
			snake[0][0] += SPEED;//蛇头移动
		}
		else
		{
			flag = true;
			return;
		}
	}
}

void  init()//双缓冲设置
{
	//第一个缓冲
	for (auto i = 0; i < YS; ++i)
		for (auto j = 0; j < XS; ++j)
		{
			if (i == 0 || i == 24 || j == 0 || j == 49)
				map[i][j] = '#';
			else map[i][j] = ' ';
		}
	for (int i = 0; i < snake.size(); ++i)
		map[snake[i][0]][snake[i][1]] = '*';
	map[food_Y][food_X] = '+';
	for (int i = 0; i < YS; i++)
	{
		coord.Y = i;
		WriteConsoleOutputCharacterA(hOutBuf, map[i], XS, coord, &bytes);
	}
	SetConsoleActiveScreenBuffer(hOutBuf);
	Sleep(50);

	//写第二个缓冲
	for (auto i = 0; i < YS; ++i)
		for (auto j = 0; j < XS; ++j)
		{
			if (i == 0 || i == 24 || j == 0 || j == 49)
				map[i][j] = '#';
			else map[i][j] = ' ';
		}
	for (int i = 0; i < snake.size(); ++i)
		map[snake[i][0]][snake[i][1]] = '*';
	map[food_Y][food_X] = '+';
	for (int i = 0; i < YS; i++)
	{
		coord.Y = i;
		WriteConsoleOutputCharacterA(hOutput, map[i], XS, coord, &bytes);
		
	}
	SetConsoleActiveScreenBuffer(hOutput);
	Sleep(50);
}

//void map_print()
//{
//	for (auto i = 0; i < YS; ++i)
//	{
//		for (auto j = 0; j < XS; ++j)
//			cout << map[i][j];
//		cout << endl;
//	}
//}

int main()
{
	system("color F3");//设置控制台颜色，第一个背景颜色 第二个字体颜色
	SetConsoleTitle(TEXT("贪吃蛇"));
	hOutBuf = CreateConsoleScreenBuffer(
		GENERIC_WRITE,  //定义进程可以往缓冲区写数据
		FILE_SHARE_WRITE, //定义缓冲区可共享写权限
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	hOutput = CreateConsoleScreenBuffer(
		GENERIC_WRITE,  //定义进程可以往缓冲区写数据
		FILE_SHARE_WRITE, //定义缓冲区可共享写权限
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	//SMALL_RECT rc = { 0,0,YS + 10,XS + 4 };  //设置窗口大小，宽度和高度
	//SetConsoleWindowInfo(hOutput, 1, &rc);
	//SetConsoleWindowInfo(hOutBuf, 1, &rc);

	//隐藏两个缓冲区的光标
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);
	SetConsoleCursorInfo(hOutBuf, &cci);
	
	snake.push_back({ 1,1 });//载入蛇头位置
	init();
	//map_print();
	char c;
	while (true)
	{
		if (_kbhit()) //_kbhit()函数监听按键是否按下
			c = _getch();//使用_getch()函数获取键值
		else control(c);
		if (S_len == 1103) {
			printf("\n恭喜通关！");
			cout << "你的得分是:" << S_len << endl;
			return 0;
		}
		if (c == '0')
		{
			cout << "\n游戏结束！" << endl;
			cout << "你的得分是:" << S_len << endl;
			return 0;
		}
		control(c);
		if (flag) {
			cout << "\n游戏结束！" << endl;
			cout << "你的得分是:" << S_len << endl;
			return 0;
		}
		init();
		//system("cls");
		//map_print();
		Sleep(100);
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
