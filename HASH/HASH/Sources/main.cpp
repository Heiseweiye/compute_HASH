#include "Headers/HASH.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HASH w;
	w.setWindowTitle(QString("HASH系统"));
	w.show();
	return a.exec();
}