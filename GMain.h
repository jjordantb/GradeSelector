#ifndef GMAIN_H
#define GMAIN_H

#include <QMainWindow>
#include <vector>
#include <string>

#include "GDialog.h"

class QListWidget;
class QPushButton;
class QLabel;
class GDialog;

class GMain : public QMainWindow
{
  Q_OBJECT

public:
  GMain();

private:
  QListWidget *listWidget;
  QPushButton *addButton;
  QPushButton *removeButton;
  QPushButton *quitButton;
  GDialog *dialog;

private slots:
  void reciveClasses(const QString&, const QString&);
  void addClass();
  void removeClass();

};

#endif //GMAIN_H
