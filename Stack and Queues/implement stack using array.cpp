#include <bits/stdc++.h>
using namespace std;

class myStack {
private:
    vector<int> st;
    int idx=-1;
public:
    myStack(int n) {
        // Define Data Structures
        st.resize(n);
    }

    bool isEmpty() {
        // check if the stack is empty
        return idx==-1;
    }

    bool isFull() {
        // check if the stack is full
        return idx==st.size()-1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(!isFull()){
            idx+=1;
            st[idx]=x;
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(idx!=-1){
            st[idx]=-1;
            idx--;
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(idx!=-1)
            return st[idx];
        return -1;
    }
};

int main()
{
    myStack s(5);
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;

    return 0;
}