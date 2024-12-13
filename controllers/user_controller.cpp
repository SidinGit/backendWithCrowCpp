#include "user_controller.h"
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
struct User
{
    std::string username;
    std::string password; // In real-world apps, passwords should be hashed!
    std::string email;
    std::string profile_picture; // Store the filename of the uploaded profile picture.
};

// In-memory storage for user data.
std::unordered_map<std::string, User> users;
std::unordered_map<std::string, bool> logged_in_users;

// Signup route logic
void signup(crow::SimpleApp &app)
{
    CROW_ROUTE(app, "/signup").methods("POST"_method)([](const crow::request &req)
                                                      {
    auto json = crow::json::load(req.body);
    if (!json) {
        crow::json::wvalue response_json;
        response_json["status"] = 400;
        response_json["message"] = "Invalid JSON";
        return crow::response(response_json);
    }

    std::string username = json["username"].s();
    std::string password = json["password"].s();
    std::string email = json["email"].s();

    if (users.find(username) != users.end()) {
        crow::json::wvalue response_json;
        response_json["status"] = 400;
        response_json["message"] = "User already exists.";
        return crow::response(response_json);
    }

    User new_user{ username, password, email, "" };
    users[username] = new_user;

    crow::json::wvalue response_json;
    response_json["status"] = 200;
    response_json["message"] = "User created successfully.";
    return crow::response(response_json); });
}

// Login route logic
void login(crow::SimpleApp &app)
{
    CROW_ROUTE(app, "/login").methods("POST"_method)([](const crow::request &req)
                                                     {
    auto json = crow::json::load(req.body);
    if (!json) {
        crow::json::wvalue response_json;
        response_json["status"] = 400;
        response_json["message"] = "Invalid JSON";
        return crow::response(response_json);
    }

    std::string username = json["username"].s();
    std::string password = json["password"].s();

    auto user_it = users.find(username);
    if (user_it == users.end()) {
        crow::json::wvalue response_json;
        response_json["status"] = 400;
        response_json["message"] = "User not found.";
        return crow::response(response_json);
    }

    if (user_it->second.password != password) {
        crow::json::wvalue response_json;
        response_json["status"] = 400;
        response_json["message"] = "Invalid credentials.";
        return crow::response(response_json);
    }

    logged_in_users[username] = true;
    crow::json::wvalue response_json;
    response_json["status"] = 200;
    response_json["message"] = "Login successful.";
    return crow::response(response_json); });
}

// Logout route logic
void logout(crow::SimpleApp &app)
{
    CROW_ROUTE(app, "/logout").methods("POST"_method)([](const crow::request &req)
                                                      {
    auto json = crow::json::load(req.body);
    if (!json) {
        crow::json::wvalue response_json;
        response_json["status"] = 400;
        response_json["message"] = "Invalid JSON";
        return crow::response(response_json);
    }

    std::string username = json["username"].s();
    if (logged_in_users.find(username) == logged_in_users.end()) {
        crow::json::wvalue response_json;
        response_json["status"] = 400;
        response_json["message"] = "User is not logged in.";
        return crow::response(response_json);
    }

    logged_in_users.erase(username);
    crow::json::wvalue response_json;
    response_json["status"] = 200;
    response_json["message"] = "Logout successful.";
    return crow::response(response_json); });
}

// Update route logic
void update(crow::SimpleApp &app)
{
    CROW_ROUTE(app, "/update").methods("POST"_method)([](const crow::request &req)
                                                      {
    auto json = crow::json::load(req.body);
    if (!json) {
        crow::json::wvalue response_json;
        response_json["status"] = 400;
        response_json["message"] = "Invalid JSON";
        return crow::response(response_json);
    }

    std::string username = json["username"].s();
    std::string new_email = json["new_email"].s();

    auto user_it = users.find(username);
    if (user_it == users.end()) {
        crow::json::wvalue response_json;
        response_json["status"] = 400;
        response_json["message"] = "User not found.";
        return crow::response(response_json);
    }

    if (logged_in_users.find(username) == logged_in_users.end()) {
        crow::json::wvalue response_json;
        response_json["status"] = 400;
        response_json["message"] = "User must be logged in to update info.";
        return crow::response(response_json);
    }

    user_it->second.email = new_email;

    crow::json::wvalue response_json;
    response_json["status"] = 200;
    response_json["message"] = "User information updated.";
    return crow::response(response_json); });
}
