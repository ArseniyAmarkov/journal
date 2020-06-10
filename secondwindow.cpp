#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

secondWindow::secondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondWindow)
{
    ui->setupUi(this);
}

secondWindow::~secondWindow()
{
    delete ui;
}

// Сигнал при нажатии ОК
void secondWindow::on_buttonBox_accepted()
{
    // Получаем данные по записи
    QString data = ui->dataLine->text();
    QString name = ui->nameLine->text();
    QString birthday = ui->birthdayLine->text();
    QString telephone = ui->telephoneLine->text();
    QString address = ui->addressLine->text();
    // и переводим всё в одну строку
    QString line = data + " " + name + " " + birthday + " " + telephone + " " + address +"\n";

    // Перекидываем строку в конец файла

    // Создаём переменную типа QFile
    QFile inFile("C://Qt/PROJECTS/journalPeople.txt");

    // Если файл успешно открывается для записи
    if(inFile.open(QIODevice::Append | QIODevice::Text)) {
        // то создаём объект типа QTextStream
        QTextStream write(&inFile);
        write.setCodec("UTF-8");
        // и посылаем строку для записи
        write << line;
       }

    else {
        qWarning("Could not open file");
    }

    inFile.close();
}
