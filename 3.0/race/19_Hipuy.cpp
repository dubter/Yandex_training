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

 private:
  std::vector<int> heap_;
};

int main() {
  int n;
  std::cin >> n;

  Heap heap;
  int mode;
  int k;
  for (int i = 0; i < n; ++i) {
    std::cin >> mode;
    if (mode == 0) {
      std::cin >> k;
      heap.Insert(k);
    } else if (mode == 1) {
      std::cout << heap.Extract() << '\n';
    }
  }
  return 0;
}