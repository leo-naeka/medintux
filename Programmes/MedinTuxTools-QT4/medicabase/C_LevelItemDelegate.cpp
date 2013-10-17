#include "C_LevelItemDelegate.h"
#include <QApplication>

//================================ C_LevelItemDelegate =====================================================

C_LevelItemDelegate::C_LevelItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}
/*
QWidget *C_LevelItemDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/ * option * /,
    const QModelIndex &/ * index * /) const
{
    QProgressBar  *editor = new QProgressBar(parent);
    editor->setValue(m_level);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}
void C_LevelItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QProgressBar *spinBox = static_cast<QProgressBar*>(editor);
    //spinBox->interpretText();
    int value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}
void C_LevelItemDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QProgressBar *spinBox = static_cast<QProgressBar*>(editor);
    spinBox->setValue(value);
}
void C_LevelItemDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/ * index * /) const
{
    editor->setGeometry(option.rect);
}
*/
void C_LevelItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,  const QModelIndex &index) const
 {  bool drawProgress=false;
    if (index.column() == 1 )             // colonne reservee au progress
       { QString progressText   = index.data().toString();
         if (progressText.length())       // ne dessiner le progress que si i y a un contenu valide
            { QStyleOptionProgressBar progressBarOption;
              QChar type                      = progressText[0];              //  A0 A1 A2 A3 A4   S1 S2 S3 S4
              int  progress                   = progressText.mid(1).toInt();
              drawProgress                    = true;
              progressBarOption.rect          = option.rect;
              progressBarOption.minimum       = 0;
              if (type=='A')
                 { progressBarOption.maximum  = 4;
                  switch(progress)
                  { case 0: progressText = tr("ASMR nul");        break;
                    case 1: progressText = tr("ASMR mineur");     break;
                    case 2: progressText = tr("ASMR modéré");     break;
                    case 3: progressText = tr("ASMR important");  break;
                    case 4: progressText = tr("ASMR majeur");     break;
                  }
                 }
              else if (type=='S')
                 { progressBarOption.maximum  = 3;
                   --progress;    // ramener le 1 2 3 4 a 0 1 2 3
                   switch(progress)
                   { case 0: progressText = tr("SMR insuffisant");break;
                     case 1: progressText = tr("SMR faible");     break;
                     case 2: progressText = tr("SMR modéré");     break;
                     case 3: progressText = tr("SMR important");  break;
                   }
                 }
              progressBarOption.progress    = progress;
              progressBarOption.text        = progressText;
              progressBarOption.textVisible = true;
              QApplication::style()->drawControl(QStyle::CE_ProgressBar,  &progressBarOption, painter);
            }
      }
    if (!drawProgress)  QStyledItemDelegate::paint(painter, option, index);
 }
