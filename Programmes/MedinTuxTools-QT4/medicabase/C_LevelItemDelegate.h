#ifndef C_LEVELITEMDELEGATE_H
#define C_LEVELITEMDELEGATE_H
#include <QStyledItemDelegate>
//================================ C_LevelItemDelegate =====================================================
    class C_LevelItemDelegate : public QStyledItemDelegate
    {
        Q_OBJECT

    public:
        C_LevelItemDelegate(QObject *parent = 0);
        /*
        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;

        void setEditorData(QWidget *editor, const QModelIndex &index) const;
        void setModelData(QWidget *editor, QAbstractItemModel *model,
                          const QModelIndex &index) const;

        void updateEditorGeometry(QWidget *editor,
            const QStyleOptionViewItem &option, const QModelIndex &index) const;
        */
        void paint(QPainter *painter, const QStyleOptionViewItem &option,  const QModelIndex &index) const;

    };
#endif // C_LEVELITEMDELEGATE_H
