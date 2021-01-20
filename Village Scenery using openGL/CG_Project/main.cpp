#include<iostream>
#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>

using namespace std;

#define SPEED 30.0

float ii=0.0,m=0.0,n=0.0,o=0.0,c=0.0,b=0.0;
float p=0.75,q=0.47,r=0.14;
float e=0.90,f=0.91,g=0.98;
int count=0;

int light=1,day=1,plane=0,comet=0,xm=900,bird=0;
char ch;

void draw_pixel(int cx, int cy)
{

	glBegin(GL_POINTS);
	glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(int h,int k, int x,int y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(int h, int k, int r)
{
	int d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object()
{
    int i;
    if(day==1)
    {
        //sky
        glColor3f(0.0,0.9,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(0,380);
        glVertex2f(0,700);
        glVertex2f(1100,700);
        glVertex2f(1100,380);
        glEnd();

        //sun
        for(i=0;i<=35;i++)
        {
            glColor3f(1.0,0.9,0.0);
            draw_circle(100,625,i);
        }

        //plane
        if(plane==1)
        {
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_POLYGON);
            glVertex2f(925+n,625+o);
            glVertex2f(950+n,640+o);
            glVertex2f(1015+n,640+o);
            glVertex2f(1030+n,650+o);
            glVertex2f(1050+n,650+o);
            glVertex2f(1010+n,625+o);
            glEnd();

            glColor3f(0.8,0.8,0.8);
            glBegin(GL_LINE_LOOP);
            glVertex2f(925+n,625+o);
            glVertex2f(950+n,640+o);
            glVertex2f(1015+n,640+o);
            glVertex2f(1030+n,650+o);
            glVertex2f(1050+n,650+o);
            glVertex2f(1010+n,625+o);
            glEnd();

        }

        //Hill1
        glColor3f(0.75,0.75,0.71);
        glBegin(GL_POLYGON);
        glVertex2f(300,380);
        glVertex2f(1000,380);
        glVertex2f(520,650);
        glEnd();

        //Hill2
        glColor3f(0.7,0.75,0.8);
        glBegin(GL_POLYGON);
        glVertex2f(700,380);
        glVertex2f(1100,380);
        glVertex2f(880,600);
        glEnd();

        //Hill3
        glColor3f(0.7,0.75,0.71);
        glBegin(GL_POLYGON);
        glVertex2f(500,380);
        glVertex2f(1000,380);
        glVertex2f(750,680);
        glEnd();

        //cloud1


        for(i=0;i<=20;i++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(30+m,600,i);
        }

        for(i=0;i<=35;i++)
        {

            glColor3f(1.0,1.0,1.0);
            draw_circle(70+m,600,i);
            draw_circle(95+m,600,i);
            draw_circle(130+m,600,i);
        }

        for(i=0;i<=20;i++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(160+m,600,i);
        }


        //cloud2


        for(i=0;i<=20;i++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(200+m,630,i);

        }


        for(i=0;i<=35;i++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(240+m,630,i);
            draw_circle(265+m,630,i);
        }

        for(i=0;i<=20;i++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(305+m,630,i);
        }

        //cloud3


        for(i=0;i<=20;i++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(370+m,615,i);
        }

        for(i=0;i<=35;i++)
        {

            glColor3f(1.0,1.0,1.0);
            draw_circle(410+m,615,i);
            draw_circle(435+m,615,i);
            draw_circle(470+m,615,i);
        }

        for(i=0;i<=20;i++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(500+m,615,i);
        }

        //grass
        glColor3f(0.6,0.8,0.196078);
        glBegin(GL_POLYGON);
        glVertex2f(0,160);
        glVertex2f(0,380);
        glVertex2f(1100,380);
        glVertex2f(1100,160);
        glEnd();

    }

    else
    {
        //sky
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,380);
        glVertex2f(0,700);
        glVertex2f(1100,700);
        glVertex2f(1100,380);
        glEnd();

        //moon
        int i;

        for(i=0;i<=35;i++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(100,625,i);
        }

        //star1

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();

        //star2
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(975,643);
        glVertex2f(970,635);
        glVertex2f(980,635);
        glVertex2f(975,632);
        glVertex2f(970,640);
        glVertex2f(980,640);
        glEnd();

        //star3
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(875,543);
        glVertex2f(870,535);
        glVertex2f(880,535);
        glVertex2f(875,532);
        glVertex2f(870,540);
        glVertex2f(880,540);
        glEnd();

        //star4
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(375,598);
        glVertex2f(370,590);
        glVertex2f(380,590);
        glVertex2f(375,587);
        glVertex2f(370,595);
        glVertex2f(380,595);
        glEnd();

        //star5
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(750,628);
        glVertex2f(745,620);
        glVertex2f(755,620);
        glVertex2f(750,618);
        glVertex2f(745,625);
        glVertex2f(755,625);
        glEnd();

        //star6
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(200,628);
        glVertex2f(195,620);
        glVertex2f(205,620);
        glVertex2f(200,618);
        glVertex2f(195,625);
        glVertex2f(205,625);
        glEnd();

        //star7
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(100,528);
        glVertex2f(95,520);
        glVertex2f(105,520);
        glVertex2f(100,518);
        glVertex2f(95,525);
        glVertex2f(105,525);
        glEnd();

        //star8
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(300,468);
        glVertex2f(295,460);
        glVertex2f(305,460);
        glVertex2f(300,458);
        glVertex2f(295,465);
        glVertex2f(305,465);
        glEnd();

        //star9
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(500,543);
        glVertex2f(495,535);
        glVertex2f(505,535);
        glVertex2f(500,532);
        glVertex2f(495,540);
        glVertex2f(505,540);
        glEnd();


        //comet
        if(comet==1)
        {
            for(i=0;i<=7;i++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(300+c,675,i);
            }
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(200+c,675);
            glVertex2f(300+c,682);
            glVertex2f(300+c,668);
            glEnd();
        }

        //Hill1
        glColor3f(0.3,0.3,0.3);
        glBegin(GL_POLYGON);
        glVertex2f(300,380);
        glVertex2f(1000,380);
        glVertex2f(520,650);
        glEnd();

        //Hill2
        glColor3f(0.3,0.31,0.33);
        glBegin(GL_POLYGON);
        glVertex2f(700,380);
        glVertex2f(1100,380);
        glVertex2f(880,600);
        glEnd();

        //Hill3
        glColor3f(0.3,0.3,0.33);
        glBegin(GL_POLYGON);
        glVertex2f(500,380);
        glVertex2f(1000,380);
        glVertex2f(750,680);
        glEnd();

        //Plane
        if(plane==1)
        {

            for(i=0;i<=1;i++)
            {
                glColor3f(1.0,0.0,0.0);
                draw_circle(950+n,625+o,i);
                glColor3f(1.0,1.0,0.0);
                draw_circle(954+n,623+o,i);

            }



        }

        //grass
        glColor3f(0.0,0.3,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,160);
        glVertex2f(0,380);
        glVertex2f(1100,380);
        glVertex2f(1100,160);
        glEnd();

    }

    //Ground
	glColor3f(0.0,0.3,0.0);
	glBegin(GL_POLYGON);
    glVertex2f(-600,0);
    glVertex2f(-600,185);
    glVertex2f(1100,185);
    glVertex2f(1100,0);
	glEnd();

    //small tree 1
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(280,185);
    glVertex2f(280,255);
    glVertex2f(295,255);
    glVertex2f(295,185);
    glEnd();


	for(i=0;i<=30;i++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(270,250,i);
		draw_circle(310,250,i);
	}

	for(i=0;i<=25;i++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(280,290,i);
		draw_circle(300,290,i);
	}

	for(i=0;i<=20;i++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(290,315,i);
	}

    //small tree 3
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(420,185);
    glVertex2f(420,255);
    glVertex2f(435,255);
    glVertex2f(435,185);
    glEnd();


	for(i=0;i<=30;i++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(410,250,i);
		draw_circle(450,250,i);
	}

	for(i=0;i<=25;i++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(420,290,i);
		draw_circle(440,290,i);
	}

	for(i=0;i<=20;i++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(430,315,i);
	}

	//small tree 2
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(350,185);
    glVertex2f(350,255);
    glVertex2f(365,255);
    glVertex2f(365,185);
    glEnd();


	for(i=0;i<=30;i++)
	{
		glColor3f(0.0,0.55,0.0);
		draw_circle(340,250,i);
		draw_circle(380,250,i);
	}

	for(i=0;i<=25;i++)
	{
		glColor3f(0.0,0.55,0.0);
		draw_circle(350,290,i);
		draw_circle(370,290,i);
	}

	for(i=0;i<=20;i++)
	{
		glColor3f(0.0,0.55,0.0);
		draw_circle(360,315,i);
	}

    //small tree 4
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1030,185);
    glVertex2f(1030,255);
    glVertex2f(1045,255);
    glVertex2f(1045,185);
    glEnd();


	for(i=0;i<=30;i++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1020,250,i);
		draw_circle(1060,250,i);
	}

	for(i=0;i<=25;i++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1030,290,i);
		draw_circle(1050,290,i);
	}

	for(i=0;i<=20;i++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1040,315,i);
	}
    // big tree 1
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(100,135);
    glVertex2f(100,285);
    glVertex2f(140,285);
    glVertex2f(140,135);
    glEnd();

	for(i=0;i<=40;i++)
	{
		glColor3f(0.0,0.6,0.0);
		draw_circle(40,280,i);
		draw_circle(90,280,i);
		draw_circle(150,280,i);
		draw_circle(210,280,i);
		draw_circle(65,340,i);
		draw_circle(115,340,i);
		draw_circle(175,340,i);

	}

	for(i=0;i<=55;i++)
	{
		glColor3f(0.0,0.6,0.0);
		draw_circle(115,360,i);


	}

 	//House

	glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);
    glVertex2f(490,330);
    glVertex2f(540,430);
    glVertex2f(960,430);
    glVertex2f(1010,330);
	glEnd();

	glColor3f(p,q,r);
	glBegin(GL_POLYGON);
    glVertex2f(550,100);
    glVertex2f(550,330);
    glVertex2f(950,330);
    glVertex2f(950,100);
    glVertex2f(850,100);
    glVertex2f(850,250);
    glVertex2f(650,250);
    glVertex2f(650,100);

	glEnd();

	//window border

	glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);
    glVertex2f(595,205);
    glVertex2f(595,285);
    glVertex2f(675,285);
    glVertex2f(675,205);
	glEnd();

	glBegin(GL_POLYGON);
    glVertex2f(825,205);
    glVertex2f(825,285);
    glVertex2f(905,285);
    glVertex2f(905,205);
	glEnd();

	glBegin(GL_POLYGON);
    glVertex2f(845,205);
    glVertex2f(845,285);
    glVertex2f(850,285);
    glVertex2f(850,205);
	glEnd();

	//door
	glColor3f(e,f,g);
	glBegin(GL_POLYGON);
    glVertex2f(800,100);
    glVertex2f(800,220);
    glVertex2f(700,220);
    glVertex2f(700,100);
	glEnd();

	glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);
    glVertex2f(760,120);
    glVertex2f(760,200);
    glVertex2f(700,220);
    glVertex2f(700,100);
	glEnd();

	//window
	glColor3f(e,f,g);
	glBegin(GL_POLYGON);
    glVertex2f(600,210);
    glVertex2f(600,280);
    glVertex2f(670,280);
    glVertex2f(670,210);
	glEnd();

	glBegin(GL_POLYGON);
    glVertex2f(830,210);
    glVertex2f(830,280);
    glVertex2f(900,280);
    glVertex2f(900,210);
	glEnd();

	glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);
    glVertex2f(620,210);
    glVertex2f(620,280);
    glVertex2f(625,280);
    glVertex2f(625,210);
	glEnd();

	glBegin(GL_POLYGON);
    glVertex2f(650,210);
    glVertex2f(650,280);
    glVertex2f(655,280);
    glVertex2f(655,210);
	glEnd();


	glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);
    glVertex2f(850,205);
    glVertex2f(850,285);
    glVertex2f(855,285);
    glVertex2f(855,205);
	glEnd();

	glBegin(GL_POLYGON);
    glVertex2f(880,205);
    glVertex2f(880,285);
    glVertex2f(885,285);
    glVertex2f(885,205);
	glEnd();


	if(bird==1)
	{
        glColor3f(0.73,0.16,0.96 );
        glBegin(GL_POLYGON);
		glVertex2f(300+ii-xm,265+b);
		glVertex2f(330+ii-xm,265+b);
		glVertex2f(330+ii-xm,250+b);
        glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(330+ii-xm,275+b);
		glVertex2f(340+ii-xm,275+b);
		glVertex2f(330+ii-xm,265+b);
        glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(200+ii-xm,285+b);
		glVertex2f(230+ii-xm,285+b);
		glVertex2f(230+ii-xm,270+b);
        glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(230+ii-xm,295+b);
		glVertex2f(240+ii-xm,295+b);
		glVertex2f(230+ii-xm,285+b);
        glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(150+ii-xm,285+b);
		glVertex2f(180+ii-xm,285+b);
		glVertex2f(180+ii-xm,270+b);
        glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(180+ii-xm,295+b);
		glVertex2f(190+ii-xm,295+b);
		glVertex2f(180+ii-xm,285+b);
        glEnd();


    }
    glFlush();
}


void idle()
{

    if(light==0 && (ii>=0 && ii<=1150))
    {
        ii+=SPEED/10;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;

    }

    if(light==0 && (ii>=2600 && ii<=3000))
    {

        ii+=SPEED/10;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;

    }

    if(light==0)
    {
        ii=ii;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;

    }
    if(count<=3)
    {

        glClearColor(1.0,1.0,1.0,1.0);
        ii+=SPEED/10;
        b+=SPEED/10;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;
    }
    if(ii>1900)
        ii=800.0;
    if(m>1100)
        m=0.0;
    if( o>75)
    {
        plane=0;
    }
    if(c>500)
    {
        comet=0;
    }
    if(b>500)
    {
        b=0.0;
        ii=800.0;
        count=count+1;
    }

    glutPostRedisplay();
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
    exit(0);
}


void keyboardFunc( unsigned char key, int x, int y )
{
    switch( key )
    {

    case 'd':
    case 'D':
		day=1;
		p=0.75;
		q=0.47;
		r=0.14;
		break;

	case 'n':
    case 'N':
		day=0;
		p=0.52;
		q=0.37;
		r=0.26;
		break;

	case 'b':
    case 'B':
		bird=1;
		ii=800;
		b=0.0;
		count=0;
		break;

    case 'l':
	case 'L':
		e=0.90;
		f=0.91;
		g=0.98;
		break;

    case 'f':
	case 'F':
		e=0.0;
		f=0.0;
		g=0.0;
		break;

    case 'a':
    case 'A':
        plane=1;
        o=n=0.0;
        break;

    case 'c':
    case 'C':
        comet=1;
        c=0.0;

    };

}


void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1100.0,0.0,700.0);
}



void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    glFlush();
}


int main(int argc,char** argv)
{
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"                    Village Scenery                             "<<endl;
    cout<<"--------------------------------------------------------------------------------\n"<<endl;
    cout<<"Press 'd' or 'D' to make it day. \n"<<endl;
	cout<<"Press 'n' or 'N' to make it night. \n"<<endl;
	cout<<"Press 'b' or 'B' to fly Birds. \n"<<endl;
	cout<<"Press 'l' or 'L' to turn On the lights. \n"<<endl;
	cout<<"Press 'f' or 'F' to turn Off the lights. \n"<<endl;
	cout<<"Press 'a' or 'A' to fly Aeroplane. \n"<<endl;
	cout<<"Press 'c' or 'C' to see Comet. \n"<<endl;
	cout<<"Press RIGHT MOUSE BUTTON to display menu. \n"<<endl;
	cout<<"Press any key and Hit ENTER."<<endl;
	cin>>ch;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Village Scenery");
	glutDisplayFunc(display);
    glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit();
	glutMainLoop();
	return 0;
}
