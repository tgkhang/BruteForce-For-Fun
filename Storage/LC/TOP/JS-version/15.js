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
