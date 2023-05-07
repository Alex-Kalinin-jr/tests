#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  QSqlDatabase dBase_;
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H

// CREATE TABLE question(id INT NOT NULL AUTO_INCREMENT, category CHAR(2) NOT
// NULL,
//                      text VARCHAR(256) NOT NULL, PRIMARY KEY(id));

// CREATE TABLE answer(id BIGINT NOT NULL AUTO_INCREMENT, question_id INT NOT
// NULL,
//                    text VARCHAR(256) NOT NULL,
//                    is_it_right_answer BOOL NOT NULL, PRIMARY KEY(id),
//                    FOREIGN KEY(question_id) REFERENCES question(id),
//                    index pn_user_index(`question_id`));

// insert into question
//    value(1, 'aa', 'Test question. Should be 4 variants. D is the answer.');
// insert into question value(
//    2, 'aa', 'Test question 2. Should be 4 variants. A, B, D are answers.');
// insert into question value(
//    3, 'aa', 'Test question 3. Should be 4 variants. B and D are answers.');

// insert into answer values(0, 1, 'A', 0), (0, 1, 'B', 0), (0, 1, 'C', 0),
//    (0, 1, 'D', 1);
// insert into answer values(0, 2, 'A2', 1), (0, 2, 'B2', 1), (0, 2, 'C2', 1),
//    (0, 2, 'D2', 0);
// insert into answer values(0, 3, 'A3', 0), (0, 3, 'B3', 1), (0, 3, 'C3', 0),
//    (0, 3, 'D3', 1);

// select * from question join answer on question.id = 2 and question.id =
// answer.question_id and answer.is_it_right_answer = 1;
