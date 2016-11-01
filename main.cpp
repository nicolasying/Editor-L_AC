#include <QApplication>
#include <QWindow>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QtQuickControls2>
#include <QMenuBar>
#include <QObject>
#include <QString>
#include <QMainWindow>
#include <QQuickTextDocument>

//class MainWindow : public QMainWindow {
//    Q_OBJECT

//public:
//    MainWindow();

//protected:
//#ifndef QT_NO_CONTEXTMENU
//    void contextMenuEvent(QContextMenuEvent * event) Q_DECL_OVERRIDE;
//#endif //QT_NO_CONTEXTMENU

//private:
//    void createActions();
//    void createMenus();
//    QMenu *fileMenu;
//    QAction *newAct;
//private slots:
//    void newFile();
//};

//MainWindow::MainWindow {
//    QWidget * widget = new QWidget;
//}

//void MainWindow::createActions() {
//    QAction * newAct = new QAction(QObject::tr("&New"));
//    newAct->setShortcut(QKeySequence::New);
//    newAct->setStatusTip(QObject::tr("Create a new file."));
//    connect(newAct, &QAction::triggered, this, &newAct);
//}

//void MainWindow::createMenus(){
//    fileMenu = menuBar()->addMenu(QObject::tr("&File"));
//    fileMenu->addAction(newAct);
//}

//#ifndef QT_NO_CONTEXTMENU
//void MainWindow::contextMenuEvent(QContextMenuEvent *event){
//    QMenu menu(this);
//    menu.exec(event->globalPos());
//}
//#endif //QT_NO_CONTEXTMENU

int main(int argc, char *argv[])
{

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    //QQuickTextDocument(QQuickItem * codeArea);

    return app.exec();
}
