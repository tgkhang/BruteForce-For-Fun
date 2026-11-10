# LC Folder Guide

## Layout

| File | What goes in it |
|---|---|
| `INDEX.md` | List of every solved problem, sorted by number. **Auto-generated, don't edit.** |
| `gen_index.py` | Script that rebuilds `INDEX.md` |
| `Array_Math.cpp` | Arrays, two pointers, math, bits, sorting |
| `String.cpp` | Strings, sliding window, stack-on-string |
| `Trie.cpp` | Trie / prefix tree |
| `DP.cpp` | Dynamic programming, prefix sums |
| `BinarySearch.cpp` | Binary search |
| `LinkedList.cpp` | Linked lists |
| `JS.js` | JavaScript solutions |
| `TOP/0_TOP.md` | Must-try problem checklist |

No topic fits? Create a new file (e.g. `Graph.cpp`, `Greedy.cpp`). The script picks it up automatically.

## Find a problem I already did

- Open `INDEX.md` → Ctrl+F the number → click the link.
- Or in VS Code: Ctrl+Shift+F, search ` * 123.`

## Add a new problem

1. Open the matching topic file.
2. Paste the code at its **numeric position** (files are sorted by number), under this banner:

   ```cpp
   /**
    * =================================================================================================
    * 123. Problem Title
    * =================================================================================================
    */

   // your code here
   ```

   - Keep the banner exactly in this shape: `/**`, a ` * ===` line, ` * <number>. <title>`, a ` * ===` line, ` */`.
     The number must be at the start of the title line, otherwise the problem won't show up in the index.
   - Several solutions for one problem: put them all under one banner (e.g. `// c2`, `// c3`).
   - Several related problems in one block: use the first number, e.g. `944 + 955 + 960. Delete Columns ...`.

3. Rebuild the index:

   ```sh
   python Storage/LC/gen_index.py
   ```

4. If it's a must-try problem, tick it in `TOP/0_TOP.md`.

## When a topic file gets too big

At roughly 1000+ lines, turn the file into a folder, e.g. `Trie.cpp` → `Trie/Basic.cpp`, `Trie/Hard.cpp`.
`gen_index.py` scans subfolders too, so the index keeps working.
