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

