#ifndef C_DRAGQTREEWIDGET_H
#define C_DRAGQTREEWIDGET_H

#include <QTreeWidget>
#include <QPoint>
class QTreeWidgetItem;
//==========================  C_DragQTreeWidget ===================================
class C_DragQTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit C_DragQTreeWidget(QWidget *parent = 0);
    void             setMimeType(const QString& mimeType);
    void             setIconPathMimeType(const QString& path);
    void             mousePressEvent(QMouseEvent *event);
    void             mouseMoveEvent(QMouseEvent *event);
    QTreeWidgetItem *getFirstSelectedItem();
signals:
    void Sign_giveMeDatas(QString &data, QTreeWidgetItem *item);

public slots:

private:
  QString m_mimeType;
  QString m_mimeTypeIconPath;
  QPoint  m_startDragPos;

};

#endif // C_DRAGQTREEWIDGET_H
