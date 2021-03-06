#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QTextBrowser>
#include "api/youdaoapi.h"
#include "windows/float_browser.h"
#include "windows/float_button.h"
#include <qclipboard.h>
#include "SQL/sqlite.h"
#include <windows/about.h>
#include <QCloseEvent>
#include "systemtrayicon.h"
#include "windows/hyaline_window.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "windows/settings_window.h"
//#include <tesseract/baseapi.h>

//using namespace tesseract;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLineEdit *input;

    QPushButton *query_button, *exchange_language, *about, *test_button;
    //QPushButton *derive;
    QComboBox *src_language, *des_language;
    QTextBrowser *browser;
    QClipboard *clipboard;
    Float_Button *float_button;
    Float_Browser *float_browser;
    Hyaline_Window *hyaline_window;
    About *about_window;
    QString src_word;
    QString des_word;
    enum Requestor {Mainwindow, Float_button, Float_browser, ocr} who_query;
    YoudaoAPI *youdao_api;
    SQLite sqlite;
    void query();
    void show_result();
    int button_time;
    void show_about();
    //void derive_words();
    SystemTrayIcon *tray_icon;
    //TessBaseAPI *ocr_ins;

private:
    void build_GUI();
    void init_language();
    void signals_slots();
    bool recognize_image();
    bool clipboard_flag;
    QPushButton *settings_button;
    QHBoxLayout *layout_root;
    QVBoxLayout *layout_view, *layout_button;
    SettingsWindow *settings_window;

private slots:
    void get_result(QByteArray re);
    void closeEvent(QCloseEvent *event);
    void tray_icon_actived(QSystemTrayIcon::ActivationReason reason);

public slots:
    void hide_float();
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
