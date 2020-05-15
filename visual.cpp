#include "visual.h"
#include <qpainter.h>
#include <qpicture.h>
#include <qpixmap.h>
#include <qimage.h>
#include <qdatetime.h>
#include <math.h>
#include <fstream.h>
#include <sys/stat.h>
#include <time.h>
#include <vector.h>
int a[700*450];
int b[700*450];
int c[700*450];
int dd[700*450];
int i = 0;
int j = 0;
int k = 0;
vector<int> v(8);
double graide = 1.0;
int scale_x = 100;
int scale_y = 100;
int kadr = 1;
int palitra = 1;
int pbit = 0;
int x_bit = 0;
int y_bit = 0;
QImage bipaint(140,400,32);
QImage img(700,450,32);
QImage img_buf;
BitPaint::BitPaint(QWidget *parent,const char *name):QWidget(parent,name)
{
	pbit = 0;
}
CannonField::CannonField(QWidget *parent,const char *name) :
QWidget(parent,name)
{
//KADR1
for(i = 0;i < 450;i++)
	for(j = 0;j<700; j++)
		a[i*700 + j] = 255;

//KADR2
for(i = 0;i < 450;i++)
	for(j = 0;j<700;j++)
		b[i*700 + j]=0;
//KADR3
int g=4;
int t =2;
int l;
l = 0;
for(j = 0; j<450; j++)
{
	for(i = 0;i < 700;i++)
	{
		if (l>255 || l < 0)
		{
			t = -t;
			l = l+t;
		}
		c[j*700 + i] = l;
		l= l + t;
	}
	if (j<449)
	{
		c[(j+1)*700] = c[(j)*700] + g;
		if (c[(j+1)*700] > 255||c[(j+1)*700] < 0 )
		{
			g = -g;
			c[(j+1)*700] = c[(j)*700]+g;
		}
		l = c[(j+1)*700];
	}
}
//KADR4
k = 0;
for(j=0;j<450;j++)
{
	k = 0;
	for(i = 0;i < 700; i++)
	{
	if(((i+j*700)%4) == 0 && i!=0)
		k++;
	dd[i+j*700] = k;

	}
}
}
void BitPaint::paintEvent(QPaintEvent *)
{
	rebitpaint();
}
void CannonField::mousePressEvent(QMouseEvent *e)
{
	if(e->button() == Qt::LeftButton)
	{
		x_bit = e->x();
		y_bit = e->y();
		emit change_bit_x(x_bit);
		emit change_bit_y(y_bit);
		emit press_bit(); 
	}
}
void BitPaint::change_y(int y)
{
	if(y<450)
		y_bit = y;
	bitchange();
}
void BitPaint::change_x(int x)
{
	if (x<700)
		x_bit = x;
	bitchange();
}
void BitPaint::bitchange(void)
{
	using namespace std;
	QRgb colbit;
	if (x_bit > img_buf.width() || y_bit > img_buf.height())
		colbit = qRgb(0,0,0);
	else
	 	colbit = img_buf.pixel(x_bit,y_bit);
	colbit = colbit << 8;
	for(int i =0; i<3;i++)
	{
		if((colbit & 0xFF000000)|| i==2 )
		{
			for(int j=0;j<8;j++)
			{
			if (colbit & 0x80000000)
				v[j] = 1;
			else
				v[j] = 0;
			colbit = colbit << 1;
			}
		i=4;
		}
		else
			colbit = colbit << 8;
	}
	rebitpaint();
}
void BitPaint::rebitpaint(void)
{
	QPainter bpainter(this);
	int t =0;
	for(int i = 0;i<140;i++)
	{
		for(int j = 0;j<400;j++)//50 -1 bit
		{
			if(j > (t+1) * 50)
				t++;
			if (v[t] == 0)
				bipaint.setPixel(i,j,qRgb(255,0,0));
			else
				bipaint.setPixel(i,j,qRgb(0,255,0));
		}
		t=0; 
	}
	QPixmap bit1(bipaint);
	bit1.resize(140,400);
	bpainter.drawPixmap(0,0,bit1);
}
void CannonField::paintEvent(QPaintEvent *)
{
	emit text_pal_change(tr("Palitra green"));
	emit text_kadr_change(tr("Kadr 1"));
	repaint();
}

void CannonField::repaint(void)
{
	QPainter painter(this);
	for(int i = 0;i < 700;i++)
	{
		for(int j = 0;j < 450;j++)
		{
			switch(kadr)
			{
				case 1:
				switch(palitra)
				{
					case 1:
					img.setPixel(i,j,qRgb(0,(int)(graide*a[i+j*700]),0));
					break;
					case 2:
					img.setPixel(i,j,qRgb(0,0,(int)(graide*a[i+j*700])));
					break;
					case 3:
					img.setPixel(i,j,qRgb((int)(graide*a[i+j*700]),0,0));
					break;
					case 4:
					img.setPixel(i,j,qRgb((int)(graide*a[i+j*700]),(int)(graide*a[i+j*700]),(int)(graide*a[i+j*700])));
					break;
					
				}
				break;
				case 2:
				switch(palitra)
				{
					case 1:
					img.setPixel(i,j,qRgb(0,(int)(graide*b[i+j*700]),0));
					break;
					case 2:
					img.setPixel(i,j,qRgb(0,0,(int)(graide*b[i+j*700])));
					break;
					case 3:
					img.setPixel(i,j,qRgb((int)(graide*b[i+j*700]),0,0));
					break;
					case 4:
					img.setPixel(i,j,qRgb((int)(graide*b[i+j*700]),(int)(graide*b[i+j*700]),(int)(graide*b[i+j*700])));
					break;
				}
				break;
				case 3:
				switch(palitra)
				{
					case 1:
					img.setPixel(i,j,qRgb(0,(int)(graide*c[i+j*700]),0));
					break;
					case 2:
					img.setPixel(i,j,qRgb(0,0,(int)(graide*c[i+j*700])));
					break;
					case 3:
					img.setPixel(i,j,qRgb((int)(graide*c[i+j*700]),0,0));
					break;
					case 4:
					img.setPixel(i,j,qRgb((int)(graide*c[i+j*700]),(int)(graide*c[i+j*700]),(int)(graide*c[i+j*700])));
					break;
				}
				break;
				case 4:
				switch(palitra)
				{
					case 1:
					img.setPixel(i,j,qRgb(0,(int)(graide*dd[i+j*700]),0));
					break;
					case 2:
					img.setPixel(i,j,qRgb(0,0,(int)(graide*dd[i+j*700])));
					break;
					case 3:
					img.setPixel(i,j,qRgb((int)(graide*dd[i+j*700]),0,0));
					break;
					case 4:
					img.setPixel(i,j,qRgb((int)(graide*dd[i+j*700]),(int)(graide*dd[i+j*700]),(int)(graide*dd[i+j*700])));
					break;
				}
				break;
			}
		}
	}
	img_buf =
img.scale(img.width()*scale_x/100,img.height()*scale_y/100,QImage::ScaleFree);
	QPixmap pix(img_buf);
	pix.resize(700,450);
	painter.drawPixmap(0,0,pix);
}
void CannonField::kadr_change(int pr_kadr)
{
	switch(pr_kadr)
	{
		case 0:
			kadr = 1;
			emit text_kadr_change(tr("Kadr 1"));
			break;
		case 1:
			emit text_kadr_change(tr("Kadr 2"));
			kadr = 2;
			break;
		case 2:
			emit text_kadr_change(tr("Kadr 3"));
			kadr = 3;
			break;
		case 3:
			emit text_kadr_change(tr("Kadr 4"));
			kadr = 4;
			break;
		default:
			break;
	}	
	repaint();
}

void CannonField::pal_change(int pr_pal)
{
	switch(pr_pal)
	{
		case 0:
		emit text_pal_change(tr("Palitra green"));
		palitra = 1;
		break;
		case 1:
		emit text_pal_change(tr("Palitra blue"));
		palitra = 2;
		break;
		case 2:
		emit text_pal_change(tr("Palitra red"));
		palitra = 3;
		break;
		case 3:
		emit text_pal_change(tr("Palitra black"));
		palitra = 4;
		break;
		default:
		break;
	}
	repaint();
}
void CannonField::sil_change(int sil)
{
	graide = sil*0.01;
	repaint();
}
void CannonField::x_size_change(int x_size)
{
	scale_x = x_size;
	repaint();
}
void CannonField::y_size_change(int y_size)
{
	scale_y = y_size;
	repaint();
}
void CannonField::obzor()
{
	scale_x = 100;
	scale_y = 100;
	emit obzor_x(scale_x);
	emit obzor_y(scale_y);
}
void CannonField::archiv()
{
	QString strdate, strtime,filename;
	QDate date1 = QDate::currentDate();
	QTime time1 = QTime::currentTime();
	strdate=date1.toString("yyyy.M.d");
	strtime=time1.toString("hh_mm_ss");
	
	char fname[100];
	sprintf(fname,"/root/Desktop/%s_%s.png",strdate.ascii(),strtime.ascii());
	//filename=fname.toString(fname);
	img.save(fname,"PNG");
}
