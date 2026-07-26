

# Delete String in Minimum Operations

**Difficulty:** Hard

## Problem Statement

You are given a string `s` consisting only of lowercase English letters.

In one operation, you may choose **any contiguous substring whose characters are all identical** and delete it from the string. After deletion, the remaining left and right parts of the string are concatenated together.

Your goal is to delete the **entire string** using the **minimum number of operations**.

Return the minimum number of operations required.

---

## Examples

### Example 1

**Input**

```text
s = "aabbaa"
```

**Output**

```text
2
```

**Explanation**

Initially,

```text
aabbaa
```

Delete the contiguous block `"bb"`.

```text
aabbaa
  ^^

↓

aaaa
```

Now all remaining characters form one contiguous block.

Delete `"aaaa"`.

```text
aaaa

↓

(empty string)
```

Total operations = **2**

---

### Example 2

**Input**

```text
s = "abc"
```

**Output**

```text
3
```

**Explanation**

Each character is isolated.

```text
abc

↓

bc

↓

c

↓

(empty)
```

Three operations are required.

---

### Example 3

**Input**

```text
s = "aaaa"
```

**Output**

```text
1
```

**Explanation**

The entire string already consists of one contiguous block.

```text
aaaa

↓

(empty)
```

---

### Example 4

**Input**

```text
s = "abba"
```

**Output**

```text
2
```

**Explanation**

Delete `"bb"` first.

```text
abba

↓

aa
```

Then delete `"aa"`.

```text
aa

↓

(empty)
```

---

## Constraints

* `1 <= s.length <= 500`
* `s` consists only of lowercase English letters (`'a'` to `'z'`).

---

## Notes

* You may delete **any** contiguous block of identical characters in one operation.
* After a deletion, the remaining parts of the string become adjacent, which may create new contiguous blocks of identical characters.
* Your objective is to determine the **minimum** number of operations needed to remove the entire string.

---

https://claude.ai/share/9d2132b4-c666-4429-bed5-db9051195739
https://chatgpt.com/share/6a662450-60fc-83ee-851d-5e2cef019df8

