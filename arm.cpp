
#include <qapplication.h>
#include "arm.h"
#include "visual.h"
#include <sys/stat.h>

char *time_s;
time_t time_1;
MainWindow::MainWindow(QWidget *parent, const char *name)
	:QWidget(parent,name)
{
	exitbutton = new QPushButton(tr("Exit"),this);
	//exitbutton->setFont(QFont("Times",15,QFont::Bold));
	exitbutton->setFixedSize(100,35);
	connect(exitbutton,SIGNAL(clicked()),this,SLOT(close()));
	
	obzor = new QPushButton(tr("Obzor"),this);
	obzor->setFixedSize(100,35);
		
	paint = new CannonField(this,"paint");
	paint->setFixedWidth(700);
	paint->setFixedHeight(450);

	pbit = new BitPaint(this,"pbit");
	pbit->setFixedWidth(80);
	pbit->setFixedHeight(400);
	
	connect(paint,SIGNAL(press_bit()),pbit,SLOT(bitchange()));
	archiv = new QPushButton(tr("archiv"),this);
	archiv->setFixedSize(100,35);

	connect(obzor,SIGNAL(clicked()),paint,SLOT(obzor()));
	connect(archiv,SIGNAL(clicked()),paint,SLOT(archiv()));
	QSpinBox *it_x = new QSpinBox(this);
	it_x->setRange(1,100);
	it_x->setSuffix("%");
	it_x->setValue(100);
	it_x->setLineStep(10);
	QSpinBox *it_y = new QSpinBox(this);
	it_y->setRange(1,100);
	it_y->setSuffix("%");
	it_y->setValue(100);
	it_y->setLineStep(10);
	QSpinBox *sil = new QSpinBox(this);
	sil->setRange(1,1000);
	sil->setSuffix("%");
	sil->setValue(100);
	sil->setLineStep(10);
	connect(it_x,SIGNAL(valueChanged(int)),paint,SLOT(x_size_change(int)));
	connect(it_y,SIGNAL(valueChanged(int)),paint,SLOT(y_size_change(int)));
	connect(paint,SIGNAL(obzor_x(int)),it_x,SLOT(setValue(int)));
	connect(paint,SIGNAL(obzor_y(int)),it_y,SLOT(setValue(int)));
	connect(sil,SIGNAL(valueChanged(int)),paint,SLOT(sil_change(int)));
	QComboBox *kadr = new QComboBox(this);
	kadr->insertItem(tr("kadr 1"));
	kadr->insertItem(tr("kadr 2"));
	kadr->insertItem(tr("kadr 3"));
	kadr->insertItem(tr("kadr 4"));
	
	connect(kadr,SIGNAL(activated(int)),paint,SLOT(kadr_change(int)));
	QComboBox *palitra = new QComboBox(this);
	palitra->insertItem(tr("palitra green"));
	palitra->insertItem(tr("palitra blue"));
	palitra->insertItem(tr("palitra red"));
	palitra->insertItem(tr("palitra black"));
	
 	connect(palitra,SIGNAL(activated(int)),paint,SLOT(pal_change(int)));
	text_x = new QLabel(tr("change x"),this);

	text_y = new QLabel(tr("change y"),this);
	text_palitra = new QLabel(" ",this);
	text_kadr = new QLabel(" ",this);
	
	sistem = new QLabel(tr("system time"),this);
	sistime = new QLabel(" ",this);
	vkl_but = new QPushButton(tr("vkl"),this);
	connect(vkl_but,SIGNAL(clicked()),this,SLOT(start_timer()));
	vikl_but = new QPushButton(tr("vikl"),this);
	connect(vikl_but,SIGNAL(clicked()),this,SLOT(stop_timer()));
	text_usil = new QLabel(tr("power"),this);	
	connect(paint,SIGNAL(text_pal_change(const QString
&)),text_palitra,SLOT(setText(const QString &)));
	connect(paint,SIGNAL(text_kadr_change(const QString &)),
text_kadr,SLOT(setText(const QString &)));
	QVBoxLayout *lamain = new QVBoxLayout(this);
	QVBoxLayout *sistemlay = new QVBoxLayout(this);
	QVBoxLayout *twoandtree = new QVBoxLayout(this);
	QHBoxLayout *sislaytime = new QHBoxLayout(this);
	QHBoxLayout *addfour = new QHBoxLayout();
	QHBoxLayout *mainlay = new QHBoxLayout();
	QHBoxLayout *mainlay2 = new QHBoxLayout();
	QHBoxLayout *mainlay3 = new QHBoxLayout();
	QHBoxLayout *mainlay4 = new QHBoxLayout();
	QHBoxLayout *layup = new QHBoxLayout();
	QHBoxLayout *layup2 = new QHBoxLayout();
	QHBoxLayout *painttwo = new QHBoxLayout();
	layup->addWidget(sistem);
	layup->addWidget(sistime);
	layup2->addWidget(vkl_but);
	layup2->addWidget(vikl_but);
	sistemlay->addLayout(layup);
	sistemlay->addLayout(layup2);
	sislaytime->addLayout(sistemlay);
	sislaytime->addWidget(exitbutton);
	mainlay->addWidget(text_palitra);
	mainlay->addWidget(text_kadr);
	mainlay2->addWidget(text_x);
	mainlay2->addWidget(it_x);
	mainlay2->addWidget(text_y);
	mainlay2->addWidget(it_y);
	mainlay2->addWidget(text_usil);
	mainlay2->addWidget(sil);
	mainlay3->addWidget(obzor);
	mainlay3->addWidget(archiv);
	mainlay4->addWidget(palitra);
	mainlay4->addWidget(kadr);
	twoandtree->addLayout(mainlay2);
	twoandtree->addLayout(mainlay3);
	addfour->addLayout(mainlay4);
	addfour->addLayout(twoandtree);
	lamain->addLayout(sislaytime);
	lamain->addLayout(mainlay);
	painttwo->addWidget(paint);
	painttwo->addWidget(pbit);
	lamain->addLayout(painttwo);
	lamain->addLayout(addfour);
	sistimer = new QTimer(this);
	connect(sistimer,SIGNAL(timeout()),this,SLOT(timerend()));
	//mainlay->setSpacing(25);
}
void MainWindow::timerend()
{
	time(&time_1);
	time_s = ctime(&time_1);
	sistime->setText(QString(time_s));
}
void MainWindow::start_timer()
{
	sistimer->start(1000,FALSE);
}
void MainWindow::stop_timer()
{
	sistimer->stop();
}
