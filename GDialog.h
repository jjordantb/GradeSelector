#ifndef GDIALOG_H
#define GDIALOG_H

#include <QDialog>

class QPushButton;
class QLabel;
class QComboBox;
class QLineEdit;

class GDialog : public QDialog
{
  Q_OBJECT

public:
  GDialog(QWidget *parent = 0);

signals:
  void sendClass(const QString&, const QString&);

private slots:
  void sendClicked();

private:
  QLabel *label1;
  QLabel *label2;
  QComboBox *gradeSelect;
  QLineEdit *classNumber;
  QPushButton *sendButton;
  QPushButton *cancelButton;

};

#endif //GDIALOG_H
