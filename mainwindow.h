#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QGridLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QSqlDatabase>
#include <set>

#include "paramswidget.h"
#include "writinggui.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class WritingGui;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public slots:
  void ChangeConnectionParams();

 private slots:
  bool Ask();
  void Answer();
  void ChangeCategory(int index);
  void ChooseSession();
  void WriteAnswerToDb();

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void ClearQuestion();
  QString GetCategoryId(const int &);
  void CopyWidgetData(QComboBox *);

 protected:
  QComboBox *categoryBox_;

 private:
  int layoutManager_ = 0;

  /************category handling section************/
  // linux, c++, sql, qt.
  // For expanding do not forget to add a record to
  // QComboBox in void MainWindow::setCategoryArea()
  std::vector<QString> categoryVector_{"aa", "ab", "ac", "ad"};
  QStringList categoryBoxVector_{"linux", "c++", "sql", "qt"};

  int currentCategory_ = 0;
  std::vector<std::vector<int>> askedChecker_;
  /************end of category handling section************/

  WritingGui *writingWidget_;
  QSqlDatabase dBase_;
  // widget with params.
  // when press ok -> validate and fill dBaseData
  // dBaseData is used in setConnection...
  ParamsWidget *paramsWidget_;
  QStringList dBaseConnectionData_;

  Ui::MainWindow *ui;
  QGridLayout *layout_;
  QPushButton *go_;
  QPushButton *answer_;

  /************menu widgets************/
  QMenuBar *menuBar_;
  QMenu *menu_;
  QAction *aConnect_;
  QAction *aCreateQuestion_;
  QAction *aCreateCategory_;
  /************end of menu widgets************/

  bool setConnection();
  void setCustomLayout();
  void CreateActions();
  void setCategoryArea();
  // checks an appropriate vector in "askedChecker_" accordingly to
  // "currentCategory_" and if it is empty, tries to fill it with ids of
  // possible questions.
  void RefillQuestions();
  // checks an appropriate vector in "askedChecker_", erases one value from it
  // and returns this value.
  int GenerateQuestionId();
  void WriteToDb(QStringList &answer);
};
#endif  // MAINWINDOW_H
