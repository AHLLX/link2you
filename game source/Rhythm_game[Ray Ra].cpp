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
int health=0,A;//����ֵ
LARGE_INTEGER frequency;        // ticks per second
LARGE_INTEGER t1, t2;           // ticks
double elapsedTime;
//����
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
        //ǰ��
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
        {1,2,3,4},//����
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
        //���һ��note��y������Ϊ�����ж�y>-100������Ϸ��{0}�������ռ�
         {0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{1},

    };
vector<vector<int>> song_backup=song;//����һ��song���ݣ�������Ϸ���������¿�ʼ��Ϸ
vector<vector<int>> song_y(song.size(), vector<int>(song[0].size(), 0));

//����noteλ��
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
        y-=80; // �������ϸ�80���ػ�������Ļ��
    }
}
// ���Ʋ˵�
void drawmenu() {
    //menu����
    loadimage(&menu, _T("menu.png"));
    putimage(0, 0, &menu);
    // �����ı���ɫ�ͱ���ɫ
    settextcolor(WHITE);
    setbkmode(TRANSPARENT);
    // �����ı���ʽ
    settextstyle(20, 0, _T("����"));
    // ���Ʋ˵���
    outtextxy(180, 360, _T("1. ��ʼ��Ϸ"));
    outtextxy(180, 400, _T("2. �˳���Ϸ"));
    outtextxy(170, 430, _T("ʹ�����ּ�ѡ��"));
    outtextxy(45, 500, _T("��ʾ:���ΰ�D,F,J,K����������,ESC��ͣ��Ϸ"));
    outtextxy(140, 530, _T("�ǵùر����뷨���棡"));
    outtextxy(120, 630, _T("������:231304045 �޼�һ"));
    FlushBatchDraw();  // ˢ����Ļ
    // �ȴ��û�����
    while (true) {
    if (GetAsyncKeyState('1')) {
        // ������Ϸ����
        break;
    }
    if (GetAsyncKeyState('2')) {
        // �˳���Ϸ
        exit(0);
    }
}
}
// ����ui
void drawboard(){
    //����
    cleardevice();
    loadimage(&bg, _T("background.jpg"));
    // ���Ʊ���ͼƬ
    putimage(0, 0, &bg);
    // ����ʵ��
    line(150,0,150,700);
    line(450,0,450,700);
    line(150,650,450,650);
    line(150,610,450,610);
    // ����������ʽΪ����
    setlinestyle(PS_DASH);
    // ��������
    line(225,0,225,650);
    line(300,0,300,650);
    line(375,0,375,650);
    // �ָ�������ʽΪʵ��
    setlinestyle(PS_SOLID);
    //���������
    outtextxy(18, 180, _T("BGM:True Blue"));
    //���score��combo�������
    TCHAR str[100];
    wsprintf(str, _T("Score: %d"), score);
    outtextxy(18, 200, str);
    //Ѫ��
    if(A)
    {
    setfillcolor(RED); // ���������ɫΪ��ɫ
    solidrectangle(20, 250+A*6, 40, 600); // ���Ƴ�����
    health=A*6;
    A=0;
    }
    
    }
//���¼�֮���ж�note�Ƿ����ж������ڣ���������������score����
void whickkey(){
    if(GetAsyncKeyState('D')){
        // Code for D key
        setfillcolor(YELLOW);  // ���������ɫΪ��ɫ
        bar(151, 610, 224, 650);  // �ڵ�һ��λ�û���һ����ɫ�ľ���
        // ������������ŵ� Note ����
        for(int i=0;i<song.size();i++){
            for(int j=0;j<song[i].size();j++){
                if (song[i][j]==1&&song_y[i][j]>= judgementAreaTop && song_y[i][j]<= judgementAreaBottom) {
                    song[i][j]=0;
                    score+=100;   }}}
    }
    if(GetAsyncKeyState('F')){
        // Code for F key
        setfillcolor(YELLOW);  // ���������ɫΪ��ɫ
        bar(226, 610, 299, 650);  // �ڵڶ���λ�û���һ����ɫ�ľ���
        for(int i=0;i<song.size();i++){
            for(int j=0;j<song[i].size();j++){
                if (song[i][j]==2&&song_y[i][j]>= judgementAreaTop && song_y[i][j]<= judgementAreaBottom) {
                        song[i][j]=0;
                        score+=100;}}}
    }
    if(GetAsyncKeyState('J')){
        // Code for J key
        setfillcolor(YELLOW);  // ���������ɫΪ��ɫ
        bar(301, 610, 374, 650);  // �ڵ�����λ�û���һ����ɫ�ľ���
        for(int i=0;i<song.size();i++){
            for(int j=0;j<song[i].size();j++){
                if (song[i][j]==3&&song_y[i][j]>= judgementAreaTop && song_y[i][j]<= judgementAreaBottom) {
                        song[i][j]=0;
                        score+=100;}}}
    }
    if(GetAsyncKeyState('K')){
        // Code for K key
        setfillcolor(YELLOW);  // ���������ɫΪ��ɫ
        bar(376, 610, 449, 650);  // �ڵ��ĸ�λ�û���һ����ɫ�ľ���
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
    //��������
    if(!song_y.empty() && !song_y.back().empty() && song_y.back().back() > -100)
    {
        cleardevice();
        loadimage(&End, _T("end.png"));
        putimage(0, 0, &End);
        outtextxy(180, 300, _T("��Ϸ����"));
        outtextxy(170, 350, _T("��F1���¿�ʼ"));
        outtextxy(170, 400, _T("��F2�˳���Ϸ"));
        TCHAR str[100];
        wsprintf(str, _T("�������յ÷���: %d"), score);
        outtextxy(160, 200, str);
        if(score>=60000)
        {
            outtextxy(160, 450, _T("��ϲ�������S������"));
            outtextxy(140, 470, _T("����ֱ����������Ϸ����"));
        }
        else if(score>=50000&&score<58000)
        {
            outtextxy(160, 450, _T("��ϲ�������A������"));
            outtextxy(160, 470, _T("����������������ģ�"));
        }
        else if(score>=40000&&score<50000)
        {
            outtextxy(160, 450, _T("��ϲ�������B������"));
            outtextxy(160, 470, _T("���������������ԣ�"));
        }
        else if(score>=20000&&score<40000)
        {
            outtextxy(160, 450, _T("��ϲ�������C������"));
            outtextxy(160, 470, _T("���������������ԣ�"));
        }
        else
        {
            outtextxy(160, 450, _T("���ź���û�м���"));
            outtextxy(180, 470, _T("�ˣ��Ͷ�����"));
        }
        FlushBatchDraw();
        PlaySound(NULL, NULL, 0);// ֹͣ��̨����
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
    //����ֵΪ0����
    if(health>350)
    {
        cleardevice();
        loadimage(&End, _T("end.png"));
        putimage(0, 0, &End);
        outtextxy(180, 200, _T("��Ϸ����"));
        outtextxy(160, 250, _T("��F1���¿�ʼ"));
        outtextxy(145, 460, _T("���ź���û�м���"));
        outtextxy(165, 500, _T("�ˣ��Ͷ�����"));
        FlushBatchDraw();
        PlaySound(NULL, NULL, 0);// ֹͣ��̨����
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
    //����Ϸ���ݽ��г�ʼ��
    int start=0;
    score=0;
    cleardevice();
    //�Ƚ���˵�
    loadimage(&note, _T("note.png"));
    BeginBatchDraw();  // ��ʼ������ͼ
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&t1);
    while(1){
        if(start==0){
            drawmenu();//�ж��Ƿ����˵�
            start=1;
            PlaySound(_T("True Blue.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
        cleardevice();  // �����Ļ
        drawboard();// ����uium
        drawnote(y);//��ʼ��Ϸ������
        y+=2;  // ÿ��ѭ��ʹnote�����ƶ�2������
{       // ����Ƿ�����ESC����ͣ��Ϸ
        if(GetAsyncKeyState(VK_ESCAPE)) {
        // ��ͣ��Ϸ
        PlaySound(NULL, NULL, 0);// ֹͣ����
        outtextxy(20, 60, _T("F1:���¿�ʼ"));
        outtextxy(20, 90, _T("F2:���ز˵�"));
        outtextxy(20, 120, _T("F3:�˳���Ϸ"));
        FlushBatchDraw();
            while (1) {
            // ���¿�ʼ��Ϸ
            if (GetAsyncKeyState(VK_F1)) {
                y=-60;score=0;
                PlaySound(_T("True Blue.wav"), NULL, SND_FILENAME | SND_ASYNC);
                song=song_backup;
                break;
            }
            // ���ز˵�

            if (GetAsyncKeyState(VK_F2)) {
                start=0;
                goto start;
            }
            // �˳���Ϸ
            if (GetAsyncKeyState(VK_F3)) {
                return 0;
                break;
            }
            Sleep(50);
            }
        }}
        whickkey();//�жϰ���
        end();//�ж���Ϸ�Ƿ����
        FlushBatchDraw();  // ˢ��������ͼ��ͬʱ��������������ʾ����Ļ��

        // ����ˢ���ٶ�
        {QueryPerformanceCounter(&t2);
        elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        if(elapsedTime < 1000.0 / 120) {
        // ���ʱ��δ�ﵽ 1/120 �룬�ͼ����ȴ�
        while (elapsedTime < 1000.0 / 120) {
            QueryPerformanceCounter(&t2);
            elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
            }
        }
        //������һ��ʱ��
        QueryPerformanceCounter(&t1);}
    }
    EndBatchDraw();  // ����������ͼ
    closegraph();
}