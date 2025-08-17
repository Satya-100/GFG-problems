/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void insert(stack<int>& s, int temp){
    if(s.empty() || s.top()<=temp){
        s.push(temp);
        return ;
    }
    
    int top = s.top();
    s.pop();
    insert(s, temp);
    s.push(top);
}

void SortedStack ::sort() {
    // Your code here
    if(s.size()==1){
        return ;
    }
    
    int temp = s.top();
    s.pop();
    sort();
    insert(s, temp);
}