// need to use Math.floor for js index calculation

var findMedianSortedArrays = function (nums1, nums2) {
  let t = merge(nums1, nums2)

  let n = nums1.length
  let m = nums2.length

  return (t[Math.floor((m + n - 1) / 2)] + t[Math.floor((m + n) / 2)]) / 2
}

const merge = (a, b) => {
  let res = []
  let n = a.length,
    m = b.length

  let i = 0,
    j = 0
  while (i < n && j < m) {
    if (a[i] < b[j]) res.push(a[i++])
    else res.push(b[j++])
  }

  if (i == n) {
    while (j < m) res.push(b[j++])
  }

  if (j == m) while (i < n) res.push(a[i++])
  return res
}
