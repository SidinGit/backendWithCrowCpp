# Crow C++ Backend Starter Project

This is a simple starter project for building a backend API using the **Crow C++ framework**. The project provides basic user authentication features such as signup, login, update, and logout. The backend is designed to handle requests via HTTP routes, and responses are returned in JSON format.

## Current Features
- **User Signup**: Allows users to sign up with a username, password, and email.
- **User Login**: Authenticates users with their username and password.
- **User Logout**: Allows users to log out.
- **User Update**: Lets users update their email (only while logged in).

### Example Endpoints:
- `POST /signup` - Sign up a new user.
- `POST /login` - Log in with username and password.
- `POST /logout` - Log out the current user.
- `POST /update` - Update user information (requires login).

### Response Format:
All responses are returned in **JSON format**. For example, a successful signup response:

```json
{
  "status": 200,
  "message": "User created successfully."
}
```

## Future Plans
This project is a starting point, and the following features will be added in the future:
- **File Upload Handling**: Support for uploading profile pictures and other files. This will include handling multipart/form-data requests to manage file uploads.
- **Database Integration**: We plan to integrate an RDBMS (Relational Database Management System) like SQL, SQLite, or PostgreSQL to persist user data and make the backend more scalable.
- **Advanced Authentication**: Adding support for password hashing and possibly integrating token-based authentication (e.g., JWT) for secure login sessions.
- **API Documentation**: We will add automatic API documentation generation (using tools like Swagger or similar) to make it easier for others to interact with the backend.

