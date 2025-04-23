#include <iostream>
#include <vector>
using namespace std;

struct Node{
        int value;
        Node* next;
};
Node* deleteBottom(Node* head);
void printList(Node* head);
Node* createList(int arr[], int n);
void freeList(Node* head);

int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited, int i, int j, int n );

int main(){
//---------Câu 1------------------
    /*int N; cin >> N;
    vector<int> input(N);
    for(int &i : input){ cin >> i;}
    vector<int> result;
    result.push_back(0);
    for(int i=1; i<N; i++){
        if(input[i]<input[i-1]) result.push_back(i);
    }
    for(int i=0; i<result.size(); i++){
        cout << result[i];
        if(i<result.size()-1) cout << " ";
    }*/

//--------------Câu 2--------------
    /*int arr[] = {3, 2, 0, 4, 4};
    Node* head = createList(arr, 5);
    cout << "Danh sach ban dau: ";
    printList(head);
    head = deleteBottom(head);
    cout << "Danh sach sau khi xoa node day: ";
    printList(head);
    freeList(head);*/

//--------------Câu 3--------------
    int n;cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int max_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && !visited[i][j]) {
                int size = dfs(grid, visited, i, j, n);
                max_size = max(max_size, size);
            }
        }
    }
    cout << max_size << endl;


    return 0;
}

//--------------Câu 3--------------
int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited, int i, int j, int n ){
    if(i<0 || i>=n || j<0 || j>=n || grid[i][j] != 0 || visited[i][j]){
        return 0;
    }
    visited[i][j] = true;
    int size = 1;

    size += dfs(grid, visited, i-1, j, n);
    size += dfs(grid, visited, i+1, j, n);
    size += dfs(grid, visited, i, j-1, n);
    size += dfs(grid, visited, i, j+1, n);
    return size;
}

//--------------Câu 2--------------
Node* deleteBottom(Node* head){
    if(!head || !head->next) return head;
    if(head->value < head->next->value / 2){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    Node* prev = head;
    Node* curr = head->next;
    while(curr->next){
        if(curr->value < prev->value / 2 && curr->value < curr->next->value / 2){
            prev->next = curr -> next;
            delete curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    if(curr->value < prev->value / 2){
        prev->next = nullptr;
        delete curr;
    }
    return head;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* createList(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node{arr[0], nullptr};
    Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new Node{arr[i], nullptr};
        current = current->next;
    }

    return head;
}
void freeList(Node* head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
