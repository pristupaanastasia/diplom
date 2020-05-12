/****************************************************************************
** BitPaint meta object code from reading C++ file 'visual.h'
**
** Created: Mon May 11 21:47:24 2020
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "visual.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *BitPaint::className() const
{
    return "BitPaint";
}

QMetaObject *BitPaint::metaObj = 0;
static QMetaObjectCleanUp cleanUp_BitPaint( "BitPaint", &BitPaint::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString BitPaint::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "BitPaint", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString BitPaint::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "BitPaint", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* BitPaint::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"bitchange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "bitchange()", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"BitPaint", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_BitPaint.setMetaObject( metaObj );
    return metaObj;
}

void* BitPaint::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "BitPaint" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool BitPaint::qt_invoke( int _id, QUObject* _o )
{
    switch ( staticMetaObject()->localSlotIndex(
              metaObject()==staticMetaObject() ? _id : staticMetaObject()->findSlot(
				 metaObject()->slot(_id,TRUE)?metaObject()->slot(_id,TRUE)->name:0, TRUE ) ) )
    {
    case 0: bitchange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool BitPaint::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool BitPaint::qt_property( int id, int f, QVariant* v)
{
    char buf[20]; buf[0]='\0';
    return QWidget::qt_property( id, f, v);
}
#endif // QT_NO_PROPERTIES


const char *CannonField::className() const
{
    return "CannonField";
}

QMetaObject *CannonField::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CannonField( "CannonField", &CannonField::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CannonField::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CannonField", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CannonField::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CannonField", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CannonField::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pr_kadr", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"kadr_change", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pr_pal", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"pal_change", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "x_size", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"x_size_change", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "y_size", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"y_size_change", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "sil", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"sil_change", 1, param_slot_4 };
    static const QUMethod slot_5 = {"obzor", 0, 0 };
    static const QUMethod slot_6 = {"archiv", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "kadr_change(int)", &slot_0, QMetaData::Public },
	{ "pal_change(int)", &slot_1, QMetaData::Public },
	{ "x_size_change(int)", &slot_2, QMetaData::Public },
	{ "y_size_change(int)", &slot_3, QMetaData::Public },
	{ "sil_change(int)", &slot_4, QMetaData::Public },
	{ "obzor()", &slot_5, QMetaData::Public },
	{ "archiv()", &slot_6, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"text_kadr_change", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"text_pal_change", 1, param_signal_1 };
    static const QUMethod signal_2 = {"press_bit", 0, 0 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"obzor_x", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"obzor_y", 1, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "text_kadr_change(const QString&)", &signal_0, QMetaData::Public },
	{ "text_pal_change(const QString&)", &signal_1, QMetaData::Public },
	{ "press_bit()", &signal_2, QMetaData::Public },
	{ "obzor_x(int)", &signal_3, QMetaData::Public },
	{ "obzor_y(int)", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CannonField", parentObject,
	slot_tbl, 7,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CannonField.setMetaObject( metaObj );
    return metaObj;
}

void* CannonField::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CannonField" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL text_kadr_change
void CannonField::text_kadr_change( const QString& t0 )
{
    activate_signal(
      metaObject()!=staticMetaObject()?
      metaObject()->findSignal ( staticMetaObject()->signal(0,FALSE)->name, TRUE ) :
      staticMetaObject()->globalSignalIndex(0)
, t0 );
}

// SIGNAL text_pal_change
void CannonField::text_pal_change( const QString& t0 )
{
    activate_signal(
      metaObject()!=staticMetaObject()?
      metaObject()->findSignal ( staticMetaObject()->signal(1,FALSE)->name, TRUE ) :
      staticMetaObject()->globalSignalIndex(1)
, t0 );
}

// SIGNAL press_bit
void CannonField::press_bit()
{
    activate_signal(
      metaObject()!=staticMetaObject()?
      metaObject()->findSignal ( staticMetaObject()->signal(2,FALSE)->name, TRUE ) :
      staticMetaObject()->globalSignalIndex(2)
 );
}

// SIGNAL obzor_x
void CannonField::obzor_x( int t0 )
{
    activate_signal(
      metaObject()!=staticMetaObject()?
      metaObject()->findSignal ( staticMetaObject()->signal(3,FALSE)->name, TRUE ) :
      staticMetaObject()->globalSignalIndex(3)
, t0 );
}

// SIGNAL obzor_y
void CannonField::obzor_y( int t0 )
{
    activate_signal(
      metaObject()!=staticMetaObject()?
      metaObject()->findSignal ( staticMetaObject()->signal(4,FALSE)->name, TRUE ) :
      staticMetaObject()->globalSignalIndex(4)
, t0 );
}

bool CannonField::qt_invoke( int _id, QUObject* _o )
{
    switch ( staticMetaObject()->localSlotIndex(
              metaObject()==staticMetaObject() ? _id : staticMetaObject()->findSlot(
				 metaObject()->slot(_id,TRUE)?metaObject()->slot(_id,TRUE)->name:0, TRUE ) ) )
    {
    case 0: kadr_change((int)static_QUType_int.get(_o+1)); break;
    case 1: pal_change((int)static_QUType_int.get(_o+1)); break;
    case 2: x_size_change((int)static_QUType_int.get(_o+1)); break;
    case 3: y_size_change((int)static_QUType_int.get(_o+1)); break;
    case 4: sil_change((int)static_QUType_int.get(_o+1)); break;
    case 5: obzor(); break;
    case 6: archiv(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CannonField::qt_emit( int _id, QUObject* _o )
{
    switch ( staticMetaObject()->localSignalIndex(
              metaObject()==staticMetaObject() ? _id : staticMetaObject()->findSignal(
               metaObject()->signal(_id,TRUE)?metaObject()->signal(_id,TRUE)->name:0, TRUE ) ) )
    {
    case 0: text_kadr_change((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: text_pal_change((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: press_bit(); break;
    case 3: obzor_x((int)static_QUType_int.get(_o+1)); break;
    case 4: obzor_y((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CannonField::qt_property( int id, int f, QVariant* v)
{
    char buf[20]; buf[0]='\0';
    return QWidget::qt_property( id, f, v);
}
#endif // QT_NO_PROPERTIES
