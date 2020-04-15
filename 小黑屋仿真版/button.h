#ifndef __BUTTON__
#define __BUTTON__

#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<windows.h>
#include<algorithm>
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

struct Button{//��ť����
    int x,y,color;//��ťλ�ú���ɫ
    const char *name;//����
    int len;//���ֵĳ���
};

void GetPos(POINT &pt){//�������������Ļ��λ��
//POINT���Դ�����
    HWND hwnd=GetForegroundWindow();
    GetCursorPos(&pt);
    ScreenToClient(hwnd,&pt);
    pt.y=pt.y/16,pt.x=pt.x/16;//����16���벻�����Լ�����ȥ������
}

void color(int a){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);}
//�޸���ɫ
//��֪��ÿ����ɫ�Ĵ����forѭ��1��256����
//��ʱû��
void gto(int x,int y)//�����ֵĹ���Ƶ�x��y��
{
    COORD pos;pos.X=y*2;pos.Y=x;
    //���뷴����
    //y*2����Ϊ������2���ַ�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

Button NewButton(int x,int y,int color,const char *name){
    Button t;
    t.x=x,t.y=y,t.name=name;
    t.color=color;
    t.len=strlen(name);
    return t;//�½���ť��������
}

bool Preserve(Button A){
    //ά��һ����ť
    //���Ҫʹ��������ñ�����ѭ���в���ִ����
    //��������ʾ��
    gto(A.x,A.y),color(0x70),printf("%s",A.name);
    POINT pt;
    GetPos(pt);
    if(pt.y==A.x&&(pt.x>=A.y&&pt.x<=A.y+A.len/2)){
        color(0x70),gto(A.x,A.y),printf("%s",A.name);
        if(KEY_DOWN(MOUSE_MOVED)){
			color(0xf0);
			return 1;//��⵽�����ť
    	}
	}
    color(0xf0); 
    return 0;//û�м�⵽
}

#endif
