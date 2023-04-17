#include <iostream>
#include <vector>

class Heap {
 public:
  void Insert(int num) {
    heap_.push_back(num);
    SiftUp(static_cast<int>(heap_.size() - 1));
  }

  int Extract() {
    int max = heap_[0];
    std::swap(heap_[0], heap_[heap_.size() - 1]);
    heap_.pop_back();
    SiftDown(0);
    return max;
  }

  std::vector<int> &HeapSort() {
    for (int i = heap_.size() - 1; i > 0; --i) {
      std::swap(heap_[0], heap_[i]);
      SiftDown(0, i);
    }

    return heap_;
  }

 private:
  void SiftUp(int index) {
    while (index > 0 && heap_[index] > heap_[(index - 1) / 2]) {
      std::swap(heap_[index], heap_[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  void SiftDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int j;

    while (left < heap_.size()) {
      j = left;
      if (right < heap_.size() && heap_[j] < heap_[right]) {
        j = right;
      }

      if (heap_[j] < heap_[index]) {
        break;
      }
      std::swap(heap_[index], heap_[j]);

      index = j;
      left = 2 * index + 1;
      right = 2 * index + 2;
    }
  }

  void SiftDown(int index, int limit) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int j;

    while (left < limit) {
      j = left;
      if (right < limit && heap_[j] < heap_[right]) {
        j = right;
      }

      if (heap_[j] < heap_[index]) {
        break;
      }
      std::swap(heap_[index], heap_[j]);

      index = j;
      left = 2 * index + 1;
      right = 2 * index + 2;
    }
  }

 private:
  std::vector<int> heap_;
};

int main() {
  int n;
  std::cin >> n;

  Heap heap;
  int num;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    heap.Insert(num);
  }

  std::vector<int> array = heap.HeapSort();
  for (int i = 0; i < n; ++i) {
    std::cout << array[i] << " ";
  }
  return 0;
}