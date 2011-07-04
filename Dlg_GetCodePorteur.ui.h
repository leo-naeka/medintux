/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/


void Dlg_GetCodePorteur::init()
{QString path_img = G_pCApp->m_PathAppli + "Images" + QDir::separator();
 labelIconePs->setPixmap ( QPixmap(path_img +"Carte_CPS.png"));
 lineEditGetCode->setFocus();
}

void Dlg_GetCodePorteur::pushButtonOk_clicked()
{accept();
}

void Dlg_GetCodePorteur::pushButtonCancel_clicked()
{reject();
}
