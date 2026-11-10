/**
 * =================================================================================================
 * 4. Median of Two Sorted Arrays
 * =================================================================================================
 */

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

/**
 * =================================================================================================
 * 5. Longest Palindromic Substring
 * =================================================================================================
 */

var longestPalindrome = function (s) {
    let n = s.length
    if (n == 0) return ""

    let start = 0, maxLength = 1

    const expandAroundCenter = (left, right) => {
        while (left >= 0 && right < n && s[left] === s[right]) {
            left--
            right++
        }
        return right - left - 1
    }

    for (let i = 0; i < n; ++i) {
        const l1 = expandAroundCenter(i, i)
        const l2 = expandAroundCenter(i, i + 1)

        const l = Math.max(l1, l2)

        if (l > maxLength) {
            maxLength = l
            start = i - Math.floor((maxLength - 1) / 2)
        }
    }
    return s.substring(start, start + maxLength)
};

/**
 * =================================================================================================
 * 15. 3Sum
 * =================================================================================================
 */

var threeSum = function (a) {
  let res = []
  const n = a.length

  if (n < 3) return res

  a.sort((x, y) => x - y)

  for (let i = 0; i < n - 2; ++i) {
    if (i > 0 && a[i] == a[i - 1]) continue

    const target = 0 - a[i]
    let l = i + 1,
      r = n - 1

    while (l < r) {
      let sum = a[l] + a[r]

      if (sum < target) l++
      else if (sum > target) r--
      else {
        res.push([a[i], a[l], a[r]])
        l++, r--
        while (l < r && a[l] == a[l - 1]) l++
        while (l < r && a[r] == a[r + 1]) r--
      }
    }
  }

  return res
}

/**
 * =================================================================================================
 * 50. Pow(x, n)
 * =================================================================================================
 */

var myPow = function (x, n) {
  if (n == 1) return x
  if (n == 0) return 1
  if (n == -1) return 1 / x

  // let t = myPow(x, Math.floor(n / 2))
  let half = Math.trunc(n / 2) // Fix: Use Math.trunc instead of Math.floor
  let t = myPow(x, half)
  if (n % 2 == 0) return t * t
  else {
    if (n > 0) return t * t * x
    else return (t * t) / x
  }
}

console.log(myPow(2.00000, 10)) // 1024.00000

/**
 * =================================================================================================
 * 61. Rotate List
 * =================================================================================================
 */

function ListNode(val, next = null) {
  this.val = val
  this.next = next
}

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
var rotateRight = function (head, k) {
  if (head == null || head.next == null) return head

  let n = 1
  let end = head
  while (end.next != null) {
    end = end.next
    n++
  }

  k %= n
  if (k === 0) return head

  end.next = head

  let t = head
  for (let i = 0; i < n - k - 1; ++i) t = t.next
  let res = t.next
  t.next = null
  return res
}

/**
 * =================================================================================================
 * 151. Reverse Words in a String
 * =================================================================================================
 */

var reverseWords = function (s) {
  let n = s.length
  // Convert string to array for manipulation
  let arr = s.split('').reverse()

  console.log(arr)
  let finalIndex = 0

  for (let i = 0; i < n; i++) {
    if (arr[i] !== ' ') {
      // Add space between words
      if (finalIndex !== 0) {
        arr[finalIndex++] = ' '
      }

      let wordStart = finalIndex
      let j = i

      while (j < n && arr[j] !== ' ') {
        arr[finalIndex++] = arr[j++]
      }

      // Reverse the current word
      let wordEnd = finalIndex
      let left = wordStart
      let right = wordEnd - 1
      while (left < right) {
        ;[arr[left], arr[right]] = [arr[right], arr[left]]
        left++
        right--
      }

      i = j
    }
  }

  // Resize array and join to string
  return arr.slice(0, finalIndex).join('')
}

// Test
const s = 'the sky is blue'
console.log(reverseWords(s))
