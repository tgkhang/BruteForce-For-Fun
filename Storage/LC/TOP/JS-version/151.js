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
