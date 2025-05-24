# Task Manager

Task Manager is a simple C++ console-based application that allows you to manage tasks, assignees, and associated checklist items. It’s designed to help teams or individuals keep track of assignments and monitor progress effectively.

---

## 💡 Features

- Add and view **Assignees**
- Add and view **Tasks**
- Add and mark **Checklist Items** for tasks
- Generate **individual task reports** per assignee in `.txt` files
- Simple and intuitive menu-driven interface

---

## 📂 Project Structure

- **Assignee:** Stores ID, name, email, and phone of each team member.
- **Task:** Contains a unique task ID, name, assigned user, and status.
- **ChecklistItem:** Contains a task ID, description, and completion status.

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`)

### Compilation

```bash
g++ -o TaskFlowManager main.cpp
