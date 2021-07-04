#pragma once

#include <QMainWindow>
#include <QPointer>
#include <QProcess>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Application; }
QT_END_NAMESPACE

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();

    bool isRunning();

private slots:

    void writeSettings();
    void readSettings();

    void on_pbStart_clicked();
    void on_pbStop_clicked();

    void on_processErrorOccurred(QProcess::ProcessError err);
    void on_processStateChanged(QProcess::ProcessState st);
    void on_readyReadStandardOutput();
    void on_readyReadStandardError();
    void on_clearLog();

    void on_hearBeat();

private:
    void syncUIWithProcessState();

private:
    Ui::Application *ui;
    QPointer<QProcess> m_currentProcess;
    QAction* m_actionClearLog;
    QTimer m_hearbeatTimer;
};
