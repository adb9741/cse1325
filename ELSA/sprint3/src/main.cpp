#include "mainwin.h"

int main (int argc, char *argv[]) {
    srand (time(NULL));
    auto app = Gtk::Application::create(argc, argv, "alpha.elsa.v0_3_0");
    Mainwin win;
    return app->run(win);
}

