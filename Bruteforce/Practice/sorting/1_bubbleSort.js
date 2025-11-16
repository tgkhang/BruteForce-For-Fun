const bubbleSort = (a) => {
  let n = a.length;

  for (let i = 0; i < n - 1; ++i) {
    let flag = false;
    for (let j = n - 1; j > i; --j) {
      if (a[j] < a[j - 1]) {
        let t = a[j];
        a[j] = a[j - 1];
        a[j - 1] = t;
        flag = true;
      }
    }
    if (!flag) {
      break;
    }
  }
};

// Time complexity: O(n^2)
// Space complexity: O(1)
let arr = [5, 3, 8, 4, 2];
bubbleSort(arr);
console.log(arr); // Output: [2, 3, 4, 5, 8]
