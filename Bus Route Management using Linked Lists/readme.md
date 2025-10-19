This program simulates a bus route management system using a singly linked list data structure in C++.
Each node in the list represents a bus stop, storing essential details such as ID, name, distance, scheduled time, and dwell duration.

The project demonstrates key linked list operations, including insertion, deletion, search, updating, reversing, rotation, and delay propagation, all applied in a real-world scenario of route scheduling and management.

🧩 Features

Dynamic Stop Creation:
Add stops dynamically with relevant details like name, ID, km, schedule time, and dwell duration.

Insertion & Deletion:
Insert a stop after a given ID or remove a stop by ID.

Search & Update:
Locate a stop using its ID and update its schedule or dwell time.

Reversing Segments:
Reverse a segment of the route between two given stop IDs.

Rotation:
Rotate the entire route to the left by k positions.

Delay Propagation:
Apply delay propagation
Memory Cleanup:
Proper deallocation of all stops using destroyRoute() to prevent memory leaks.
