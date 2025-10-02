# 🎓 University Course Registration System (Waitlist Management)

This project implements a **University Course Registration Waitlist Management System** using a **Singly Linked List** in C++.  
It simulates the real-world course registration scenario at FAST University, where students are either allocated a seat or placed on a waitlist. Scholarship students are given **priority** in the waitlist but maintain their relative order among themselves.

---

## 📌 Features & Requirements

Each **Node** in the waitlist stores:
- **Student ID** (unique, integer)  
- **Student Name** (string)  
- **Course Code** (e.g., `CS201`)  
- **Priority Status** (`Normal`, `Merit Scholarship`, `Need Scholarship`)  

### Supported Operations
1. **Add Student to Waitlist**  
   - Normal students are added at the end.  
   - Scholarship students are inserted before normal students, but after existing scholarship students.  

2. **Remove Student from Waitlist**  
   - Removes a student using their Student ID.  

3. **Allocate Seat**  
   - Allocates a seat to the first student in the waitlist (highest priority).  

4. **Swap Requests**  
   - Two students can swap their positions without breaking the linked list structure.  

5. **Display Waitlist**  
   - Shows all students in their current order with complete details.  

6. **Find Student Position**  
   - Finds the position of a student in the waitlist by Student ID.  

7. **End of Registration Report**  
   - Total number of students who got seats.  
   - Total number of students still on the waitlist.  
   - Separate lists for Scholarship students and Normal students still waiting.  


