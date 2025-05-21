## Static Arrays

### Characteristics:
- Stores elements in **contiguous memory locations**
- Holds elements of the **same data type**
- Has a **fixed size**

### Advantages:
- Elements can be **accessed easily and quickly** using the array name and the index

### Limitations:
- The size is **allocated at compile-time**
- Size must be a **constant expression**
- **Cannot be changed** while the program is running

---

## Dynamic Arrays

### Characteristics:
- Similar to static arrays, but the **size can change at runtime**

### Advantages:
- **Efficient memory use**: you can adjust the size to fit the number of elements
- You can **increase** or **decrease** the size dynamically

### Disadvantages:
- **Resizing** involves:
    1. Allocating space for a new (larger or smaller) array
    2. Copying all elements from the old array to the new array
    3. Deleting the old array
- **Extra execution time** is required for resizing operations

---

## STL Vector (C++)

### Characteristics:
- Provides all benefits of dynamic arrays with **less work and fewer errors**
- Stores elements in **contiguous memory**
- Can **resize automatically** when inserting or deleting elements
- Offers many built-in **functionalities** for managing collections

### Vector vs Static Array:
- Use `vector` if the collection size will **change frequently**
- Use **static array** if the size is fixed and you need **fast access**

### Vector vs Dynamic Array:
- `vector` **hides memory management** from the programmer
- Offers **reliable, tested, and standardized** functionality
- Millions of developers know how to use it
- Prefer `vector` over dynamic arrays unless you need **fine control** over performance and memory





