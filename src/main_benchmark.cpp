#include "App.h"
#include <iostream>
using namespace std;

int main() {
    App app;

    // Load và đo thời gian cho các file khác nhau
    //100contact
    app.benchmarkLoadFromFile("test/Contacts100.txt");
    //name , phone tồn tại
    app.benchmarkSearchByName("Le Huu Minh Phu100");
    app.benchmarkSearchByPhone("0987000100");
    //name , phone không tồn tại
    app.benchmarkSearchByName("Le Huu Minh Phu100000");
    app.benchmarkSearchByPhone("0187000300");
    app.benchmarkDeleteByName("Le Huu Minh Phu100");
    // 1000 contact
    app.benchmarkLoadFromFile("test/Contacts1000.txt");
    //name , phone tồn tại
    app.benchmarkSearchByName("Le Huu Minh Phu1000");
    app.benchmarkSearchByPhone("0987001000");
    //name , phone không tồn tại
    app.benchmarkSearchByName("Le Huu Minh Phu100000");
    app.benchmarkSearchByPhone("0187000300");
    app.benchmarkDeleteByName("Le Huu Minh Phu1000");
    // cho 10000 contact
    app.benchmarkLoadFromFile("test/Contacts10000.txt");
    //name , phone tồn tại
    app.benchmarkSearchByName("Le Huu Minh Phu10000");
    app.benchmarkSearchByPhone("0987010000");
    //name , phone không tồn tại
    app.benchmarkSearchByName("Le Huu Minh Phu100000");
    app.benchmarkSearchByPhone("0187000300");
    app.benchmarkDeleteByName("Le Huu Minh Phu10000");
    return 0;
}
