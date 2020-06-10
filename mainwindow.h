#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_actionQuit_triggered();

    void on_SearchLine_textChanged(const QString &arg1);

    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
    void names_output(QString filename);
    QStringList words;
};
#endif // MAINWINDOW_H
