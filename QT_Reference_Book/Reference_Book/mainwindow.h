#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QListWidgetItem>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>

//------------------------------------------------------------------------------------------------------------
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE
//------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnInsert_clicked();
    void on_btnUpdate_clicked();
    void on_btnClear_clicked();
    void on_btnDelete_clicked();
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

    void on_lineSearch_textChanged(const QString &arg1);
    void on_listNames_itemClicked(QListWidgetItem *item);

private:
    bool ConnectDB();
    bool ShowMessageBox(QString question);

    void ShowAllItems();

    Ui::MainWindow *ui;

    QSqlDatabase *db;

    QListWidgetItem *currentItem;

    int16_t currentNumer;
};
//------------------------------------------------------------------------------------------------------------

#endif // MAINWINDOW_H
