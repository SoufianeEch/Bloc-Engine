# BBloc Engine — Project Brief

## 1. Project Overview

**BBloc Engine** a small 2D game engine built as a learning and personal development project.

The project is intended to provide practical experience with C++ and to develop an understanding of how the major parts of a game engine work together.

---

## 2. Project Vision

The vision of BBloc Engine is to build a simple, working 2D game engine that allows users to create, inspect, and interact with basic 2D objects.

The engine will eventually provide a simple editor through which objects and scenes can be created and modified.

The project is primarily motivated by:

* Deep understanding of C++
* Understanding how game engines work
* Understanding software architecture
* Practicing real-world software development
* Having fun while building something from the ground up

---

## 3. Project Goals

### 3.1 Understand Game Engine Architecture

The project should provide practical understanding of how a simple game engine is structured and how its systems interact.

The engine will progressively develop systems for:

* 2D objects
* Scenes
* Rendering
* Input
* Physics
* Collision
* Object interaction
* Editor functionality

---

### 3.2 Build a Simple 2D Engine

BBloc Engine should support a small set of basic 2D objects:

* Rectangles
* Circles
* Triangles
* Lines
* Points

Objects should be possible to create, inspect, modify, and interact with.

The engine should remain intentionally simple rather than attempting to provide every feature found in large commercial game engines.

---

### 3.3 Implement Simple Physics

BBloc Engine should provide basic physics functionality, including:

* Gravity
* Collision detection
* Basic collision response
* Simple physical properties

The physics system is intended to demonstrate the fundamentals of physics simulation rather than become a fully featured physics engine.

---

### 3.4 Support User Input

The engine should allow interaction through user input.

Initial input goals include:

* Keyboard input
* Mouse input
* Controlling or interacting with objects through input

---

### 3.5 Build a Simple Editor

A simple editor should eventually allow the user to interact with the engine without directly modifying source code for every change.

The editor should provide functionality such as:

* Creating objects
* Selecting objects
* Inspecting objects
* Modifying object properties
* Working with scenes
* Running and interacting with a scene

The editor will be developed progressively and does not need to provide the functionality of a professional commercial engine editor.

---

### 3.6 Practice Real Software Development

BBloc Engine will also be used to gain practical experience with the software-development process.

Areas include:

* Git and version control
* CMake and build systems
* Debugging
* Automated testing
* Documentation
* Project planning
* Software architecture
* Code organization
* Incremental development
* Problem solving
* Maintaining a project over time

---

## 4. Version 1.0 Definition

### 4.1 v1.0 Goal

**BBloc Engine v1.0 a small, working 2D game engine that allows the user to create, inspect, and interact with basic 2D shapes, with simple physics and user input, through a basic editor.**

---

### 4.2 v1.0 Requirements

#### 2D Objects

The engine must support:

* Rectangle
* Circle
* Triangle
* Line
* Point

#### Scene and Object Interaction

The engine should allow the user to:

* Create objects
* Move objects
* Select objects
* Inspect objects
* Modify basic object properties
* Have multiple objects in a scene

#### Physics

The engine should support:

* Gravity
* Basic collision detection
* Basic collision response
* Simple physical properties

#### User Input

The engine should support:

* Keyboard input
* Mouse input
* Object interaction through user input

#### Editor

The editor should allow the user to:

* Create objects
* Select objects
* Inspect objects
* Modify objects
* Work with scenes
* Run and interact with a scene

#### Core Development

The project should have:

* A C++20 implementation
* Organized engine architecture
* A CMake build system
* Debugging support
* Automated tests for important systems
* Version control through Git

#### Documentation

The project should contain documentation covering:

* What BBloc Engine is
* How to build the project
* How to develop the project
* Important engine systems
* Project changes and milestones

---

## 5. v1.0 Success Criteria

BBloc Engine can be considered ready for v1.0 when it is possible to perform a workflow similar to:

1. Open BBloc Engine.
2. Create a scene.
3. Create a rectangle.
4. Create a circle.
5. Create a triangle.
6. Select and inspect objects.
7. Modify object properties.
8. Apply basic physics.
9. Run the scene.
10. Observe gravity affecting objects.
11. Observe objects colliding.
12. Interact with objects using user input.
13. Modify the scene through the editor.
14. Run a small interactive demo or game using the engine.

The purpose of this workflow is to demonstrate that the engine's core systems work together as a complete, usable project.

---

## 6. Scope Rule

BBloc Engine should remain focused on its purpose.

> **If a feature is not necessary for learning the fundamentals of C++ and game-engine architecture, or for creating the simple 2D interactive engine defined by v1.0, it should not be added to v1.0.**

Ideas that do not fit the v1.0 scope should be recorded for possible future development rather than being allowed to expand the current project unnecessarily.

---

## 7. Project Philosophy

BBloc Engine is a learning project, but it should be developed using a disciplined software-development process.

The project should follow this general cycle:

**Idea → Research → Requirements → Design → Implementation → Testing → Debugging → Documentation → Integration → Review**

The goal is to understand not only how to write the code, but also how a real software project is planned and developed.

---

## 8. Development Principles

The project should prioritize:

1. **Understanding over copying**
2. **Simple solutions over unnecessary complexity**
3. **Incremental development**
4. **Testing important functionality**
5. **Clear documentation**
6. **Maintainable code**
7. **Learning through implementation**
8. **Keeping the project within its defined scope**

---

## 9. Project Target

The current target for **BBloc Engine v1.0 is December 20, 2026**.

The schedule may be adjusted when necessary. The quality of understanding and implementation is more important than blindly following a deadline.

---

## 10. Definition of the Project

BBloc Engine is successful if, by the end of the project, it provides both:

**A working small 2D game engine**

and

**A practical understanding of how C++, software architecture, game-engine systems, and real-world software development work together.**
