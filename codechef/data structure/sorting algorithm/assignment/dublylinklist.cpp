
#include <iostream>
using namespace std;

struct node{
    int val;
    node *next;
};


struct DoublyLinkedList{
    node *head, *tail;
    /**
    * Implement the constructor to initialize head and tail
    */
    DoublyLinkedList();
    /**
    * A value would be provided, you have to insert it as the
    * last element.
    */
    void insertValAtTail(int val);
    /**
    * A value would be provided, you have to insert it as the
    * second last element, that means the inserted value would
    * be the second element from last.
    */
    void insertValBeforeTail(int val);
    /**
    * A value would be provided, you have to insert it as the
    * first element.
    */
    void insertAtHead(int val);
    /**
    * A value would be provided, you have to insert it as the
    * second element.
    */
    void insertAfterHead(int val);
    /**
    * A value and a position would be provided, you have to
    * insert the value in the provided position from first.
    */
    void insertAtPos(int val, int pos);
    /**
    * A value and a position would be provided, you have to
    * insert the value in the provided position from last.
    */
    void insertAtRevPos(int val, int pos);
    /**
    * A value would be provided, you have to find the position
    * of its first occurrence from first.
    */
    int findValFromHead(int val);
    /**
    * A value would be provided, you have to find the position
    * of its first occurrence from last.
    */
    int findValFromTail(int val);
    /**
    * A position would be provided, you have to find the value
    * of the corresponding position from first.
    */
    int findValAtPosFromHead(int pos);
    /**
    * A position would be provided, you have to find the value
    * of the corresponding position from last.
    */
    int findValAtPosFromTail(int pos);
    /**
    * Print all the values in the list from first to last.
    */
    void traverse();
    /**
    * Print all the values in the list from last to first.
    */
    void reverselyTraverse();
    /**
    * A value would be provided, delete all occurrence
    * of the value from the list.
    */
    void deleteVal(int val);
    /**
    * A value would be provided, delete the first occurrence
    * of the value from first.
    */
    void deletePosFromHead(int pos);
    /**
    * A value would be provided, delete the first occurrence
    * of the value from last.
    */
    void deletePosFromTail(int pos);
    /**
    * Delete all elements of the list.
    */
    void deleteAll();
    /**
    * Delete the first element of the list.
    */
    void deleteHead();
    /**
    * Delete the last element of the list.
    */
    void deleteTail();
};

int main()
{
    return 0;
}
