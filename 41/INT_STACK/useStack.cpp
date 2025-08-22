#include <iostream>
#include <cassert>
#include "Stack.hpp"

int main(void)
{
    int topData,poppedData;
    status_t status;

    Stack S(8);

    assert(S.top(&topData) == STACK_EMPTY);
    assert(S.pop(&poppedData) == STACK_EMPTY);
    
    for(ssize_t i =0 ; i <8; ++i)
    {
        status = S.push((i+1)*100);
        assert(status == SUCCESS);
    }

    status = S.push(900);
    assert(status == STACK_FULL);

    status = S.top(&topData);
    assert(status == SUCCESS);
    std::cout << "TOP DATA:" << topData <<std::endl;

    while(!S.empty())
    {
        status = S.pop(&poppedData);
        assert(status == SUCCESS);
        std::cout <<"Popped Data:" << poppedData <<std::endl;

    }

    assert(S.top(&topData) == STACK_EMPTY);
    assert(S.pop(&poppedData) == STACK_EMPTY);
    std::cout <<"TESTING COMPLETE" <<std::endl;
}



/*


int main(void)
{
    Stack myStack(5); // Create a stack with size 5

    // Push elements into the stack
    for (int i = 1; i <= 5; ++i) {
        if (myStack.push(i) == STACK_FULL) {
            std::cout << "Stack is full. Cannot push " << i << std::endl;
        } else {
            std::cout << "Pushed: " << i << std::endl;
        }
    }

    // Try pushing another element to show overflow
    if (myStack.push(6) == STACK_FULL) {
        std::cout << "Stack is full. Cannot push 6" << std::endl;
    }

    // Display the top element
    int topElement;
    if (myStack.top(&topElement) == SUCCESS) {
        std::cout << "Top element: " << topElement << std::endl;
    } else {
        std::cout << "Stack is empty. Cannot get top element." << std::endl;
    }

    // Pop all elements
    int poppedElement;
    while (!myStack.empty()) {
        if (myStack.pop(&poppedElement) == SUCCESS) {
            std::cout << "Popped: " << poppedElement << std::endl;
        }
    }

    // Try popping from empty stack
    if (myStack.pop(&poppedElement) == STACK_EMPTY) {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
    }

    return 0;
}


*/