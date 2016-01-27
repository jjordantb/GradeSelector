#include <QApplication>
#include <QFile>
#include <QLatin1String>

#include "GMain.h"

int main(int argv, char * argc[])
{
  QApplication app(argv, argc);

  QFile file("resources/qstyle.css");
  file.open(QFile::ReadOnly);
  QString styleSheet = QLatin1String(file.readAll());
  app.setStyleSheet(styleSheet);

  GMain window;
  window.setWindowTitle("Grader");
  window.show();

  return app.exec();
}
