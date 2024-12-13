#ifndef USER_ROUTES_H
#define USER_ROUTES_H
#include "crow.h"
// Include the controller header to access the route handler functions
#include "controllers/user_controller.h"

// This function sets up all user-related routes and binds them to the controller functions
void setup_user_routes(crow::SimpleApp& app) {
    signup(app);  // Bind routes from controller
    login(app);
    logout(app);
    update(app);
}

#endif
