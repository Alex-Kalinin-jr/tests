#include "writinggui.h"

#include <QCheckBox>
#include <QLabel>

DialogGui::DialogGui(QWidget *parent) : QDialog(parent) {
  ok_ = new QPushButton("Write", this);
  cancel_ = new QPushButton("Cancel", this);
  connect(ok_, SIGNAL(clicked()), SLOT(accept()));
  connect(cancel_, SIGNAL(clicked()), SLOT(reject()));
  layout_ = new QGridLayout(this);
  layout_->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  row_ = 0;
  col_ = 0;
}

WritingGui::WritingGui(QWidget *parent) : DialogGui(parent) {
  question_ = new QTextEdit(this);
  category_ = new QComboBox(this);
  setLayout(layout_);
  PutQuestionArea();
  addAnswer_ = new QPushButton("+", this);
  layout_->addWidget(addAnswer_, row_++, col_);
  connect(addAnswer_, &QPushButton::clicked, this, &WritingGui::AddOneAnsw);
  firstAnswRow_ = row_;
  AddOneAnsw();
}

void WritingGui::AddOneAnsw() {
  layout_->removeWidget(layout_->itemAtPosition(--row_, col_)->widget());
  layout_->addWidget(
      new QLabel(QString("Answ %1").arg(QString::number(row_ - 2)), this), row_,
      col_++);
  layout_->addWidget(new QLabel("True/false", this), row_++, col_--);

  layout_->addWidget(new QTextEdit(), row_, col_++);
  layout_->addWidget(new QCheckBox(), row_++, col_--);
  layout_->addWidget(addAnswer_, row_++, col_);
}

QStringList WritingGui::GetFields() {
  QStringList answ;
  int row = questRow_;
  int col = 0;
  QWidget *temp_1(layout_->itemAtPosition(row, col++)->widget());
  QTextEdit *record(qobject_cast<QTextEdit *>(temp_1));
  if (!record) {
    return answ;
  }
  QString answText = record->toPlainText();
  answText.replace('\t', "  ");
  answ << answText;
  temp_1 = layout_->itemAtPosition(row++, col--)->widget();
  QComboBox *category(qobject_cast<QComboBox *>(temp_1));
  if (category) {
    MainWindow *categorySender = qobject_cast<MainWindow *>(parent());
    if (categorySender) {
      answ << categorySender->GetCategoryId(category_->currentIndex());
    }

    row = firstAnswRow_;
    do {
      QLayoutItem *buffItem = layout_->itemAtPosition(row, col++);
      if (!buffItem) break;
      QWidget *temp_2(buffItem->widget());
      QTextEdit *recordAnsw = qobject_cast<QTextEdit *>(temp_2);
      if (recordAnsw == nullptr) break;
      answText = recordAnsw->toPlainText();
      answText.replace('\t', "  ");
      answ << answText;
      temp_2 = layout_->itemAtPosition(row++, col--)->widget();
      QCheckBox *isItRight(qobject_cast<QCheckBox *>(temp_2));
      QString buffStr;
      buffStr = isItRight->QAbstractButton::isChecked() ? "1" : "0";
      answ << buffStr;
      ++row;
      col = 0;
    } while (1);
  }
  return answ;
}

void WritingGui::PutQuestionArea() {
  layout_->addWidget(new QLabel("Question text", this), row_, col_++);
  layout_->addWidget(new QLabel("Category", this), row_++, col_--);
  questRow_ = row_;
  layout_->addWidget(question_, row_, col_++);
  layout_->addWidget(category_, row_++, col_--);
  layout_->addWidget(ok_, row_, col_++);
  layout_->addWidget(cancel_, row_++, col_--);
}

NewCategoryGui::NewCategoryGui(QWidget *parent) : DialogGui(parent) {
  setLayout(layout_);
  PutFieldsOntoLayout();
}

QStringList NewCategoryGui::GetFields() {
  QStringList answ;
  answ << newCategory_->text() << codeForDb_->text();
  return answ;
}

void NewCategoryGui::PutFieldsOntoLayout() {
  layout_->addWidget(new QLabel("write category name", this), row_++, col_);
  newCategory_ = new QLineEdit(this);
  layout_->addWidget(newCategory_, row_++, col_);
  layout_->addWidget(new QLabel("write category code", this), row_++, col_);
  codeForDb_ = new QLineEdit(this);
  layout_->addWidget(codeForDb_, row_++, col_);
  layout_->addWidget(ok_, row_, col_++);
  layout_->addWidget(cancel_, row_++, col_--);
}
