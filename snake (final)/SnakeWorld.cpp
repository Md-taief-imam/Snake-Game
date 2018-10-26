# include "iGraphics.h"
# include <string.h>

int x[100],y[100];
char name [100],str [100];
int len=0;
bool flag=false;
bool flag2 = false;

FILE *names,*scores;

int i,j,num=1,val=1,dx=7,dy=7;
int up=0,down=0,left=0,right=1,ex=7;

int x1,y2,k, xx1, yy2;

int st = 10,sn = 0,count = 0,hs,level = 1,se = 80;
char score[10],lev[10],h_s[10];


int game_x=0,game_y=0;
void SnakeMove()

{
	
	for ( i = ex - 1 ; i > 0 ; i-- )
	{
		x[i] = x[i-1] ;
		y[i] = y[i-1] ;
	}
	if ( up==1 ) {
		y[0] += dy ;
	}
	else if ( down==1 ) {
		y[0] -= dy ;
	}
	else if ( right==1 ) {
		x[0] += dx ;
	}
	else if ( left==1 ) {
		x[0] -= dx ;
	}
}

void food ()
{
	//srand(time(NULL));
	x1 = rand()%760+15;
	y2 = rand()%470+35;
	
	count ++;
	
}

void getScore()
{
	scores=fopen("scores.txt", "r");
	names=fopen("names.txt","r");
	
	
	fscanf(names,"%s", &str);
	
	fscanf(scores,"%d", &hs);
	fclose(names);
	fclose(scores);
}


void iDraw()
{
	iClear();
	
	if (st == 10) iShowBMP(game_x,game_y,"cover.bmp");
	if (st == 0 && sn == 0)
	{
		iShowBMP(game_x,game_y,"start.bmp");
		
		iSetColor(255,255,255);
		iRectangle(10,30,780,510); 	
		//for NEW GAME 
		
		iSetColor(255,255,255);
		iRectangle(500,470,150,60);
		iRectangle(499,469,150,60);
		iRectangle(501,471,150,60);
		iSetColor(255,255,255);
		iText(510,490," New Game " , GLUT_BITMAP_TIMES_ROMAN_24);
		//for CONTROLS
		
		iSetColor(5,255,5);
		iRectangle(500,370,150,60);
		iRectangle(499,369,150,60);
		iRectangle(501,371,150,60);
		iSetColor(255,0,0);
		iText(505,390," CONTROLS " , GLUT_BITMAP_TIMES_ROMAN_24);
		//for QUIT
		
		iSetColor(55,75,75);
		iRectangle(500,270,150,60);
		iRectangle(499,269,150,60);
		iRectangle(501,271,150,60);
		iSetColor(255,255,255);
		iText(525,290," ABOUT " , GLUT_BITMAP_TIMES_ROMAN_24);
		//for US
		
		iSetColor(115,150,175);
		iRectangle(500,170,150,60);
		iRectangle(499,169,150,60);
		iRectangle(501,171,150,60);
		iSetColor(255,0,0);
		iText(501,190,"HIGH SCORE" , GLUT_BITMAP_TIMES_ROMAN_24);
		//for highscore
		
		iSetColor(67,83,97);
		iRectangle(500,70,150,60);
		iRectangle(499,69,150,60);
		iRectangle(501,71,150,60);
		iSetColor(255,255,255);
		iText(530,90," QUIT " , GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (st == 1)
	{
		iShowBMP (0,0,"option.bmp");
		//easy
		iSetColor(5,255,5);
		iRectangle(300,300,150,60);
		iRectangle(299,299,150,60);
		iRectangle(301,301,150,60);
		iSetColor(255,255,255);
		iText (340, 320, "EASY", GLUT_BITMAP_TIMES_ROMAN_24);
		
		
		//easy
		if (sn == 3)
		{;
		iShowBMP(game_x,game_y,"background_e.bmp");
		iSetColor(0,0,250);                         // Border
		iRectangle(10,30,780,510);
		iSetColor(10, 155, 255);
		iText (350, 580, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
		iText (600, 580, "LEVEL", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(10,10,"Press 'p' to pause");			// Score							
		
		sprintf (score , "%.3d" , count);
		iSetColor(255, 255, 255);
		iText (370 , 550 , score , GLUT_BITMAP_TIMES_ROMAN_24);
		
		sprintf (lev , "%.2d" , level);
		iSetColor(255, 255, 255);
		iText (620 , 550 , lev , GLUT_BITMAP_TIMES_ROMAN_24);
		
		if (count % 15 == 0 && count != 0 ) 
		{
			count = count + 1;
			level = level + 1;
			se = se - 15;
			iSetTimer(se, SnakeMove);
			
		}
		
		if( count % 5 == 0 && count != 0)
		{
			if(!flag2)
			{
				xx1 = rand()%760+15;
				yy2 = rand()%470+35;
				
				
				flag2 = true;
			}
		}
		
		sprintf (lev , "%.2d" , level);
		
		iSetColor(130,255,130);	                     // Snake
		for(i=0;i<ex;i++)
		{
			iFilledRectangle(x[i],y[i],5,5);
		}
		
		int snake_hit_itself = 0 ;
		for ( i = 1 ; i < ex ; i++ ) {
			if ( x[ 0 ] == x[ i ] && y[ 0 ] == y[ i ] ) {
				snake_hit_itself = 1 ;
			}
		}
		
		if(x[0] >= 787 || x[0] <= 10 || y[0] >= 537 || y[0] <= 27 || snake_hit_itself == 1)
		{
			
			iPauseTimer(0);
			iShowBMP(game_x,game_y,"game_over.bmp");
			iText(600,10,"Press 'r' to resume");
			hs = count;
			sprintf (h_s,"%.3d",count);
			iSetColor(20,10,250);	
			iText(300,200,"YOUR SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(500,200,h_s,GLUT_BITMAP_TIMES_ROMAN_24);
			
		}
		if (!flag)
		{
			x1 = rand()%740+15;
			y2 = rand()%470+35;
			flag = true;
		}
		iSetColor (255,255,0);
		
		iFilledRectangle(x1, y2, 5, 5);
		
		iSetColor (255, 0, 0);
		if(flag2)iFilledCircle(xx1, yy2, 3);
		
		if (k==1)
		{
			iText (300, 300, "Game Paused", GLUT_BITMAP_TIMES_ROMAN_24);
			iText (270, 270, "Press Arrow Keys To Continue");
		}
		if ( (x1 < x[0]+10 && x1> x[0]-5) && y2>y[0]-5 && y2<(y[0]+10))
		{
			food ();
			
			
			ex++;
		}
		
		}
		if (flag2 && (xx1 < x[0]+10 && xx1> x[0]-5) && yy2>y[0]-5 && yy2<(y[0]+10))
		{
			count = count + 6 ;
			
			
			
			flag2 = false;
		}
		
	}
	if (st == 2) 
	{
		iShowBMP (0,0,"controls.bmp");
		iText(600,20,"Press 'r' to go back");
	}
	if (st == 3) 
	{
		iShowBMP (0,0,"about.bmp");
		iText(600,20,"Press 'r' to go back");
	}
	
	// High Score
	if(st==4)
	{
		getScore();
		iText(300,400,"Highest Score :",GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(h_s, "%d", hs);
		iText(300,300,str,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400,300,h_s,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(st==5)
	{
		iText(200,400,"Please Enter your name.");
		iRectangle(200,300,300,50);
		iText(220,320,name);
	}
    if(count>=hs)
    {
		
		scores=fopen("scores.txt", "w");
		
		fprintf(scores,"%d\n",hs);
		
		fclose(scores);
        
		names=fopen("names.txt","w");
		
		fprintf(names,"%s", str);
		
		fclose(names);
	}
	
}

void iMouseMove(int mx, int my)
{
	//place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx >= 500 && mx <= 650 && my >= 470 && my <= 530 )
		{
			st=5;
		}
		if(mx >= 500 && mx <= 650 && my >= 370 && my <= 430 )
		{
			st=2;
		}
		if(mx >= 500 && mx <= 650 && my >= 270 && my <= 330 )
		{
			st=3;
		}
		if(mx >= 500 && mx <= 650 && my >= 170 && my <= 230 )
		{
			st=4;
		}
		if(mx >= 500 && mx <= 650 && my >= 70 && my <= 130 )
		{
			exit (0);
		}
		if (st == 1)
		{
			if(mx >= 300 && mx <= 450 && my >= 300 && my <= 360 )
			{
				sn=3;
			}
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

void iKeyboard(unsigned char key)
{
	if (st == 5)
	{
		if(key == '\r')
		{ 
			strcpy(str, name);
			for(i = 0; i < len; i++)
				name[i] = 0;
			
			st=1;
			len = 0;
		}
		else
		{
			name[len] = key;
			printf("%c", name[len]);
			len++;
		}
	}
	else
	{
		if(key == '\r')
		{
			st = 0;
		}
		if(key == 'p')
		{
			iPauseTimer(0);
			
			k=1;
		}
		if(key == 'r')
		{
			st = 0;
			sn = 0;
		}
	}
}


void iSpecialKeyboard(unsigned char key)
{
	if(key== GLUT_KEY_UP)
	{
		if (left==1)
		{
			
			up=1;
			down=left=right=0;
			iResumeTimer (0);
		}
		else if (right==1)
		{
			up=1;
			down=left=right=0;
			iResumeTimer (0);
		}
	}
	if(key== GLUT_KEY_DOWN)
	{
		if (left==1)
		{
			down=1;
			up=left=right=0;
			iResumeTimer (0);
			
		}
		else if (right==1)
		{
			down=1;
			up=left=right=0;
			iResumeTimer (0);
			
		}
	}
	if(key== GLUT_KEY_LEFT)
	{
		if (up==1)
		{	
			left=1;
			up=down=right=0;
			iResumeTimer (0);
			
		}
		else	if (down==1)
		{
			left=1;
			up=down=right=0;
			iResumeTimer (0);
			
		}
	}
	if(key== GLUT_KEY_RIGHT)
	{
		if (up==1)
		{
			right=1;
			up=down=left=0;
			iResumeTimer (0);
			
		}
		else 	if (down==1)
		{
			right=1;
			up=down=left=0;
			iResumeTimer (0);
			
		}
	} 
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}
int main()
{
	getScore();
	x[0]= 380;
	
	for (i=0;i<=ex;i++)
	{
		x[i+1]=x[i]-7;
		y[i]=500;
	}
	
	srand(time(NULL));
	iSetTimer (se,SnakeMove);
	
	iPauseTimer (0);
	
	
	iInitialize(800, 600, "Snake Game");
	return 0;
}