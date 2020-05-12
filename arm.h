#ifndef ARM_H
#define ARM_H
#include <qwidget.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qtimer.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qscrollbar.h>
#include "visual.h"
class MainWindow: public QWidget
{
	Q_OBJECT
	public:
	MainWindow(QWidget *parent=0, const char *name=0);
	QPushButton *exitbutton;
	QPushButton *obzor;
	CannonField *paint;
	BitPaint *pbit;
	QPushButton *archiv;
	QPushButton *vkl_but;
	QPushButton *vikl_but;
	QComboBox *kadr;
	QComboBox *palitra;
	QLabel *text_kadr;
	QLabel *text_usil;
	QLabel *text_palitra;
	QLabel *text_x;
	QLabel *text_y;
	QLabel *sistem;
	QLabel *sistime;
	QTimer *sistimer;
	QComboBox it_x;
	QComboBox it_y;
	//QLabel *text2;
	public slots:
		void timerend();
		void start_timer();
		void stop_timer();
};
#endif

