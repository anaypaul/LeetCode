#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int parent(int n){
    if(n%2==0){
        n= n-2;
        return n/2;
    }else{
        n--;
        return n/2;
    }
}
//max heap
void maxheapify(vector<int>& arr, int index){
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < arr.size() && arr[largest]< arr[left]){
        largest = left;
    }
    if(right< arr.size() && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest!= index){
        int t = arr[largest];
        arr[largest] = arr[index];
        arr[index] = t;
        maxheapify(arr, largest);
    }
}
int getMax(vector<int>&arr){
    int l = arr[0];
    arr[0] = arr[arr.size()-1];
    arr.pop_back();
    maxheapify(arr, 0);
    return l;
}
void buildMaxHeap(vector<int>& arr){
    int n = arr.size()/2 - 1;
    for(int i = n ; i>=0 ;i--){
        maxheapify(arr, i);
    }
}
void addMaxHeap(vector<int>&arr, int index){
    while(index>0 && arr[index] > arr[parent(index)]){
        int t = arr[index];
        arr[index] = arr[parent(index)];
        arr[parent(index)] = t;
        index = parent(index);
    }
}
void insertMaxHeap(vector<int>& arr, int value){
    arr.push_back(value);
    addMaxHeap(arr, arr.size()-1);
}
//Min heap
void minheapify(vector<int>& arr, int index){
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < arr.size() && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < arr.size() && arr[smallest]> arr[right]){
        smallest = right;
    }
    if(smallest != index){
        int t = arr[smallest];
        arr[smallest] = arr[index];
        arr[index] = t;
        minheapify(arr, smallest);
    }
}
int getMin(vector<int>& arr){
    int s = arr[0];
    arr[0] = arr[arr.size()-1];
    arr.pop_back();
    minheapify(arr, 0);
    return s;
}
void buildMinHeap(vector<int>&arr){
    int n = arr.size()/2 - 1;
    for(int i= n ; i>=0;i--){
        minheapify(arr, i);
    }
}
void addMinHeap(vector<int>&arr, int index){
    while(index > 0 && arr[index] < arr[parent(index)]){
        int t = arr[index];
        arr[index] = arr[parent(index)];
        arr[parent(index)] = t;
        index = parent(index);
    }
}
void insertMinheap(vector<int>& arr, int value){
    arr.push_back(value);
    addMinHeap(arr, arr.size()-1);
}
int getRoot(vector<int> arr){
    return arr[0];
}

vector<double> calculateMedian(vector<int> arr){
    vector<int> left_max_heap, right_min_heap;
    vector<double> median;
    median.push_back(arr[0]);
    insertMaxHeap(left_max_heap, arr[0]);
    for(int i = 1;i<arr.size();i++){
        int val = arr[i];
        if(left_max_heap.size() == right_min_heap.size()){
            if(val > getRoot(right_min_heap)){
                insertMaxHeap(left_max_heap, getMin(right_min_heap));
                insertMinheap(right_min_heap, val);
                median.push_back(left_max_heap[0]);
            }else{
                insertMaxHeap(left_max_heap, val);
                median.push_back(left_max_heap[0]);
            }
        }else if(left_max_heap.size() > right_min_heap.size()){
            if(val < left_max_heap[0] ){
                insertMinheap(right_min_heap, getMax(left_max_heap));
                insertMaxHeap(left_max_heap, val);
            }
            else{
                insertMinheap(right_min_heap, val);
            }
            median.push_back((double)(left_max_heap[0]+right_min_heap[0])/2.0);
        }else{
            if(val > right_min_heap[0]){
                insertMaxHeap(left_max_heap, getMin(right_min_heap));
                insertMinheap(right_min_heap, val);
            }else{
                insertMaxHeap(left_max_heap, val);
            }
            median.push_back((double)(left_max_heap[0] + right_min_heap[0])/2.0);
        }
    }
    return median;
}
int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<double> ans = calculateMedian(arr);
    for(double x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}