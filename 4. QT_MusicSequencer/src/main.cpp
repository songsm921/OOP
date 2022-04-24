#include <QApplication>

#include "mainwindow.h"
#include "player.h"

//using namespace as4::widgets;

// Entry point of our application
int main(int argc, char **argv)
{
    /*as4::model::VectorSeq a;
    as4::model::VectorSeq b;
    app::source::Player *player_m = new app::source::MelodyPlayer;
    app::source::Player *player_d = new app::source::DrumPlayer;
   a.Put({40, 10, {0, 4}}); // C1 start:duration 100:10
    a.Put({30, 10, {0, 5}}); // C1 0:10
    a.Put({10, 20, {2, 4}}); // D1 10:10
   a.Put({10, 20, {5, 4}});
   b.Put({40, 10, {0, 4}}); // C1 start:duration 100:10
    b.Put({30, 10, {0, 5}}); // C1 0:10
    b.Put({10, 20, {2, 4}}); // D1 10:10
   b.Put({10, 20, {5, 4}});*/
    QApplication app(argc, argv);

    // Create and show our main window. 'mainWindow' is the
    // root QWidget of all QWidgets in this application
    MainWindow window;
    window.show();
    //player_d->GetInfo(b);
   // player_d->Init();


    // Enters main event loop and waits until exit() is called.
    // No user interaction can take place before this call.
    return app.exec();
}
