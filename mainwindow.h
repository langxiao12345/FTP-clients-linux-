#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>

class QFtp;
class QFile;
class QUrlInfo;
class QTreeWidgetItem;


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QFtp *ftp;
    QHash<QString, bool> isDirectory;//�����洢һ��·���Ƿ�ΪĿ¼����Ϣ
    QString currentPath;//�����洢���ڵ�·��
    QFile *file;//������ʾ���ص��ļ�

private slots:
    void ftpCommandStarted(int);
    void ftpCommandFinished(int, bool);
    void updateDataTransferProgress(qint64, qint64);
    void addToList(const QUrlInfo &urlInfo);
    void processItem(QTreeWidgetItem*, int);
    void on_connectButton_clicked();
    void on_cdToParentButton_clicked();
    void on_downloadButton_clicked();
};

#endif // MAINWINDOW_H
