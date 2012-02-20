//Automatic sig/slot connections

#include <QApplication>
#include "DlgTimeCalc.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	DlgTimeCalc dialog;
	dialog.show();
    
    return app.exec();
}