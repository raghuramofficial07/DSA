<!-- GitHub Project Banner -->
<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C++-black?logo=cplusplus&logoColor=white&labelColor=black&color=black">
  <img src="https://img.shields.io/badge/Built%20by-RaghuRam-black?labelColor=black&color=black">
</p>

# » C++ Core OOP Concepts — Beginner to Advanced

## » Table of Contents
1. Introduction
2. Constructor
3. Destructor
4. Inheritance
5. Abstraction
6. Static Keyword
7. Inheriting from Parent Class
8. Polymorphism
9. this-> Pointer
10. Virtual Functions
11. Concept Flow Diagram
12. Quick Reference Table
13. Author Footer

---

## » Introduction
C++ is an object-oriented programming language that gives you the ability to structure your code using **classes** and **objects**. In this guide, we will explore crucial C++ OOP concepts such as constructors, destructors, inheritance, abstraction, and more, with examples that even a beginner can follow.

---

## » Constructor
A **constructor** is a special member function that is automatically called when an object of a class is created.

**Key Points:**
- Same name as the class.
- No return type.
- Can be overloaded.

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    
    // Constructor
    Car(string b) {
        brand = b;
        cout << "Car constructed: " << brand << endl;
    }
};

int main() {
    Car c1("Tesla"); // Constructor runs automatically
}
```

---

## » Destructor
A **destructor** is a special member function called when an object goes out of scope or is deleted.

**Key Points:**
- Same name as the class but preceded with `~`.
- No parameters, no return type.
- Used to free resources.

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    Car() {
        cout << "Car constructed" << endl;
    }
    ~Car() {
        cout << "Car destroyed" << endl;
    }
};

int main() {
    Car c1; // Constructor runs here
} // Destructor runs automatically here
```

---

## » Inheritance
**Inheritance** allows one class (child) to acquire the properties and methods of another (parent).

```cpp
#include <iostream>
using namespace std;

class Vehicle {
public:
    void drive() {
        cout << "Driving..." << endl;
    }
};

class Car : public Vehicle {
public:
    void honk() {
        cout << "Honking!" << endl;
    }
};

int main() {
    Car c1;
    c1.drive(); // From parent class
    c1.honk();  // From child class
}
```

---

## » Abstraction
**Abstraction** hides internal implementation details and exposes only essential features.

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Circle c;
    c.draw();
}
```

---

## » Static Keyword
The **static** keyword makes a variable or function belong to the class rather than any specific object.

```cpp
#include <iostream>
using namespace std;

class Counter {
public:
    static int count;
    
    Counter() {
        count++;
    }
};

int Counter::count = 0; // Definition

int main() {
    Counter c1, c2;
    cout << Counter::count; // Access without object
}
```

---

## » Inheriting from Parent Class
When inheriting, you specify the **access specifier** (`public`, `protected`, `private`) for inheritance.

```cpp
class Parent {
public:
    void show() {
        cout << "Parent function" << endl;
    }
};

class Child : public Parent {
};

int main() {
    Child obj;
    obj.show();
}
```

---

## » Polymorphism
**Polymorphism** means "many forms" — the same function name behaves differently based on the object.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof" << endl;
    }
};

int main() {
    Animal* a = new Dog();
    a->speak(); // Outputs: Woof
}
```

---

## » this-> Pointer
The `this` pointer refers to the current object instance.

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    int length;
    Box setLength(int length) {
        this->length = length;
        return *this;
    }
    void show() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b;
    b.setLength(10).show();
}
```

---

## » Virtual Functions
Virtual functions enable **runtime polymorphism**.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived class" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->display(); // Calls Derived's version
}
```

---

## » Concept Flow Diagram
```
Object Creation → Constructor → Inheritance → Polymorphism → Virtual Functions
                  ↓
              Destructor (when object is destroyed)
```

---

## » Quick Reference Table

| Concept         | Purpose | Key Syntax | Example |
|----------------|---------|-----------|---------|
| Constructor    | Initialize object | ClassName(){} | `Car c;` |
| Destructor     | Clean up object | ~ClassName(){} | Automatic on delete |
| Inheritance    | Reuse code | `class Child : public Parent` | Child gets Parent methods |
| Abstraction    | Hide details | `virtual void func() = 0;` | Interfaces |
| Static         | Shared among all objects | `static int x;` | `Class::x` |
| this-> Pointer | Current object reference | `this->var` | Method chaining |
| Virtual Func   | Override at runtime | `virtual void func()` | Polymorphism |

---

## » Author Footer

**Created By:** Vemparala Sri Satya RaghuRam  
**License:** MIT  
**Platform:** C++  

<p align="left">
  <img src="https://img.shields.io/badge/%23BeyondCertifications-black?logo=tag&logoColor=white&labelColor=black&color=black">
  <img src="https://img.shields.io/badge/%23IndustryOriented-black?logo=tag&logoColor=white&labelColor=black&color=black">
  <img src="https://img.shields.io/badge/%23CodeWithRaghuRam-black?logo=tag&logoColor=white&labelColor=black&color=black">
</p>
