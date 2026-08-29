# Vector2 Requirements

Vector2 represents a 2D value using two components:

- x
- y

It must support:

- Addition
- Subtraction
- Multiplication by a scalar
- Length
- Normalization
- Dot product

# Vector2 Design

## Data memebers
  - float x
  - float y

## Constructor
  - Vector2(float x = 0, float y = 0)

## Operator & Methods
  - Addition
    - Vector2 operator+(const Vector& other) const;
    - Usage: `v1 + v2`
  - Substraction
    - Vector2 operator-(const Vector2& other) const;
    - Usage: `v1 - v2`
  - Scaler Multiplication
    - Vector2 operator*(float scaler) const;
    - Usage: `v2 * 2.0f`
  - Length
    - float Length() const;
    - Usage: `v.Length()`
  - Normalization
    - Vector2 Normalize() const;
    - Usage: `v.Normalize()`
  - Dot Product
    - float DotProduct(const Vector2& other) const;
    - Usage: `v1.DotProduct(v2)`