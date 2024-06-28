#include<graphics.h>
#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

using namespace std;

IMAGE note,bg,menu,End;
int y=0;
int judgementAreaTop =610;
int judgementAreaBottom =650;
int score=0;
int health=0,A;//生命值
LARGE_INTEGER frequency;        // ticks per second
LARGE_INTEGER t1, t2;           // ticks
double elapsedTime;
//乐谱
vector<vector<int>> song=
    {   {1},{0},{0},{2},{0},{0},{3},{0},{0},{4},{0},{0},
        {1,2,3,4},
        {1,2},
        {2,3},
        {3,4},
        {1,2,3,4},
        {0},
        {1},{0},{0},{2},{0},{0},{3},{0},{0},{4},{0},{0},
        {1,2,3,4},
        {1,2},
        {2,3},
        {3,4},
        {1,2,3,4},
        {1},{1},{0},{2},{2},{0},{3},{3},{0},{4},{4},{0},
        {1,2,3,4},
        {1,2},
        {2,3},
        {3,4},
        {1,2,3,4},
        {0},
        {4},{0},{0},{2},{0},{0},{1},{0},{0},{3},{0},{0},
        {1,2,3,4},
        {1,2},{2,3},
        {3,4},
        {1,2,3,4},
        {1},{2},{3},{4},
        {4},{3},{2},{1},
        {1},{2},{3},{4},
        {4},{3},{2},{1},
        {1,2},{3,4},
        {3,4},{1,2},{1,2},
        {1},{2},{3},{4},
        {4},{3},{2},{1},
        {1},{0},{2},{0},{3},{0},{4},{0},
        {1,2},{3,4},{1,2},{2,3},{1,2},{2,3},
        {3,4},{1,2},
        {1},{0},{0},{2},{0},{0},{0},{3},{0},{4},{0},{0},
        {1},{0},{0},{2},{0},{0},{0},{3},{0},{4},{0},{0},{0},
        //前奏
        {1,2,3,4},
        {1,2},
        {2,3},
        {3,4},
        {1,2,3,4},
        {0},
        {1},{0},{0},{2},{0},{0},{0},{3},{0},{4},{0},{0},
        {1,2,3,4},
        {1,2},
        {2,3},
        {3,4},
        {1,2,3,4},
        {1},{2},{3},{4},
        {4},{3},{2},{1},
        {1,2},
        {2,3},
        {3,4},
        {1,2,3,4},
        {1,2},{0},{3,4},
        {1,2},{0},{3,4},
        {1,2},{0},{3,4},
        {1,2},{0},{3,4},
        {1,2},{0},{3,4},
        {0},
        {3,4},{1,2},
        {3,4},{1,2},
        {3,4},{1,2},
        {3,4},{1,2},
        {3,4},{1,2},
        {3,4},{1,2},
        {0},{0},{0},{0},
        {1},{2},{1},{2},{1},{2},{1},{2},
        {4},{3},{4},{3},{4},{3},{4},{3},
        {1},{2},{1},{2},{4},{3},{4},{3},
        {1,2},{1,2},{1,2},{1,2},{0},{0},{0},{0},
        {1,2,3,4},//副歌
        {0},{0},{4},{3},{2},{1},
        {1},{2},{3},{4},
        {4},{3},{2},{1},
        {1},{2},{3},{4},
        {4},{3},{2},{1},
        {0},{0},{0},{0},{0},{0},
        {1,2,3},
        {1,2,3},
        {1,2,4},
        {1,2,3},
        {1,2,3},
        {1,3,4},
        {1,3,4},
        {2,3,4},
        {2,3,4},
        {2,3,4},
        {1},{2},{1},{2},{1},{2},{1},{2},
        {4},{3},{4},{3},{4},{3},{4},{3},
        {1},{2},{1},{2},{4},{3},{4},{3},
        {1},{2},{1},{2},{1},{2},{1},{2},
        {4},{3},{4},{3},{4},{3},{4},{3},
        {1},{2},{4},{3},{1},{2},{4},{3},
        {1},{2},{4},{3},{1},{2},{4},{3},
        {1},{0},{0},{2},{0},{0},{0},{3},{0},{4},{0},{0},
        {1,2,3,4},
        {3,4},
        {2,3},
        {1,2},
        {1,2,3,4},
        {0},
        {1},{0},{0},{2},{0},{0},{0},{3},{0},{4},{0},{0},
        {1,2,3,4},
        {1,2},
        {2,3},
        {3,4},
        {1,2,3,4},
        {1},{0},{0},{2},{0},{0},{3},{0},{4},{0},
        {1,2,3,4},
        {3,4},
        {2,3},
        {1,2},
        {1,2,3,4},
        {0},
        {1},{0},{0},{2},{0},{0},{3},{0},{4},{0},
        {2,3},
        {1,2},
        {1,4},{2,3},
        {1,2,3,4},
        {1,2},{2,3},
        {3,4},
        {1,2,3,4},
        {1},{1,2},{1,3},{1,4},
        {1,4},{1,3},{1,2},{1},
        {1},{2},{3},{4},
        {4},{3},{2},{1},
        {1,2},{3,4},
        {3,4},{1,2},{1,2},
        {1},{2},{3},{4},
        {4},{3},{2},{1},
        {1},{0},{2},{0},{3},{0},{4},{0},
        {1,2},{3,4},{0},{0},{0},{0},{0},
        {3,4},{1,2},
        {1,2,3,4},
        {1,4},{2,3},
        {1},{0},{0},{2},{0},{0},{3},{0},{4},{0},
        {1},{0},{0},{2},{0},{0},{3},{0},{4},{0},
        {1},{2},{1},{2},{1},{2},{1},{2},
        {4},{3},{4},{3},{4},{3},{4},{3},{0},
        {1},{2},{3},{4},{1},{2},{3},{4},
        {4},{3},{2},{1},{4},{3},{2},{1},{0},
        {4},{3},{2},{1},
        {1,2},{3,4},
        {1,2},{3,4},
        {1},{2},{4},{3},{1,4},{2,3},{0},
        {1,2,3,4},
        {1,2,3,4},
        {1},{0},{2},{0},{3},{0},{4},{0},    
        {1,2},{3,4},
        {1,2},{3,4},
        {1,2},{3,4},
        {1,2},{3,4},
        {1,2},{0},{3,4},
        {3,4},{1,2},
        //最后一个note的y坐标作为结束判定y>-100结束游戏，{0}用来填充空间
         {0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{1},

    };
vector<vector<int>> song_backup=song;//复制一份song备份，用于游戏结束后重新开始游戏
vector<vector<int>> song_y(song.size(), vector<int>(song[0].size(), 0));

//画出note位置
void drawnote(int y){
    for(int i=0;i<song.size();i++){
        for(int j=0;j<song[i].size();j++){
            if(song[i][j]!=0){
               if(song[i][j]==1)
               {
                    putimage(152, y, &note);
               }
               else if (song[i][j]==2)
               {
                    putimage(228, y, &note);
               }
               else if (song[i][j]==3)
               {
                    putimage(304, y, &note);
               }
               else if (song[i][j]==4)
               {
                    putimage(380, y, &note);
               }
               song_y[i][j]=y;
            }
            
        }
        y-=80; // 依次向上隔80像素绘制在屏幕外
    }
}
// 绘制菜单
void drawmenu() {
    //menu背景
    loadimage(&menu, _T("menu.png"));
    putimage(0, 0, &menu);
    // 设置文本颜色和背景色
    settextcolor(WHITE);
    setbkmode(TRANSPARENT);
    // 设置文本样式
    settextstyle(20, 0, _T("宋体"));
    // 绘制菜单项
    outtextxy(180, 360, _T("1. 开始游戏"));
    outtextxy(180, 400, _T("2. 退出游戏"));
    outtextxy(170, 430, _T("使用数字键选择"));
    outtextxy(45, 500, _T("提示:依次按D,F,J,K键击打音符,ESC暂停游戏"));
    outtextxy(140, 530, _T("记得关闭输入法游玩！"));
    outtextxy(120, 630, _T("制作人:231304045 邹佳一"));
    FlushBatchDraw();  // 刷新屏幕
    // 等待用户输入
    while (true) {
    if (GetAsyncKeyState('1')) {
        // 进入游戏界面
        break;
    }
    if (GetAsyncKeyState('2')) {
        // 退出游戏
        exit(0);
    }
}
}
// 绘制ui
void drawboard(){
    //背景
    cleardevice();
    loadimage(&bg, _T("background.jpg"));
    // 绘制背景图片
    putimage(0, 0, &bg);
    // 绘制实线
    line(150,0,150,700);
    line(450,0,450,700);
    line(150,650,450,650);
    line(150,610,450,610);
    // 设置线条样式为虚线
    setlinestyle(PS_DASH);
    // 绘制虚线
    line(225,0,225,650);
    line(300,0,300,650);
    line(375,0,375,650);
    // 恢复线条样式为实线
    setlinestyle(PS_SOLID);
    //输出音乐名
    outtextxy(18, 180, _T("BGM:True Blue"));
    //输出score和combo数在左侧
    TCHAR str[100];
    wsprintf(str, _T("Score: %d"), score);
    outtextxy(18, 200, str);
    //血条
    if(A)
    {
    setfillcolor(RED); // 设置填充颜色为红色
    solidrectangle(20, 250+A*6, 40, 600); // 绘制长方形
    health=A*6;
    A=0;
    }
    
    }
//按下键之后判定note是否在判定区域内，是则消除，增加score分数
void whickkey(){
    if(GetAsyncKeyState('D')){
        // Code for D key
        setfillcolor(YELLOW);  // 设置填充颜色为黄色
        bar(151, 610, 224, 650);  // 在第一个位置绘制一个黄色的矩形
        // 遍历乐谱内序号的 Note 对象
        for(int i=0;i<song.size();i++){
            for(int j=0;j<song[i].size();j++){
                if (song[i][j]==1&&song_y[i][j]>= judgementAreaTop && song_y[i][j]<= judgementAreaBottom) {
                    song[i][j]=0;
                    score+=100;   }}}
    }
    if(GetAsyncKeyState('F')){
        // Code for F key
        setfillcolor(YELLOW);  // 设置填充颜色为黄色
        bar(226, 610, 299, 650);  // 在第二个位置绘制一个黄色的矩形
        for(int i=0;i<song.size();i++){
            for(int j=0;j<song[i].size();j++){
                if (song[i][j]==2&&song_y[i][j]>= judgementAreaTop && song_y[i][j]<= judgementAreaBottom) {
                        song[i][j]=0;
                        score+=100;}}}
    }
    if(GetAsyncKeyState('J')){
        // Code for J key
        setfillcolor(YELLOW);  // 设置填充颜色为黄色
        bar(301, 610, 374, 650);  // 在第三个位置绘制一个黄色的矩形
        for(int i=0;i<song.size();i++){
            for(int j=0;j<song[i].size();j++){
                if (song[i][j]==3&&song_y[i][j]>= judgementAreaTop && song_y[i][j]<= judgementAreaBottom) {
                        song[i][j]=0;
                        score+=100;}}}
    }
    if(GetAsyncKeyState('K')){
        // Code for K key
        setfillcolor(YELLOW);  // 设置填充颜色为黄色
        bar(376, 610, 449, 650);  // 在第四个位置绘制一个黄色的矩形
        for(int i=0;i<song.size();i++){
            for(int j=0;j<song[i].size();j++){
                if (song[i][j]==4&&song_y[i][j]>= judgementAreaTop && song_y[i][j]<= judgementAreaBottom) {
                        song[i][j]=0;
                        score+=100;}}}
    }
    for(int i=0;i<song.size();i++){
            for(int j=0;j<song[i].size();j++){
                if (song_y[i][j]> 60+judgementAreaBottom) {
                A++;
                song[i][j]=0;}}}
}

void end()
{
    //正常结束
    if(!song_y.empty() && !song_y.back().empty() && song_y.back().back() > -100)
    {
        cleardevice();
        loadimage(&End, _T("end.png"));
        putimage(0, 0, &End);
        outtextxy(180, 300, _T("游戏结束"));
        outtextxy(170, 350, _T("按F1重新开始"));
        outtextxy(170, 400, _T("按F2退出游戏"));
        TCHAR str[100];
        wsprintf(str, _T("您的最终得分是: %d"), score);
        outtextxy(160, 200, str);
        if(score>=60000)
        {
            outtextxy(160, 450, _T("恭喜您获得了S级评价"));
            outtextxy(140, 470, _T("您简直就是音乐游戏大神！"));
        }
        else if(score>=50000&&score<58000)
        {
            outtextxy(160, 450, _T("恭喜您获得了A级评价"));
            outtextxy(160, 470, _T("您就是天生干这个的！"));
        }
        else if(score>=40000&&score<50000)
        {
            outtextxy(160, 450, _T("恭喜您获得了B级评价"));
            outtextxy(160, 470, _T("还不错！加油再试试！"));
        }
        else if(score>=20000&&score<40000)
        {
            outtextxy(160, 450, _T("恭喜您获得了C级评价"));
            outtextxy(160, 470, _T("还不错！加油再试试！"));
        }
        else
        {
            outtextxy(160, 450, _T("很遗憾您没有及格"));
            outtextxy(180, 470, _T("菜，就多练！"));
        }
        FlushBatchDraw();
        PlaySound(NULL, NULL, 0);// 停止后台播放
        while (1) {
            if (GetAsyncKeyState(VK_F1)) {
                y=-60;score=0;
                PlaySound(_T("True Blue.wav"), NULL, SND_FILENAME | SND_ASYNC);
                song=song_backup;
                break;
            }
            if (GetAsyncKeyState(VK_F2)) {
                return;
            }
            Sleep(50);
        }
    }
    //生命值为0结束
    if(health>350)
    {
        cleardevice();
        loadimage(&End, _T("end.png"));
        putimage(0, 0, &End);
        outtextxy(180, 200, _T("游戏结束"));
        outtextxy(160, 250, _T("按F1重新开始"));
        outtextxy(145, 460, _T("很遗憾您没有及格"));
        outtextxy(165, 500, _T("菜，就多练！"));
        FlushBatchDraw();
        PlaySound(NULL, NULL, 0);// 停止后台播放
        while (1) {
            if (GetAsyncKeyState(VK_F1)) {
                y=-60;score=0;health=0;A=0;
                PlaySound(_T("True Blue.wav"), NULL, SND_FILENAME | SND_ASYNC);
                song=song_backup;
                break;
            }
            
            Sleep(50);
        }
    }
}

int main(){
    initgraph(500,700);
    start:
    //对游戏数据进行初始化
    int start=0;
    score=0;
    cleardevice();
    //先进入菜单
    loadimage(&note, _T("note.png"));
    BeginBatchDraw();  // 开始批量绘图
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&t1);
    while(1){
        if(start==0){
            drawmenu();//判断是否进入菜单
            start=1;
            PlaySound(_T("True Blue.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
        cleardevice();  // 清除屏幕
        drawboard();// 绘制uium
        drawnote(y);//开始游戏后画谱面
        y+=2;  // 每次循环使note向下移动2个像素
{       // 检测是否按下了ESC键暂停游戏
        if(GetAsyncKeyState(VK_ESCAPE)) {
        // 暂停游戏
        PlaySound(NULL, NULL, 0);// 停止播放
        outtextxy(20, 60, _T("F1:重新开始"));
        outtextxy(20, 90, _T("F2:返回菜单"));
        outtextxy(20, 120, _T("F3:退出游戏"));
        FlushBatchDraw();
            while (1) {
            // 重新开始游戏
            if (GetAsyncKeyState(VK_F1)) {
                y=-60;score=0;
                PlaySound(_T("True Blue.wav"), NULL, SND_FILENAME | SND_ASYNC);
                song=song_backup;
                break;
            }
            // 返回菜单

            if (GetAsyncKeyState(VK_F2)) {
                start=0;
                goto start;
            }
            // 退出游戏
            if (GetAsyncKeyState(VK_F3)) {
                return 0;
                break;
            }
            Sleep(50);
            }
        }}
        whickkey();//判断按键
        end();//判断游戏是否结束
        FlushBatchDraw();  // 刷新批量绘图，同时将缓冲区内容显示到屏幕上

        // 控制刷新速度
        {QueryPerformanceCounter(&t2);
        elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        if(elapsedTime < 1000.0 / 120) {
        // 如果时间未达到 1/120 秒，就继续等待
        while (elapsedTime < 1000.0 / 120) {
            QueryPerformanceCounter(&t2);
            elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
            }
        }
        //计算下一轮时间
        QueryPerformanceCounter(&t1);}
    }
    EndBatchDraw();  // 结束批量绘图
    closegraph();
}