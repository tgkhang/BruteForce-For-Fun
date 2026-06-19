import java.util.ArrayList;
import java.util.List;

public class maxheap {
    private List<Integer> heap;

    public maxheap() {
        heap = new ArrayList<>();
    }

    private void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap.get(left) > heap.get(largest)) {
            largest = left;
        }

        if (right < heap.size() && heap.get(right) > heap.get(largest)) {
            largest = right;
        }

        if (largest != index) {
            int temp = heap.get(index);
            heap.set(index, heap.get(largest));
            heap.set(largest, temp);
            heapify(largest);
        }
    }

    public void insert(int key) {
        heap.add(key);
        int index = heap.size() - 1;

        while (index != 0 && heap.get((index - 1) / 2) < heap.get(index)) {
            int parent = (index - 1) / 2;
            int temp = heap.get(index);
            heap.set(index, heap.get(parent));
            heap.set(parent, temp);
            index = parent;
        }
    }

    public int extractMax() {
        if (heap.isEmpty()) {
            throw new IllegalStateException("Heap underflow");
        }

        if (heap.size() == 1) {
            return heap.remove(0);
        }

        int maximum = heap.get(0);
        heap.set(0, heap.remove(heap.size() - 1));
        heapify(0);
        return maximum;
    }

    public int getMax() {
        if (heap.isEmpty()) {
            throw new IllegalStateException("Heap underflow");
        }

        return heap.get(0);
    }

    public void deleteKey(int index) {
        if (index < 0 || index >= heap.size()) {
            throw new IndexOutOfBoundsException("Invalid index");
        }

        int lastIndex = heap.size() - 1;
        if (index == lastIndex) {
            heap.remove(lastIndex);
            return;
        }

        heap.set(index, heap.remove(lastIndex));

        if (index > 0 && heap.get(index) > heap.get((index - 1) / 2)) {
            while (index != 0 && heap.get((index - 1) / 2) < heap.get(index)) {
                int parent = (index - 1) / 2;
                int temp = heap.get(index);
                heap.set(index, heap.get(parent));
                heap.set(parent, temp);
                index = parent;
            }
        } else {
            heapify(index);
        }
    }

    public void printHeap() {
        for (int value : heap) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

}
