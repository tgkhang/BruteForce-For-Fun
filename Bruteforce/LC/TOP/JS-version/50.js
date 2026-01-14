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