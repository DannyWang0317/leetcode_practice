#include <iostream>
#include <vector>
#include <algorithm> // std::swap

using namespace std;

class Sorter {
public:
    Sorter() {}

    void bubbleSort(vector<int>& array) {
        bool swapped;
        for (int i = 0; i < array.size() - 1; i++) {
            swapped = false;
            for (int j = 0; j < array.size() - 1 - i; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array[j], array[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }

    void selectionSort(vector<int>& array) {
        for (int i = 0; i < array.size() - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < array.size(); j++) {
                if (array[j] < array[min_index]) {
                    min_index = j;
                }
            }
            swap(array[i], array[min_index]);
        }
    }

    void insertionSort(vector<int>& array) {
        for (int i = 1; i < array.size(); i++) {
            int curNum = array[i];
            int j = i - 1;
            while (j >= 0 && curNum < array[j]) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = curNum;
        }
    }

    void mergeSort(vector<int>& array) {
        if (array.size() <= 1) return;
        int mid = array.size() / 2;
        vector<int> leftArray(array.begin(), array.begin() + mid);
        vector<int> rightArray(array.begin() + mid, array.end());
        mergeSort(leftArray);
        mergeSort(rightArray);

        int leftIndex = 0, rightIndex = 0, mergeIndex = 0;
        while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
            if (leftArray[leftIndex] <= rightArray[rightIndex]) {
                array[mergeIndex++] = leftArray[leftIndex++];
            } else {
                array[mergeIndex++] = rightArray[rightIndex++];
            }
        }
        while (leftIndex < leftArray.size()) array[mergeIndex++] = leftArray[leftIndex++];
        while (rightIndex < rightArray.size()) array[mergeIndex++] = rightArray[rightIndex++];
    }

    void quickSort(vector<int>& array) {
        if(array.empty()) return;
        quickSortHelper(array, 0, array.size() - 1);
    }

    void heapSort(vector<int>& array) {
        int n = array.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(array, n, i);
        for (int i = n - 1; i > 0; i--) {
            swap(array[0], array[i]);
            heapify(array, i, 0);
        }
    }

private:
    // Quick Sort 
    void quickSortHelper(vector<int>& array, int low, int high) {
        if (low < high) {
            int pi = partition(array, low, high);
            quickSortHelper(array, low, pi - 1);
            quickSortHelper(array, pi + 1, high);
        }
    }
    // Quick Sort
    int partition(vector<int>& array, int low, int high) {
        int pivot = array[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (array[j] < pivot) {
                i++;
                swap(array[i], array[j]);
            }
        }
        swap(array[i + 1], array[high]);
        return (i + 1);
    }

    // Heap Sort 
    void heapify(vector<int>& array, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && array[left] > array[largest]) largest = left;
        if (right < n && array[right] > array[largest]) largest = right;
        if (largest != i) {
            swap(array[i], array[largest]);
            heapify(array, n, largest);
        }
    }
};

int main() {
    vector<int> myData = {16, 25, 39, 27, 12, 8, 45, 63};
    Sorter s;

    cout << "Before sort: ";
    for (int n : myData) cout << n << " ";
    cout << endl;

    s.heapSort(myData);

    cout << "After sort:  ";
    for (int n : myData) cout << n << " ";
    cout << endl;

    return 0;
}