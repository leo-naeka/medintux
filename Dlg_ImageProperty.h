/****************************************************************************
** Form interface generated from reading ui file 'Dlg_ImageProperty.ui'
**
** Created: mer. mai 4 22:17:02 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_IMAGEPROPERTY_H
#define DLG_IMAGEPROPERTY_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
class QSlider;

class Dlg_ImageProperty : public QDialog
{
    Q_OBJECT

public:
    Dlg_ImageProperty( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_ImageProperty();

    QPushButton* pushButton_Annuler;
    QPushButton* pushButton_Ok;
    QPushButton* pushButton_Save;
    QLabel* textLabel1;
    QLineEdit* lineEdit_width;
    QLabel* textLabel1_2;
    QLineEdit* lineEdit_height;
    QLabel* textLabel_Name;
    QTextEdit* textEdit_FileName;
    QPushButton* pushButton_VoirSource;
    QLabel* pixmapLabel_Image;
    QSlider* slider_Width;
    QSlider* slider_height;

protected:
    QGridLayout* Dlg_ImagePropertyLayout;
    QSpacerItem* spacer3;
    QGridLayout* layout9;
    QHBoxLayout* layout3;
    QSpacerItem* spacer1;
    QHBoxLayout* layout3_2;
    QSpacerItem* spacer1_2;
    QGridLayout* layout6;
    QGridLayout* layout7;

protected slots:
    virtual void languageChange();

};

#endif // DLG_IMAGEPROPERTY_H
