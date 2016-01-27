#include <QtGui>
#include "GDialog.h"

GDialog::GDialog(QWidget *parent) : QDialog(parent)
{
  label1 = new QLabel("Course Numer: ");
  label2 = new QLabel("Grade: ");

  classNumber = new QLineEdit();

  sendButton = new QPushButton("Add");
  cancelButton = new QPushButton("Cancel");

  gradeSelect = new QComboBox();
  gradeSelect->addItem("A+");
  gradeSelect->addItem("A");
  gradeSelect->addItem("A-");
  gradeSelect->addItem("B+");
  gradeSelect->addItem("B");
  gradeSelect->addItem("B-");
  gradeSelect->addItem("C+");
  gradeSelect->addItem("C");
  gradeSelect->addItem("C-");
  gradeSelect->addItem("D+");
  gradeSelect->addItem("D");
  gradeSelect->addItem("D-");
  gradeSelect->addItem("F");

  connect(sendButton, SIGNAL(clicked()), this, SLOT(sendClicked()));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

  QVBoxLayout *mainLayout = new QVBoxLayout();
  QHBoxLayout *top = new QHBoxLayout();
  QHBoxLayout *mid = new QHBoxLayout();
  QHBoxLayout *bottom = new QHBoxLayout();

  mainLayout->addLayout(top);
  mainLayout->addLayout(mid);
  mainLayout->addLayout(bottom);

  top->addWidget(label1);
  top->addWidget(classNumber);
  mid->addWidget(label2);
  mid->addWidget(gradeSelect);
  bottom->addWidget(sendButton);
  bottom->addWidget(cancelButton);

  setLayout(mainLayout);
  setWindowTitle("Add Class");

}

void GDialog::sendClicked()
{
  QString cn = classNumber->text();
  QString grade = gradeSelect->currentText();

  emit sendClass(cn, grade);
}
