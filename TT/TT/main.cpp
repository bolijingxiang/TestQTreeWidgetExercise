#include "TT.h"
#include <QtWidgets/QApplication>
#include "ExerciseWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ExerciseWidget w;
	w.show();
	return a.exec();
}
