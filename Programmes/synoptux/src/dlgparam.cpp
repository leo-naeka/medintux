#include "dlgparam.h"
#include "ui_dlgparam.h"
#include <QFile>
#include <QMessageBox>

#define NOM_APPLI "SynopTux"

//--------------------------------- DlgParam --------------------------------------------------------------------------------
DlgParam::DlgParam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgParam)
{
    ui->setupUi(this);

    connect (ui->pushButton_valider,    SIGNAL(clicked()),  this, SLOT (EcrireParam()) );
    connect (ui->pushButton_annuler,    SIGNAL(clicked()),  this, SLOT (close()));
}

//--------------------------------- ~DlgParam --------------------------------------------------------------------------------
DlgParam::~DlgParam()
{
    delete ui;
}

//--------------------------------- changeEvent --------------------------------------------------------------------------------
void DlgParam::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//--------------------------------- ChargeParam --------------------------------------------------------------------------------
void   DlgParam::ChargeParam(QString typeParam)
{
    QString     zParam;
    QFile       *FilePARAM;
    if (typeParam == "CSS")
        {
        nomficPARAM = QApplication::applicationDirPath()+ "/Ressources/synoptux.css";
        setWindowTitle("Mise en forme des objets" );
        setWindowIcon(QIcon(":/images/css.png"));
        }
    else
        {
        nomficPARAM = QApplication::applicationDirPath()+ "/synoptux.ini";
        setWindowTitle("Paramètres généraux" );
        setWindowIcon(QIcon(":/images/ini.png"));
        }

    FilePARAM = new QFile(nomficPARAM);
    if (!FilePARAM->open(QIODevice::ReadOnly)) {
        QMessageBox::warning(0,NOM_APPLI,"Le fichier " + nomficPARAM + tr(" ne peut pas être ouvert !"));
        delete FilePARAM;
        return ;
        }
    zParam = FilePARAM->readAll();
    ui->textEdit_param->setText(zParam);
    FilePARAM->close();
    delete FilePARAM;
    return ;
}
//--------------------------------- EcrireParam --------------------------------------------------------------------------------
void DlgParam::EcrireParam()
{
    QByteArray zParam     = ui->textEdit_param->document()->toPlainText().toLatin1();
    QFile *FilePARAM;
    FilePARAM = new QFile(nomficPARAM);
    if (!FilePARAM->open(QIODevice::WriteOnly)) {
        QMessageBox::warning(0,NOM_APPLI,"Le fichier " + nomficPARAM + tr(" ne peut pas être ouvert !"));
        }
    if (FilePARAM->write(zParam) <= 0) {
        QMessageBox::warning(0,NOM_APPLI,"Le fichier " + nomficPARAM + tr(" ne peut pas être mis à jour !"));
        }
    FilePARAM->close();
    close();
}
