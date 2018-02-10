# zin
concurrent, functional, closure centric language

## core concepts
- everything is an expression (every statement has a value)
- functions are a first class
- every function is a closure
  - you can explicitly close over any variables
  - you can access / mutate a closure's context outside of a closure
  - objects are just a closure with the identify function

Due to the unique "closures first" concept, we get some really interesting things almost for free, like:
  - a class system - just include functions within a closure's context, these are now methods
  - objects - just closures where the closed function is returns the closure (identity)
  - continuations
    - because everything is inherently a closure, we get co-routines, green threads, etc

## examples
Functions:
```javascript
let foo = () => 'foo'
let foo() => 'foo'
let foo => 'foo'
```

```javascript
let add = (a, b) => a + b
let add(a, b) => a + b
let add(a, b) => (
  return a + b
)
```

Closures:
```javascript
let add_n(n) => (
  return (a) => a + n
)

let add_3 = add_n(3)
add_3(7) // 10

// access a closure's context
add_3.n // 3
add_3['n'] // 3
```

"Classes" and "Objects" - just a closure with no fn (defaults to identity)
```javascript
let Vehicle => (
  let :odometer = 0 // explicitly closed variable via `:`
)

let my_vehicle = Vehicle()
my_vehcile.odometer // 0
my_vehcile() // identity fn, so returns my_vehcile
```

"Inheritance" via the spread operator (include a closure's context in another closure)
```javascript
let Car(make, model) => (
  **Vehcile()
  let :make = make
  let :model = model
)

// explicitly close over arguments
let Car(:make, :model) => (
  **Vehcile()
  let :drive => (
    odometer += 1
  )
)
```

Partial function application
```javascript
let add(a, b) => a + b
let add_3 = add(3) // second argument not filled in, returns closure with `a` bound to 3
add_3(5) // 8
```
