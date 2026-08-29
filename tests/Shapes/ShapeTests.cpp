#include <cassert>
#include <cmath>
#include "Shapes/Circle.hpp"
#include "Shapes/Rectangle.hpp"
#include "Shapes/Triangle.hpp"
#include "Shapes/Line.hpp"

using namespace BBloc;

// ===== Circle Tests =====
void TestCircleConstruction() {
    Circle circle(Vector2(100.0f, 50.0f), 25.0f);
    assert(circle.GetRadius() == 25.0f);
}

void TestCircleGetBounds() {
    Circle circle(Vector2(100.0f, 50.0f), 25.0f);
    Vector2 bounds = circle.GetBounds();
    assert(bounds.x == 50.0f && bounds.y == 50.0f);  // diameter
}

// ===== Rectangle Tests =====
void TestRectangleConstruction() {
    Rectangle rect(Vector2(10.0f, 20.0f), 100.0f, 50.0f);
    assert(rect.GetWidth() == 100.0f);
    assert(rect.GetHeight() == 50.0f);
}

void TestRectangleGetBounds() {
    Rectangle rect(Vector2(10.0f, 20.0f), 100.0f, 50.0f);
    Vector2 bounds = rect.GetBounds();
    assert(bounds.x == 100.0f && bounds.y == 50.0f);
}

// ===== Triangle Tests =====
void TestTriangleConstruction() {
    Vector2 p1(0.0f, 0.0f);
    Vector2 p2(10.0f, 0.0f);
    Vector2 p3(5.0f, 10.0f);
    Triangle triangle(Vector2(50.0f, 50.0f), p1, p2, p3);
    assert(triangle.GetScale() == 1.0f);
}

void TestTriangleSetScale() {
    Vector2 p1(0.0f, 0.0f);
    Vector2 p2(10.0f, 0.0f);
    Vector2 p3(5.0f, 10.0f);
    Triangle triangle(Vector2(50.0f, 50.0f), p1, p2, p3);
    
    triangle.SetScale(2.0f);
    assert(triangle.GetScale() == 2.0f);
}

void TestTriangleGetBounds() {
    Vector2 p1(0.0f, 0.0f);
    Vector2 p2(10.0f, 0.0f);
    Vector2 p3(5.0f, 10.0f);
    Triangle triangle(Vector2(50.0f, 50.0f), p1, p2, p3);
    
    Vector2 bounds = triangle.GetBounds();
    assert(bounds.x == 10.0f && bounds.y == 10.0f);
}

// ===== Line Tests =====
void TestLineConstruction() {
    Line line(Vector2(0.0f, 0.0f), Vector2(10.0f, 0.0f), 2.0f);
    assert(line.GetThickness() == 2.0f);
}

void TestLineGetLength() {
    Line line(Vector2(0.0f, 0.0f), Vector2(3.0f, 4.0f), 2.0f);
    float length = line.GetLength();
    assert(length == 5.0f);  // 3-4-5 triangle
}

void TestLineGetBounds() {
    Line line(Vector2(0.0f, 0.0f), Vector2(10.0f, 5.0f), 2.0f);
    Vector2 bounds = line.GetBounds();
    assert(bounds.x == 10.0f && bounds.y == 5.0f);
}

// ===== Main Test Runner =====
int main() {
    // Circle tests
    TestCircleConstruction();
    TestCircleGetBounds();
    
    // Rectangle tests
    TestRectangleConstruction();
    TestRectangleGetBounds();
    
    // Triangle tests
    TestTriangleConstruction();
    TestTriangleSetScale();
    TestTriangleGetBounds();
    
    // Line tests
    TestLineConstruction();
    TestLineGetLength();
    TestLineGetBounds();
    
    return 0;
}