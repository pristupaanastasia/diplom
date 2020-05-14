#include <qapplication.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qhbox.h>
#include <qslider.h>
#include <qspinbox.h>
#include "arm.h"
#include <iostream.h>

int main(int argc,char *argv[])
{
	//setEncoding(QTextStream::Unicode);
	QApplication app(argc,argv);
	QTranslator *tr1 = new QTranslator(0);
	tr1->load("main_ru.qm",".");
	app.installTranslator(tr1);

	QTranslator *tr2 = new QTranslator(0);
	tr2->load("arm_ru.qm",".");
	app.installTranslator(tr2);
	
	QTranslator *tr3 = new QTranslator(0);
	tr3->load("visual_ru.qm",".");
	app.installTranslator(tr3);

	MainWindow *dialog = new MainWindow;
	dialog->setCaption(QObject::tr("programm to image"));
	//dialog->setGeometry(0,0,500,500);
	app.setMainWidget(dialog);
	dialog->show();	
	return app.exec();
}
