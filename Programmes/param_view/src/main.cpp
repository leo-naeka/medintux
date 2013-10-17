
#include <qapplication.h>
#include "CApp.h"
#include "C_Dlg_ParamView.h"
int main( int argc, char ** argv ) {
    CApp a( argc, argv );
    C_Dlg_ParamView * mw = new C_Dlg_ParamView();
    mw->setCaption( "param_view" );
    mw->show();
    a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
    return a.exec();
}
