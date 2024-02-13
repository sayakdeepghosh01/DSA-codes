
1. **Simple Queue:**
   - A simple queue is a linear data structure that follows the FIFO (First-In-First-Out) principle. The first element added to the queue will be the first one to be removed.
   - **Operations:**
     - `enqueue`: Adds an element to the rear of the queue.
     - `dequeue`: Removes and returns the front element of the queue.
     - `isEmpty`: Checks if the queue is empty.
     - `isFull`: Checks if the queue is full (in case of a bounded queue).
   - **Time Complexity:**
     - `enqueue`: O(1)
     - `dequeue`: O(1)
     - `isEmpty`: O(1)
     - `isFull`: O(1)
   - **Space Complexity:**
     - O(n), where n is the maximum number of elements in the queue.

2. **Circular Queue:**
   - A circular queue is a variation of the simple queue, but the last element is connected to the first element to form a circular structure. This allows efficient usage of space and avoids shifting elements when dequeueing.
   - **Operations:**
     - Similar to a simple queue: `enqueue`, `dequeue`, `isEmpty`, `isFull`.
   - **Time Complexity:**
     - `enqueue`: O(1)
     - `dequeue`: O(1)
     - `isEmpty`: O(1)
     - `isFull`: O(1)
   - **Space Complexity:**
     - O(n), where n is the maximum number of elements in the queue.

3. **Priority Queue:**
   - A priority queue is a data structure that maintains a set of elements. Each element has an associated priority, and elements with higher priority are dequeued before elements with lower priority.
   - **Operations:**
     - `push`: Inserts an element into the priority queue with a given priority.
     - `pop`: Removes and returns the element with the highest priority.
     - `isEmpty`: Checks if the priority queue is empty.
   - **Time Complexity:**
     - `push`: O(log n), where n is the number of elements in the priority queue.
     - `pop`: O(log n)
     - `isEmpty`: O(1)
   - **Space Complexity:**
     - O(n)

4. **Double-Ended Queue (Deque):**
   - A deque is a generalized queue data structure that allows insertion and deletion of elements from both the front and the rear ends. It can function as both a stack and a queue.
   - **Operations:**
     - `insertFront`: Inserts an element at the front of the deque.
     - `insertRear`: Inserts an element at the rear of the deque.
     - `deleteFront`: Removes and returns an element from the front of the deque.
     - `deleteRear`: Removes and returns an element from the rear of the deque.
   - **Time Complexity:**
     - `insertFront`: O(1)
     - `insertRear`: O(1)
     - `deleteFront`: O(1)
     - `deleteRear`: O(1)
   - **Space Complexity:**
     - O(n), where n is the maximum number of elements in the deque.
