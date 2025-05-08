/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA3: Do you see what I see?
 */

/*
Monotonic stack (MonoStack):
this is a stack that has elements that appear in either monotonically increasing or decreasing order. from the bottom
of the stack to the top of the stack. Duplicate values are not allowed in the stack. As with any traditional stack,
a monotonic stack is a LIFO (last in first out) data structure. The only difference is the push function, which must
ensure that the values remain in monotonically increasing or decreasing order. this means that for a monotonically
increasing stack, to push a value of X on the stack, we must first pop and discard all values in the stack that are
larger than X. Similarly, for a monotonically decreasing stack, to push a value of X on the stack, we must first pop
and discard all values in the stack that are smaller than X. All other operations remain the same
*/

#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>

template <typename T>
class MonoStack {
    public:
        MonoStack(int size, char o) : capacity(size), order(o), topIndex(-1) {
            stack = new T[capacity];
        }

        ~MonoStack() {
            delete[] stack;
        }

        void push(T value) {
            while (topIndex >= 0 && ((order == 'i' && stack[topIndex] > value) || (order == 'd' && stack[topIndex] < value))) {
                topIndex--;
            }

            if (topIndex + 1 == capacity) {
                resize();
            }
            stack[++topIndex] = value;
        }

        void pop() {
            if (topIndex >= 0) {
                topIndex--;
            }
        }

        T top() {
            if (topIndex >= 0) return stack[topIndex];
            throw std::out_of_range("Stack is empty");
        }

        bool isEmpty() {
            return topIndex == -1;
        }

    private:
        T* stack;
        int topIndex;
        int capacity;
        char order; // 'i' for increasing, 'd' for decreasing

        void resize() {
            capacity *= 2;
            T* newStack = new T[capacity];
            for (int i = 0; i <= topIndex; i++) {
                newStack[i] = stack[i];
            }

            delete[] stack;
            stack = newStack;
        }
};

#endif