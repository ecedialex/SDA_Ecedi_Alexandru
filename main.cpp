#include "Service.h"
#include "Ui.h"

using namespace std;

int main() {
    Service service("users.txt", "events.txt");
    Ui ui(service);
    ui.show_menu();
    return 0;
}
