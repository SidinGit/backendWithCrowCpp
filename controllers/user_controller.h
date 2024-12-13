#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "crow.h"

void signup(crow::SimpleApp &app);
void login(crow::SimpleApp &app);
void logout(crow::SimpleApp &app);
void update(crow::SimpleApp &app);

#endif
