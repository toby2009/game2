#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<ctime> 
#include"button.h"

//function defined
inline void village();
inline void fireroom();
inline void mmct();
inline void pth(short,short,int,char[]); 
//end


using namespace std;


char a[20][20],b[20][20];
char x;

clock_t start,sum;

Button FR,WR,MF;
Button TREE,NEST;
Button trip;

Button save=NewButton(31,1,0xf0,"����");
Button github=NewButton(31,4,0xf,"Github");

Button trap;
Button car;
Button house; 
Button hotel;
Button VL;

//arms 
struct menu{
	int num;
	int hurt;
	int tempo;
	float miss; 
};
menu bonegun={0,3,2};//��ǹ 
menu irronsword={0,6,4};//����
menu steelsword={0,9,6};//�ֽ�
menu bayonet={0,5,8};//�̵�
menu gun={0,5,5};//ǹ 
menu lasergun={0,20,24};//���ⲽǹ 
int lasso;//����
int ball;//�ӵ�
int energypack;//����Ԫ��
//end

struct smell{
    short x;
    short y;
}f;
struct flag{
	int fireroom;
	int village;
	int compass;
}fl;
struct data{
	int house;
	int farmer;
	int hunter;
	int toller;
	int cooker;
	int irronrobot;
	int irronplus;
	int Srobot;
	int Mrobot;
	int Gunworker;
	int leatherwalker;
}dt;

struct resource{
	
	int steel; //�� 
	int sulfur; //��� 
	int coal;//ú 
	int irron;//�� 
	int trap;
	int wood;//ľͷ 
	int meat;//�� 
	int tooth;//���� 
	int scale;//��Ƭ 
	int fur;//ëƤ 
	int car;//����
	int toll;//�ն�
	int rice;//Ѭ��
	int cloth;//�� 
	int leather;//Ƥ�� 
}rc;
inline void armsinput(){
	freopen("data.log","r",stdin);
	scanf("%d%d%d%d%d%d%d%d",&bonegun.num,&irronsword.num,&steelsword.num,&gun.num,&lasergun.num,&ball,&energypack,&lasso);
	fclose(stdin);
}
inline void armsoutput(){
	freopen("data.log","w",stdout);
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",bonegun.num,irronsword.num,steelsword.num,gun.num,lasergun.num,ball,energypack,lasso);
	fclose(stdout);
}
inline void dataoutput(){
	freopen("data.log","w",stdout);
	printf("%d\n%d\n%d\n%d\n",dt.farmer,dt.house,dt.hunter,dt.toller);
	fclose(stdout);
}
inline void datainput(){
	freopen("data.log","r",stdin);
	scanf("%d%d%d%d",&dt.farmer,&dt.house,&dt.hunter,&dt.toller);
	fclose(stdin);
}
inline void flagoutput(){
	freopen("flag.log","w",stdout);
	printf("%d\n%d\n%d\n",fl.compass,fl.fireroom,fl.village);
	fclose(stdout);
}
inline void flaginput(){
	freopen("flag.log","r",stdin);
	scanf("%d%d%d",&fl.compass,&fl.fireroom,&fl.village);
	fclose(stdin);
}
inline void MSGPrint(const char Message[]){
	gto(22,0);
	printf("                                               ");
	gto(22,0);
	printf("%s",Message);
}
inline void resourceinput(){
	freopen("resource.log","r",stdin);
	scanf("%d%d%d%d%d%d%d%d%d%d",&rc.wood,&rc.meat,&rc.tooth,&rc.scale,&rc.fur,&rc.car,&rc.toll,&rc.rice,&rc.cloth,&rc.trap);
	fclose(stdin);
} 
inline void resourceoutput(){
	freopen("resource.log","w",stdout); 
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",rc.wood,rc.meat,rc.tooth,rc.scale,rc.fur,rc.car,rc.toll,rc.rice,rc.cloth,rc.trap);
	fclose(stdout);
}
inline void save_a(){
	MessageBox(0,"�ѱ���","��Ϣ",MB_OK);
	flagoutput();
	resourceoutput();
	dataoutput();
	armsoutput();
}
inline void village(){ 
	system("cls");
	system("title ����ɭ��");
	FR = NewButton(1,1,0xf,"�����");
	//trip = NewButton(1,19,0xf,"�������"); 
	Preserve(FR);
	Preserve(trip);
	Preserve(github);
	Preserve(save);
	if(!dt.house){
		system("title ����ɭ��");
		gto(22,0);
		printf("                                                   ");
		gto(22,0);
		printf("���Ǹ����ʵ�ҹ��������ع��š�");
		VL = NewButton(1,10,0xf,"����ɭ��");
	}
	if(dt.house==1)
		system("title �¶�С��"),VL = NewButton(1,10,0xf,"�¶�С��");
	if(dt.house>1)
		system("title С�ʹ���"),VL = NewButton(1,10,0xf,"С�ʹ���");
	if(dt.house>10)
		system("title ���ʹ���"),VL = NewButton(1,10,0xf,"���ʹ���");
	if(dt.house>30)
		system("title ���ʹ���"),VL = NewButton(1,10,0xf,"���ʹ���");
	if(dt.house>60)
		system("title ����С��"),VL = NewButton(1,10,0xf,"����С��");
	
	gto(20,0);
	printf("��Ϣ\n----------------------");
	gto(24,0);
	printf("��Ʒ\n----------------------");
	gto(29,0);
	printf("ѡ��\n----------------------");
	MF = NewButton(3,1,0xf,"��ľ");
//	NEST = NewButton(3,1,0xf,"�鿴����"); 
	Preserve(VL);
	while(1){
		pth(26,0,rc.wood,"ľͷ");pth(26,10,rc.cloth,"����");pth(26,20,rc.fur,"ëƤ");pth(26,30,rc.tooth,"����");
		sum=clock();
		if((sum-start)%50==0){
			rc.wood+=dt.farmer*2;
			rc.fur+=dt.hunter*5;
			rc.meat+=dt.hunter*5;
			if(rc.meat-dt.toller*10>=0){
				rc.meat-=dt.toller*10;
				rc.toll+=dt.toller;
			}
			if(rc.meat-dt.cooker>=0 && rc.wood-dt.cooker*5>=0){
				rc.meat-=dt.cooker;
				rc.wood-=dt.cooker*10;
				rc.rice+=dt.cooker;
			}
			if(rc.rice-dt.irronrobot*5>=0){
				rc.rice-=dt.irronrobot*5;
				rc.irron+=dt.irronrobot;
			}
			if(rc.fur-dt.leatherwalker*5>=0){
				rc.fur-=dt.leatherwalker*5;
				rc.leather+=dt.leatherwalker;
			}
		} 
		if(rand()%10 == 4 && dt.farmer+dt.hunter+dt.toller<dt.house*4){
			if(dt.house*4-(dt.farmer+dt.hunter+dt.toller)==1) MSGPrint("İ������ҹ��ִ�"),dt.farmer++;
			else if(dt.house*4-(dt.farmer+dt.hunter+dt.toller)<5) MSGPrint("һ��������˪���˼�ס����һ��С��"),dt.farmer+=4;
			else if(dt.house*4-(dt.farmer+dt.hunter+dt.toller)<12) MSGPrint("һȺ�ݹ���᾵��˵ִ���"),dt.farmer+=10;
			else MSGPrint("�������ˣ����ų�࣬ͬʱҲ����ϣ��"),dt.farmer+=12;
		}
		if(Preserve(trip)) mmct(),village(); 
		if(Preserve(FR)) fireroom();
		if(Preserve(MF)){
			rc.wood+=(1+rc.car)*5;
			gto(22,0);
			printf("                                                   ");
			gto(22,0);
			printf("�ֵ���ɢ���ſ�֦��Ҷ"); 
			Sleep(100);
		}
		if(Preserve(github)) system("start github.html");
		if(Preserve(save)) {
			save_a();
		}
	}
}
inline void yd(){
    x=_getch();
    switch(x)
    {
        case 'w':
            if(f.x>0)
                f.x--;
            break;
        case 'a':
            if(f.y>0)
                f.y--;
            break;
        case 's':
            if(f.x<8)
                f.x++;
            break;
        case 'd':
            if(f.y<8)
                f.y++;
            break;
    }    
}
inline void mmct(){
	MessageBox(0,"���ģʽ��������̽Ѱ��ׯ�������ڴ˹�������������������֪��Χ��ͬʱ���㲻��������\n��������Ҳͬ�����������κι�������ض��ص��ĳЩ�¼���\n��ô����ʿ�������ɣ�ʹ��w,a,s,d����������ƶ���","�������",MB_OK); 
	system("cls");
	system("title ��������"); 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD defaul = 0xf6;
	WORD build  = 0xf0;
	WORD build_empty  = 0xf8;
	WORD grass  = 0xfa;
	WORD desert = 0xf6;
	WORD forest = 0xfb;
	WORD walker = 0xf1;
    f.x=4;
    f.y=4;
    bool flag=false;
    while(1)
    {
        b[f.x+1][f.y]=1;
        b[f.x-1][f.y]=1;
        b[f.x][f.y+1]=1;
        b[f.x][f.y-1]=1;
        system("cls");
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(i==f.x && j==f.y){
                	SetConsoleTextAttribute(hOut, walker);
                	putchar('@');
				}
                else if(b[i][j]==1){
                	if(a[i][j]!='.' && a[i][j]!=';' && a[i][j]!=',') SetConsoleTextAttribute(hOut, build);
                	else if(a[i][j]==',') SetConsoleTextAttribute(hOut, grass);
                	else if(a[i][j]==';') SetConsoleTextAttribute(hOut, forest);
                	else if(a[i][j]=='.') SetConsoleTextAttribute(hOut, desert);
					else SetConsoleTextAttribute(hOut, defaul);
                	putchar(a[i][j]);
				}
                else putchar(' ');
                putchar(' ');
            }
            putchar('\n');
        }
        yd();
        b[f.x++][f.y]=1;
        b[f.x--][f.y]=1;
        b[f.x][f.y++]=1;
        b[f.x][f.y--]=1;
        flag=true;
        if(a[f.x][f.y]=='A' && flag==true)
        {
            system("cls");
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    if(i==f.x && j==f.y) putchar('@');
                    else if(b[i][j]==1) putchar(a[i][j]);
                    else putchar(' ');
                    putchar(' ');
                }
                putchar('\n');
            }
            return;
        }
    }
}
inline void pth(short x,short y,int th,char thname[]){
	gto(x,y);
	color(0x70);
	if(th){
		printf("         ");
		gto(x,y);
		printf("%s%d",thname,th);
	}
	color(0xf0);
}
inline void pthnum(short x,short y,int th,char thname[]){
	gto(x,y);
	color(0xf0);
	if(th){
		printf("  ");
		gto(x,y);
		printf("%s%d",thname,th);
	}
	color(0xf0);
}
inline void fireroom(){
	
	start=clock();
	srand((unsigned)time(0));
	
	color(0xf0); 
	system("cls");
	gto(20,0);
	printf("��Ϣ\n----------------------");
	gto(24,0);
	printf("��Ʒ\n----------------------");
	gto(29,0);
	printf("ѡ��\n----------------------"); 
	
	pth(26,0,rc.wood,"ľͷ");pth(26,10,rc.cloth,"����");pth(26,20,rc.fur,"ëƤ");pth(26,30,rc.tooth,"����"); 
	MF = NewButton(3,1,0xf,"   ����   ");
	if(!fl.fireroom){
		system("title С����") ;
		FR = NewButton(1,1,0xf,"С����");
		Preserve(FR);
		rc.wood = 7;
		gto(22,0);
		printf("���Ϩ���ˣ�С���ݺ���̹�\n");
	}
	else{
		system("title �����");
		FR = NewButton(1,1,0xf,"�����");
		MF = NewButton(3,1,0xf," ������� "); 
		Preserve(VL); 
		Preserve(FR);
		Preserve(trap);
		Preserve(car);
		Preserve(house);
		Preserve(hotel);
		Preserve(trip); 
		if(rc.car) car = NewButton(5,1,0xf,"��ӵ�л���");  
	}
	while(1){
		sum=clock();
		if((sum-start)%100==0){
			rc.wood+=dt.farmer*2;
			rc.fur+=dt.hunter*5;
			rc.meat+=dt.hunter*5;
			if(rc.meat-dt.toller*10>=0){
				rc.meat-=dt.toller*10;
				rc.toll+=dt.toller;
			}
			if(rc.meat-dt.cooker>=0 && rc.wood-dt.cooker*5>=0){
				rc.meat-=dt.cooker;
				rc.wood-=dt.cooker*10;
				rc.rice+=dt.cooker;
			}
			if(rc.rice-dt.irronrobot*5>=0){
				rc.rice-=dt.irronrobot*5;
				rc.irron+=dt.irronrobot;
			}
			if(rc.fur-dt.leatherwalker*5>=0){
				rc.fur-=dt.leatherwalker*5;
				rc.leather+=dt.leatherwalker;
			}
		}
		if(rand()%10 == 4 && dt.farmer+dt.hunter+dt.toller<dt.house*4){
			if(dt.house*4-(dt.farmer+dt.hunter+dt.toller)==1) MSGPrint("İ������ҹ��ִ�"),dt.farmer++;
			else if(dt.house*4-(dt.farmer+dt.hunter+dt.toller)<5) MSGPrint("һ��������˪���˼�ס����һ��С��"),dt.farmer+=4;
			else if(dt.house*4-(dt.farmer+dt.hunter+dt.toller)<12) MSGPrint("һȺ�ݹ���᾵��˵ִ���"),dt.farmer+=10;
			else MSGPrint("�������ˣ����ų�࣬ͬʱҲ����ϣ��"),dt.farmer+=12;
		}
		if(rand()%50 == 4 && rc.wood>=9900){
			MessageBox(0,"һ�����ϯ���˲ֿ⣬ʣ���ľͷ�����޼�","��Ϣ",MB_OK);
			MSGPrint("һЩľͷ���ջ���"); 
			rc.wood-=9000;
		}
		gto(26,0);
		pth(26,0,rc.wood,"ľͷ");pth(26,10,rc.cloth,"����");pth(26,20,rc.fur,"ëƤ");pth(26,30,rc.tooth,"����");
		pthnum(4,6,rc.trap," ");
		pthnum(6,6,dt.house," "); 
        if(Preserve(save)) save_a();
		else if(Preserve(github)) system("start github.html");
		else if(Preserve(trip)) mmct(),fireroom();
		else if(Preserve(MF) && !fl.fireroom){
            gto(22,0);
            printf("                                                   ");
			gto(22,0); 
            printf("���Ӻ���,���ȼ��\n"); 
            MF = NewButton(3,1,0xf,"   ���   ");//֮���ټ�һ����ʱ�� 
            FR = NewButton(1,1,0xf,"�����");
            Preserve(FR);
            system("title �����");
            rc.wood-=1;
            fl.fireroom = 5;
            Sleep(100);
    	}
        else if(Preserve(MF) && fl.fireroom){
        	if(fl.fireroom-1!=0 && rc.wood-1>=0){
        		fl.fireroom -=1;
        		gto(22,0);
        		printf("                                               ");
        		gto(22,0);
        		printf("����ů��,���ȼ��\n");
        		rc.wood -=1;
        		Sleep(100);
			}
			/*
			else if(fl.fireroom-1==1){
        		fl.fireroom -=1;
        		gto(22,0);
        		printf("                                               ");
        		gto(22,0);
        		printf("����ů��,���ȼ��\n");
        		rc.wood -=1;
        		Sleep(100);
        		trap=NewButton(4,1,0xf,"   ����   ");
				car=NewButton(5,1,0xf,"   ����   ");
				house=NewButton(6,1,0xf,"   С��   "); 
				hotel=NewButton(7,1,0xf," ����С�� ");	
			}
			*/
			else{
				gto(22,0);
				printf("                                               ");
				gto(22,0); 
				printf("����Ѿ�ȼ��ľ�񲻹��ˡ�\n");
				fl.fireroom=1;
				fl.village=1;
				MF = NewButton(3,1,8," ������� ");
				VL = NewButton(1,10,0xf,"����ɭ��");
				MessageBox(0,"һ��İ�����߽�С�ݣ������������ڽ�����","��Ϣ",MB_OK);
				MessageBox(0,"İ���˵ĺ���ƽ������������˵��������ܶණ��","��Ϣ",MB_OK); 
				if(!rc.car)car=NewButton(5,1,0xf,"   ����   ");
				house=NewButton(6,1,0xf,"   С��   "); 		
				hotel=NewButton(7,1,0xf," ����С�� ");
				trap=NewButton(4,1,0xf,"   ����   ");
				trip = NewButton(1,19,0xf,"�������");
				Preserve(trap);
				Preserve(car);
				Preserve(house);
				Preserve(hotel);
			}	 
		}
		else if(Preserve(VL) && fl.fireroom)village();
		else if(Preserve(car) && !rc.car){
			if(rc.wood - 30>=0){
			rc.wood-=30;
			rc.car=1;
			car = NewButton(5,1,0xf,"��ӵ�л���"); 
			MSGPrint("ҡҡ�λεĻ��������Ŵ�ɭ���˳���ľͷ"); 
			}
			else MSGPrint("ľͷ������");
		}
		else if(Preserve(trap)){
			if(rc.wood-10*(rc.trap+1)>=0 && rc.trap<20){
				rc.wood -= 10*(rc.trap+1);
				rc.trap+=1;
				MSGPrint("����Խ�࣬ץ�������Խ��"); 
			}
			else if(rc.trap<20) MSGPrint("ľͷ������");
			else MSGPrint("�����������Ѿ���������");
		}
		else if(Preserve(house)){
			if(rc.wood-100*(dt.house+1)>=0 && dt.house<80){
				rc.wood -= 100*(dt.house+1);
				dt.house+=1;
				MSGPrint("������������һ��С�ݣ���˵��Ϣ�ܿ�ᴫ��ȥ"); 
			}
			else if(dt.house<80) MSGPrint("ľͷ������");
			else MSGPrint("��Ҳû�н���С�ݵĿյ���");	
		}
	}
} 
int main(){
	system("mode 80,45"); 
	//system("color 8f"); //���Ҫ����ɫ�Ͱ����н����ע����ע��һ�� 
    system("color f0");
    
	freopen("sperr.txt","r",stdin);
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++)
        {
		    a[i][j]=getchar();
        }
        getchar();
	}
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++)
        {
            a[i][j]=getchar();
        }
        getchar();
	}
    fclose(stdin);
    resourceinput();
    flaginput();
    datainput();
    armsinput();
    if(fl.fireroom == 1){
		car=NewButton(5,1,0xf,"   ����   ");
		house=NewButton(6,1,0xf,"   С��   "); 		
		hotel=NewButton(7,1,0xf," ����С�� ");
		trap=NewButton(4,1,0xf,"   ����   ");		    	
		VL = NewButton(1,10,0xf,"����ɭ��");
		trip = NewButton(1,19,0xf,"�������");
	} 
	MessageBox(0,"Welcome to a dark room v0.1.1!","Stdin Cache complete!",MB_OK);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false; 
    SetConsoleCursorInfo(handle, &CursorInfo);
    system("cls"); 
    fireroom();
    system("pause");
    return 0; 
}

