#include "mainwindow.h"
#include "ui_mainwindow.h"

// MainWindow
//------------------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(ConnectDB())
    {
        ShowAllItems();
    }

    ui->btnSave->hide();
    ui->btnCancel->hide();

    ui->lineSearch->setMaxLength(80);
    ui->lineTitle->setMaxLength(80);

    currentItem = ui->listNames->item(0);
    on_listNames_itemClicked(currentItem);
    ui->listNames->setCurrentRow(0);
}
//------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete db;
    delete currentItem;
    delete ui;
}
//------------------------------------------------------------------------------------------------------------
bool MainWindow::ConnectDB()
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName("../db/DataBase.db");

    if(db->open())
    {
        return true;
    }

    ui->statusbar->showMessage("Error, opening database falied! " + db->lastError().text());

    return false;
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::ShowAllItems()
{
    if (db->open())
    {
        ui->listNames->clear();

        QSqlQuery query;
        query.prepare("SELECT * FROM DATA");

        if (query.exec())
        {
            while (query.next())
            {
                QString id = query.value(0).toString();
                QString title = query.value(1).toString();

                if (title.size() >= 30)
                {
                    title = title.left(27) + "...";
                }

                ui->listNames->addItem(id + " " + title);
            }
        }
    }
}
//------------------------------------------------------------------------------------------------------------
bool MainWindow::ShowMessageBox(QString question)
{
    QMessageBox msgBox;
    msgBox.setText(question);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes)
    {
        return true;
    }

    return false;
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::on_btnInsert_clicked()
{
    currentNumer = ui->listNames->currentRow();

    ui->btnClear->hide();
    ui->btnDelete->hide();
    ui->btnInsert->hide();
    ui->btnUpdate->hide();

    ui->lineID->clear();
    ui->lineTitle->clear();
    ui->listNames->clear();

    ui->planText->clear();

    ui->lineSearch->setReadOnly(true);

    ui->btnSave->show();
    ui->btnCancel->show();
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::on_btnUpdate_clicked()
{
    if (db->open())
    {
        if(ShowMessageBox("Are you sure want to update item?"))
        {
            QString currentID = ui->lineID->text();
            QString newTitle = ui->lineTitle->text();
            QString newText = ui->planText->toPlainText();

            QSqlQuery query;
            query.prepare("UPDATE DATA SET title = :newTitle, text = :newText WHERE id = :currentID");
            query.bindValue(":newTitle", newTitle);
            query.bindValue(":newText", newText);
            query.bindValue(":currentID", currentID);

            if (query.exec())
            {
                int16_t row = ui->listNames->currentRow();

                if(ui->lineSearch->text() != "")
                {
                    on_lineSearch_textChanged(ui->lineSearch->text());
                }
                else
                {
                    ShowAllItems();
                }

                ui->listNames->setCurrentRow(row);

                ui->statusbar->showMessage("Item was successfully updated");
            }
            else
            {
                ui->statusbar->showMessage("Error, update was failed!");
            }
        }
    }
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::on_btnClear_clicked()
{
    ui->lineTitle->clear();
    ui->planText->clear();
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::on_btnDelete_clicked()
{
    if (db->open())
    {
        if(ShowMessageBox("Are you sure want to delete item?"))
        {
            QString currentID = ui->lineID->text();

            QSqlQuery query;
            query.prepare("DELETE FROM DATA WHERE id = :currentID");
            query.bindValue(":currentID", currentID);

            if(query.exec())
            {
                int16_t row = 0;
                if(ui->listNames->currentRow() != 0)
                {
                    row = ui->listNames->currentRow() - 1;
                }

                if(ui->lineSearch->text() != "")
                {
                    on_lineSearch_textChanged(ui->lineSearch->text());
                }
                else
                {
                    ShowAllItems();
                }

                ui->listNames->setCurrentRow(row);
                currentItem = ui->listNames->currentItem();
                on_listNames_itemClicked(currentItem);

                ui->statusbar->showMessage("Item was successfully deleted!");
            }
            else
            {
                ui->statusbar->showMessage("Error, deletion failed!");
            }
        }

    }
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::on_btnSave_clicked()
{
    if (db->open())
    {
        QString newTitle = ui->lineTitle->text();

        if(ShowMessageBox("Are you sure want to add item " + newTitle + "?"))
        {
            QString newText = ui->planText->toPlainText();

            QSqlQuery query;
            query.prepare("INSERT INTO DATA (title, text) VALUES (:newTitle, :newText)");
            query.bindValue(":newTitle", newTitle);
            query.bindValue(":newText", newText);

            if(query.exec())
            {
                ui->btnSave->hide();
                ui->btnCancel->hide();

                ui->btnClear->show();
                ui->btnDelete->show();
                ui->btnInsert->show();
                ui->btnUpdate->show();

                if(ui->lineSearch->text() != "")
                {
                    on_lineSearch_textChanged(ui->lineSearch->text());
                }
                else
                {
                    ShowAllItems();
                }

                currentItem = ui->listNames->item(ui->listNames->count() - 1);
                on_listNames_itemClicked(currentItem);
                ui->listNames->setCurrentRow(ui->listNames->count() - 1);

                ui->lineSearch->setReadOnly(false);

                ui->statusbar->showMessage("New item was successfully added!");
            }
            else
            {
                ui->statusbar->showMessage("Error, addition was failed!");
            }
        }
    }
}

//------------------------------------------------------------------------------------------------------------
void MainWindow::on_btnCancel_clicked()
{
    if(ShowMessageBox("Are you sure want to cancel the changes?"))
    {

        ui->btnSave->hide();
        ui->btnCancel->hide();

        ui->btnClear->show();
        ui->btnDelete->show();
        ui->btnInsert->show();
        ui->btnUpdate->show();

        if(ui->lineSearch->text() != "")
        {
            on_lineSearch_textChanged(ui->lineSearch->text());
        }
        else
        {
            ShowAllItems();
        }

        currentItem = ui->listNames->item(currentNumer);
        on_listNames_itemClicked(currentItem);
        ui->listNames->setCurrentRow(currentNumer);

        ui->lineSearch->setReadOnly(false);
    }
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::on_lineSearch_textChanged(const QString &arg1)
{
    if (db->open())
    {
        if(arg1 != "")
        { 
            QSqlQuery query;
            query.prepare("SELECT * FROM DATA WHERE title LIKE :currentTitle OR id LIKE :currentID");
            query.bindValue(":currentTitle", "%" + arg1 + "%");
            query.bindValue(":currentID", arg1 + "%");

            if (query.exec())
            {
                ui->listNames->clear();

                while (query.next())
                {
                    QString id = query.value(0).toString();
                    QString title = query.value(1).toString();
                    QString date = query.value(3).toString();

                    if (title.size() >= 30)
                    {
                        title = title.left(27) + "...";
                    }

                    ui->listNames->addItem(id + " " + title + QString(48 - id.length() - title.length() - date.length(), ' ') + date);
                }

                if (ui->listNames->count() > 0)
                {
                    ui->statusbar->showMessage("Items containing " + arg1 + " were successfully found!");

                    currentItem = ui->listNames->item(0);
                    on_listNames_itemClicked(currentItem);
                    ui->listNames->setCurrentRow(0);
                }
                else
                {
                    ui->statusbar->showMessage("No items found containing " + arg1 + " in the title.");
                }
            }
            else
            {
                ui->statusbar->showMessage("Error executing the query!");
            }

            if(arg1.length() >= 80)
            {
                ui->statusbar->showMessage("The maximum number of characters reached!");
            }
        }
        else
        {
            ShowAllItems();

            currentItem = ui->listNames->item(0);
            on_listNames_itemClicked(currentItem);
            ui->listNames->setCurrentRow(0);
        }
    }
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::on_listNames_itemClicked(QListWidgetItem *item)
{
    currentItem = item;

    if (db->open())
    {
        QString currentID = item->text().left(item->text().indexOf(' '));

        QSqlQuery query;
        query.prepare("SELECT * FROM DATA WHERE id = :currentID");
        query.bindValue(":currentID", currentID);

        if (query.exec() && query.next())
        {
            QString id = query.value(0).toString();
            QString title = query.value(1).toString();
            QString text = query.value(2).toString();

            ui->lineID->setText(id);
            ui->lineTitle->setText(title);
            ui->planText->setPlainText(text);

            ui->statusbar->showMessage("Item was successfully opened!");
        }
        else
        {
            ui->statusbar->showMessage("Error, no such current item!");
        }
    }
}
//------------------------------------------------------------------------------------------------------------
