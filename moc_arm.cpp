/****************************************************************************
** MainWindow meta object code from reading C++ file 'arm.h'
**
** Created: Wed May 13 13:29:30 2020
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "arm.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MainWindow::className() const
{
    return "MainWindow";
}

QMetaObject *MainWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MainWindow( "MainWindow", &MainWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MainWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MainWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MainWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"timerend", 0, 0 };
    static const QUMethod slot_1 = {"start_timer", 0, 0 };
    static const QUMethod slot_2 = {"stop_timer", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "timerend()", &slot_0, QMetaData::Public },
	{ "start_timer()", &slot_1, QMetaData::Public },
	{ "stop_timer()", &slot_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"MainWindow", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MainWindow.setMetaObject( metaObj );
    return metaObj;
}

void* MainWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MainWindow" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool MainWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( staticMetaObject()->localSlotIndex(
              metaObject()==staticMetaObject() ? _id : staticMetaObject()->findSlot(
				 metaObject()->slot(_id,TRUE)?metaObject()->slot(_id,TRUE)->name:0, TRUE ) ) )
    {
    case 0: timerend(); break;
    case 1: start_timer(); break;
    case 2: stop_timer(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MainWindow::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool MainWindow::qt_property( int id, int f, QVariant* v)
{
    char buf[20]; buf[0]='\0';
    return QWidget::qt_property( id, f, v);
}
#endif // QT_NO_PROPERTIES
