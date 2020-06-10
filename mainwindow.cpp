#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    names_output("C://Qt/PROJECTS/journalPeople.txt");
    // Выводим содержимое файла на экран
    ui->TablePeople->addItems(words);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Сигнал на получение записей из файла
void MainWindow::names_output(QString fileName)
{

 // Создаём объект типа QFile
 QFile inFile(fileName);

     // С помощью метода open() открываем файл в режиме чтения
    if(!inFile.open(QIODevice::ReadOnly))
    {
        // Если файл не найден, то выводим предупреждение
        qWarning("Cannot open file for reading");
        return;
    }

    // Создаём входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream read(&inFile);
    read.setCodec("UTF-8");

    QString line;

    // Очищаем старые данные
    words.clear();
    ui->TablePeople->clear();    

    // Считываем файл строка за строкой
    while (!read.atEnd())
    {
        line = read.readLine();
        // И добавляем строки в переменную words
        words.append(line);
    }

    inFile.close();
}



// Сигнал при введении даты или имени в ячейку поиска
void MainWindow::on_SearchLine_textChanged(const QString &arg1)
{
    // Метод фильтра выражения
    QRegExp find(arg1);
    // Очищаем ячейку от всех ненужных записей
    ui->TablePeople->clear();
    // Наполняем эту ячейку записами, соответсвующими фильтру поиска
    ui->TablePeople->addItems(words.filter(find));
}



// Сигнал при нажатии на кнопку добавления записи
void MainWindow::on_addButton_clicked()
{
    // Создаём второе диалоговое окно
    secondWindow addWindow;
    // Даём ему значение true
    addWindow.setModal(true);
    // Успешно выполняем действия в нём
    addWindow.exec();


    // Выводим обновлённый список записей в поле
    names_output("C://Qt/PROJECTS/journalPeople.txt");
    ui->TablePeople->addItems(words);
}
