# travel-management
C++ application with a 4-layered architecture: data access layer (Domain), persistence layer (Repository), business layer (Service) and presentation layer (UserInterface). The data are saved in txt or csv files (input, output). Validations for entity data and tests for functions and validations were performed. The main class is Applications. Key concepts are encapsulation, inheritance, polymorphism, validations, exceptions, reading from files and storing in files.

Application for travel management. A travel agency organizes trips and they need an application to manage their transportation problem. The means of transport available are the plane and the bus. A plane trip is characterized by travel code, departure city, destination city, departure date, property to stop or not, total number of seats and number of reserved seats. A bus trip is characterized by travel code, departure city, destination city, departure date, number of days of travel duration, total number of seats and number of reserved seats.

The application must allow the following functionalities:
1. Login - After successful authentication, all trips are displayed, along with their related features
2. Operation - After successful authentication, a user can:
• Look for trips that take place on a certain date. The application will display all the characteristics of the search results.
• Book a certain number of seats for a trip with a given code. A user cannot book more seats than available for that trip. After the change, the application displays the updated travel list. If a certain trip no longer has any space available, then it will be displayed with special fonts.
3. Logout

Specifications:
1. Input data is stored in files. On application startup, entities are read from files. Changes made during the application run are saved in these files.
2. When starting the application, the user can choose the type of file/files according to which the data is viewed (TXT or CSV). Depending on this type chosen by the user, the data is saved in file(s). Polymorphic structures were used.
3. Exceptions were used to signal possible errors.
4. The data retrieved in the application is validated using the Validator classes.
