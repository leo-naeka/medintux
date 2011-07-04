#ifndef C_QWEBVIEW_H
#define C_QWEBVIEW_H

#include <QWebView>
#include <QWebPage>
#include <QToolBar>
#include <QAction>

class C_QWebView;
//============================================== C_QWebPage =====================================================
class C_QWebPage : public QWebPage
{
    Q_OBJECT
public:
    explicit          C_QWebPage(QObject *parent = 0);
    virtual QWebPage *createWindow ( QWebPage::WebWindowType type );
    C_QWebView       *m_pC_QWebViewParent;

signals:
public slots:

};

//============================================== C_QWebView =====================================================
class C_QWebView : public QWebView
{
    Q_OBJECT
public:
    explicit          C_QWebView(QWidget *parent = 0);
    C_QWebPage        *m_pC_QWebPage;
    QToolBar          *m_ToolBar;
    QAction           *m_action_Back;
    QAction           *m_action_Reload;
    QAction           *m_action_Forward;
    QAction           *m_action_Stop;
signals:
public slots:

};

#endif // C_QWEBVIEW_H
