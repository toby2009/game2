#include<cstdio>
#include<cstring>
#include<algorithm>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;
#define MAXN 35
#define MIDX 10
#define MIDY 40
#define CG 25
#define CK 80
int G,K,Lnum,Wnum;//GΪ��ͼ�ߣ�KΪ��ͼ��LnumΪ��ͼ�е�������WnumΪʣ���С����
int nx,ny;//���ڹ�����ڵ�λ��
bool QR=0,Lose=0,is_flag_true[MAXN][MAXN];//QRΪȷ��ģʽ�Ƿ�򿪣�LoseΪ�Ƿ��䣬�����������λ���ϵ����Ƿ�Ŷ�
char map[MAXN][MAXN],tmap[MAXN][MAXN];//��һ����ֻ���׺Ϳյصĵ�ͼ���ڶ���������ܿ����ĵ�ͼ
int map1[MAXN][MAXN],mapc[MAXN][MAXN];//map1Ϊ���ֵĵ�ͼ������0����յأ�-1Ϊ�ף�1-8Ϊ��Χ�׵ĸ���
//mapcΪ��ǰ���ӵ���ɫ
int col[10]={240,249,242,252,241,244,243,240,248};//col[i]��ʾwindowsɨ����i����ɫ,col[0]Ϊ�ո����ɫ
int d[10][4]={{0},{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};//8������
bool ZB;//�����Ƿ��

/*���ֺ���*/

void color(int);//��ɫ
void gto(int,int);//���λ��
void make();//���������ͼ
void print();//��ӡ��ͼ��
bool check(int,int);//�ж������Ƿ�Ϸ�
bool is_win();//�ж��Ƿ�Ӯ
bool is_lose();//�Ƿ���
void dfs(int,int);//���������򿪷���
void st(int,int);//��̽����windowsɨ���е����Ҽ�ͬʱ��
void flag(int,int);//С��
void bj(int,int);//���
void swt();//ȷ��ģʽ
void again();//���¿�ʼ
void zb();//����ģʽ
void mainmain();//������
void print_real_map();//��ӡ���յĵ�ͼ
void begin();//���ֲ���
int main()
{
mainmain();
}
void color(int a){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);}
void gto(int x,int y)
{
COORD pos;pos.X=y;pos.Y=x;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void make()
{
for(int i=1;i<=G;i++)
for(int j=1;j<=K;j++)
map[i][j]='#';//��ʼ��
for(int i=1;i<=Lnum;i++)
{
int x=rand()%G+1,y=rand()%K+1;
while(map[x][y]=='O')
x=rand()%G+1,y=rand()%K+1;
map[x][y]='O';

}//�������

for(int i=1;i<=G;i++)
for(int j=1;j<=K;j++)
{
if(map[i][j]=='O')map1[i][j]=-1,mapc[i][j]=240;//�������
else
{
for(int k=1;k<=8;k++)
if(map[i+d[k][0]][j+d[k][1]]=='O')
map1[i][j]++;//������Χ�׵ĸ���
mapc[i][j]=col[map1[i][j]];//���ݸ����ϵ���������ɫ
}
}
for(int i=1;i<=G;i++)
for(int j=1;j<=K;j++)
if(mapc[i][j]==0)//�յ�
mapc[i][j]=240;
}
void print()
{
system("cls");
gto(0,MIDY-4); color(233); printf("ɨ��");
color(240);
gto(1,MIDY);
for(int i=2;i<=G+1;i++)
{
gto(i,0);
for(int j=1;j<=K;j++)
printf("#"),tmap[i-1][j]='#';//��ʼ������������ĵ�ͼ
}
gto(2,0);
nx=2,ny=0;
color(15);
printf("@");
color(15);
gto(2,2*K+5);printf("-----����-----");
gto(3,2*K+5);printf("wasd��ѡ��λ��");
gto(4,2*K+5);printf("�ո񣺴�");
gto(5,2*K+5);printf("1������̽��Χ8�����飬������������򲻻�򿪣���");
gto(6,2*K+5);printf(" �׻����ı������Ὣ��Χ���׵�λ�ô򿪣�");
gto(7,2*K+5);printf(" �����̽ʱ��Χ�б������ģ������Ϸʧ��");
gto(8,2*K+5);printf(" �������ȷ��һ�Σ��Ա�鿴��Χ����̽������");
gto(9,2*K+5);printf("2��������/ȡ��С�죨F��");
gto(10,2*K+5);printf("3��������/ȡ����ǣ�����");
gto(11,2*K+5);printf("4������/�ر�ȷ��ģʽ����ÿ�β������ٰ�һ��ȷ��");
gto(12,2*K+5);printf("5������/�ر�����ģʽ������ʾԭ����ͼ");
gto(13,2*K+5);printf("0�������¿�ʼ");//��ӡ����
gto(G+4,0);printf("-----������ʾ-----\n");
printf("��ѡ�񷽿���в���");
gto(1,2*K+10);color(12);printf("ʣ��С������%d",Wnum=Lnum);
}
bool check(int x,int y){return y>=0&&y<K&&x>=2&&x<G+2;}
//��Ϊ��ͼ�Ǵ�2��0�п�ʼ��ģ�����ͼ�Ǵ�1��1�п�ʼ��ģ�����gto(x,y)�ߵ�����map[x-1][y+1]
bool is_win()
{
int cnt=0;
for(int i=1;i<=G;i++)
for(int j=1;j<=K;j++)
if(map[i][j]=='#'&&map1[i][j]==-1)
cnt++;
if(cnt==Lnum) return 1;
//����û���򿪵ķ��鶼����=>ʤ��
for(int i=1;i<=G;i++)
for(int j=1;j<=K;j++)
if((tmap[i][j]!='F'&&map1[i][j]==-1)||(tmap[i][j]=='F'&&map1[i][j]!=-1))
return 0;
return 1;
//�����׶�������
}
bool is_lose(){return Lose;}
void dfs(int x,int y)
{
if(map1[x-1][y+1]>0)//ֻҪ�߽�ȫ�������־�return
{
gto(x,y),color(mapc[x-1][y+1]),printf("%d",map1[x-1][y+1]);
tmap[x-1][y+1]=map1[x-1][y+1]+'0';
return;
}
gto(x,y);color(255);
tmap[x-1][y+1]=' ';
printf(" ");//��Ϊ�����ж����ף������ж������֣������һ���ǿյ�
for(int i=1;i<=8;i++)
{
int xx=x+d[i][0]-1,yy=y+d[i][1]+1;//�����xx��yy����map�еģ�������gto�е�
if(check(xx+1,yy-1)&&tmap[xx][yy]=='#'&&map1[xx][yy]!=-1)//����check��dfs�Ĳ���Ҫ�仯
dfs(xx+1,yy-1);
}
}
void st(int x,int y)
{
for(int i=1;i<=8;i++)
{
int xx=x+d[i][0],yy=y+d[i][1];
if(check(xx,yy))
{
gto(xx,yy);
if(tmap[xx-1][yy+1]!='#')
color(mapc[xx-1][yy+1]-128);//��ȥ128ʹ��Χ��8�����ӵı�����ɫ��Ϊ��ɫ
else
color(112);//��������һ��'#'��Ӧ�ÿ��Բ���
printf("%c",tmap[xx-1][yy+1]);
}
}
gto(G+5,0),color(15),printf("��ȷ�� ");
//��̽�������ȷ��һ�Σ���������˵
char c=getch();
if(c=='1')
{
for(int i=1;i<=8;i++)
{
int xx=x+d[i][0],yy=y+d[i][1];
if(check(xx,yy))
if(tmap[xx-1][yy+1]=='F'&&map1[xx-1][yy+1]!=-1)//��̽ʱ�и��ӵ�С������=>ʧ��
{
Lose=1;
return;
}
}
for(int i=1;i<=8;i++)
{
int xx=x+d[i][0],yy=y+d[i][1];
if(check(xx,yy))
if(map1[xx-1][yy+1]==-1&&tmap[xx-1][yy+1]!='F')//��̽���и���Ϊ��=>ȡ����
return;
}
for(int i=1;i<=8;i++)
{
int xx=x+d[i][0],yy=y+d[i][1];
if(check(xx,yy)&&tmap[xx-1][yy+1]=='#')//����Χ8������
dfs(xx,yy);
}
}
}
void flag(int x,int y)
{
x-=1,y+=1;
if(tmap[x][y]=='F')//ԭ��ΪС��=>ȡ��С��
{
tmap[x][y]='#';mapc[x][y]=240;
gto(x+1,y-1),color(240),printf("#");
Wnum++;//����С����
}
else//����ͷ���С��
{
is_flag_true[x][y]=map1[x][y]==-1;//�ж�С���Ƿ�Ŷ�
tmap[x][y]='F';mapc[x][y]=253;
gto(x+1,y-1),color(253),printf("F");
Wnum--;//����С����
}
gto(1,2*K+10);color(12);printf("ʣ��С������ ");
gto(1,2*K+22);printf("%d",Wnum);//����С����
}
void bj(int x,int y)//�ͷ�С���ֻ࣬�ǲ��ø���is_flag_true
{
x-=1,y+=1;
if(tmap[x][y]=='?')
{
gto(x+1,y-1),color(240),printf("#");
tmap[x][y]='#';mapc[x][y]=240;
}
else
{
if(tmap[x][y]=='F')//���ԭ�����λ������С�죬���������Ϊ�˱�ǣ���Ҫ����С����
{
Wnum++;
gto(1,2*K+10);color(12);printf("ʣ��С������ ");
gto(1,2*K+22);printf("%d",Wnum);
}
gto(x+1,y-1),color(240),printf("?");
tmap[x][y]='?';mapc[x][y]=240;
}
}
void swt(){QR=!QR;}
void zb()
{
if(ZB)//����������״��˾Ͱ����׵�ͼ���
{
for(int i=1;i<=G;i++)
{
gto(i+1,K+2);
for(int j=1;j<=K;j++)
color(15),printf(" ");
}
ZB=0;
}
else//�����ӡ���׵�ͼ
{
for(int i=1;i<=G;i++)
{
gto(i+1,K+2);
for(int j=1;j<=K;j++)
{
color(mapc[i][j]);
if(map1[i][j]==-1) printf("O");
else if(map1[i][j]>0) printf("%d",map1[i][j]);
else printf(" ");
}
}
ZB=1;
}
}
void again()
{
G=K=Lnum=nx=ny=Lose=ZB=0;
QR=0;
memset(is_flag_true,0,sizeof(is_flag_true));
memset(map,0,sizeof(map));
memset(tmap,0,sizeof(tmap));
memset(map1,0,sizeof(map1));
memset(mapc,0,sizeof(mapc));
color(15);
system("cls");//��ʼ��
mainmain();
}
void begin()//���ֲ���
{
char c=getch(); 
gto(G+5,0),color(15),printf("��ѡ�񷽿���в���");
color(240);
if(c=='w'&&check(nx-1,ny))
{
gto(nx,ny);
if(tmap[nx-1][ny+1]!='#'||tmap[nx-1][ny+1]==' ')
color(mapc[nx-1][ny+1]);
printf("%c",tmap[nx-1][ny+1]);
gto(nx-=1,ny);color(15);printf("@");
}
else if(c=='s'&&check(nx+1,ny))
{
gto(nx,ny);if(tmap[nx-1][ny+1]!='#'||tmap[nx-1][ny+1]==' ')color(mapc[nx-1][ny+1]);printf("%c",tmap[nx-1][ny+1]);
gto(nx+=1,ny);color(15);printf("@");
}
else if(c=='a'&&check(nx,ny-1))
{
gto(nx,ny);if(tmap[nx-1][ny+1]!='#'||tmap[nx-1][ny+1]==' ')color(mapc[nx-1][ny+1]);printf("%c",tmap[nx-1][ny+1]);
gto(nx,ny-=1);color(15);printf("@");
}
else if(c=='d'&&check(nx,ny+1))
{
gto(nx,ny);if(tmap[nx-1][ny+1]!='#'||tmap[nx-1][ny+1]==' ')color(mapc[nx-1][ny+1]);printf("%c",tmap[nx-1][ny+1]);
gto(nx,ny+=1);color(15);printf("@");
}
//���������ƶ�
else
{
if(c==' '&&(!(tmap[nx-1][ny+1]<='9'&&tmap[nx-1][ny+1]>='0'))&&tmap[nx-1][ny+1]!='F')
{
mapc[nx-1][ny+1]=col[map1[nx-1][ny+1]];//����������˱�ǣ�mapc[nx-1][ny+1]����ɫΪ��ɫ,�ڴ�ʱ�������ɫȴ��һ���Ǻ�ɫ
if(QR)
{
gto(G+5,0),color(15),printf("��ȷ�� ");
if(getch()==' ')
{
if(map1[nx-1][ny+1]==-1) {Lose=1;return;}
dfs(nx,ny);
}
}
else
{
if(map1[nx-1][ny+1]==-1) {Lose=1;return;}
dfs(nx,ny);
}
}
else if(c=='1')
{
if(QR)
{
gto(G+5,0),color(15),printf("��ȷ�� ");
if(getch()=='1') st(nx,ny);
}
else st(nx,ny);
for(int i=1;i<=8;i++)
{
int xx=nx+d[i][0],yy=ny+d[i][1];
if(check(xx,yy))
{
gto(xx,yy);
if(tmap[xx-1][yy+1]!='#') color(mapc[xx-1][yy+1]);
else color(240);
printf("%c",tmap[xx-1][yy+1]);
}
}
}
else if(c=='2'&&(tmap[nx-1][ny+1]>'9'||tmap[nx-1][ny+1]<'1'))
{
if(QR)
{
gto(G+5,0),color(15),printf("��ȷ�� ");
if(getch()=='2') flag(nx,ny);
}
else flag(nx,ny);
}
else if(c=='3'&&(tmap[nx-1][ny+1]>'9'||tmap[nx-1][ny+1]<'1'))
{
if(QR)
{
gto(G+5,0),color(15),printf("��ȷ�� ");
if(getch()=='3') bj(nx,ny);
}
else bj(nx,ny);
}
else if(c=='4')
{
if(QR)
{
gto(G+5,0),color(15),printf("��ȷ�� ");
if(getch()=='4') swt();
}
else swt();
}
else if(c=='5')
{
if(QR)
{
gto(G+5,0),color(15),printf("��ȷ�� ");
if(getch()=='5') zb();
}
else zb();
}
else if(c=='0')
{
if(QR)
{
gto(G+5,0),color(15),printf("��ȷ�� ");
if(getch()=='0') again();
}
else again();
}
}
}
void mainmain()
{
system("mode con cols=120 lines=35");//���ô��ڴ�С
srand((unsigned)time(NULL));
int mode;
printf("1.����\n2.�м�\n3.�߼�\n4.�Զ���\n");
scanf("%d",&mode);if(mode>4) mode=4;
if(mode==1) G=9,K=9,Lnum=10;
else if(mode==2) G=16,K=16,Lnum=40;
else if(mode==3) G=16,K=30,Lnum=99;//���ֵȼ��Ĳ���
else
{
printf("�����������߶ȣ�");scanf("%d",&G);
printf("������������ȣ�");scanf("%d",&K);
printf("�������׸��������鲻�����ܴ�С������֮һ����");scanf("%d",&Lnum);
if(G>24) G=24;if(K>30) K=30;
if(G<9) G=9;if(K<9) K=9;
if(Lnum<10) Lnum=10;if(Lnum>G*K*9/10) Lnum=G*K*9/10;
//���Ʋ����ķ�Χ,���һ��if���׵�������������ͼ��С��9/10
}
make();
print();
while(1)
{
begin();
bool f1=is_win(),f2=is_lose();
if(f1||f2)
{
gto(0,0);
if(f1)
color(202),gto(0,0),printf("�� Ӯ �ˣ����Ƿ�������(y/n)");
if(f2)
color(137),gto(0,0),printf("�� �� �ˣ����Ƿ�������(y/n)");//��Ӯ
print_real_map();
char c=getch();
if(c=='y'||c=='Y') again();
else
{
color(15);
system("cls");
gto(MIDX,MIDY-5);
printf("��ӭ�´�����");
return;
}
}
}
}
void print_real_map()
{
color(240);
for(int i=1;i<=G;i++)
{
gto(i+1,0);
for(int j=1;j<=K;j++)
{
if(tmap[i][j]=='F'&&is_flag_true[i][j]==0)//�����������ʾ��ɫ��X
color(252),printf("X");
else if(map1[i][j]==-1)//��Ϊ��ɫO
color(240),printf("O");
else if(map1[i][j]==0)//��
color(240),printf(" ");
else//����
color(mapc[i][j]),printf("%d",map1[i][j]);
}
}
}
