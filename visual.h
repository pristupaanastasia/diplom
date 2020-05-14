#ifndef VISUAL_H
#define VISUAL_H

#include <qapplication.h>
#include <qwidget.h>
#include <qscrollview.h>
#include <qsocket.h>
#include <qsocketdevice.h>
#include <iostream>
#include <qtimer.h>

class BitPaint : public QWidget
{
	Q_OBJECT
	public:
		BitPaint(QWidget *parent = 0,const char *name = 0);
	protected:
		void paintEvent(QPaintEvent *);
		void rebitpaint(void);
	public slots:
		void bitchange();
		void change_x(int);
		void change_y(int);
};
class CannonField : public QWidget
{
	Q_OBJECT
	public:
		CannonField(QWidget *parent=0, const char *name=0);
	protected:
		void paintEvent(QPaintEvent *);
		void mousePressEvent(QMouseEvent *e);
		void repaint(void);
	public slots:
		void kadr_change(int pr_kadr);
		void pal_change(int pr_pal);
		void x_size_change(int x_size);
		void y_size_change(int y_size);
		void sil_change(int sil);
		void obzor();
		void archiv();
	signals:
		void text_kadr_change(const QString &);
		void text_pal_change(const QString &);
		void press_bit();
		void change_bit_x(int);
		void change_bit_y(int);
		void obzor_x(int);
		void obzor_y(int);
};
#endif
