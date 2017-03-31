//
// Created by aleafall on 16-10-18.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Queue {
public:
    stack<int> st;
    // Push element x to the back of queue.
    void push(int x) {
        vector<int> vi;
        while (!st.empty()){
            vi.push_back(st.top());
            st.pop();
        }
        st.push(x);
        for (int i = 0; i < vi.size(); ++i) {
            st.push(vi[vi.size()-1-i]);
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!st.empty())
            st.pop();
    }

    // Get the front element.
    int peek(void) {
        if (!st.empty())
            return st.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
};

int main(){
    Queue *queue=new Queue;
    queue->push(1);
    cout<<queue->empty()<<endl;
    delete queue;
    return 0;
}