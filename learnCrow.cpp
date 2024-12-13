#include "crow.h"
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

#include "controllers/user_controller.h"
#include "routes/user_routes.h"

int main()
{
    crow::SimpleApp app;

    // Setup routes by calling the setup function
    setup_user_routes(app);

    app.port(18080).multithreaded().run();
}
