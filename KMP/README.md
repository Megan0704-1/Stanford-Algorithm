
# KMP Algorithm and `lps` Array Concept

## KMP (Knuth-Morris-Pratt) Algorithm

The KMP Algorithm is an efficient string matching algorithm that improves upon the naive approach by avoiding redundant comparisons. It achieves this by preprocessing the pattern and constructing an `lps` (Longest Prefix Suffix) array.

### How KMP Works

- KMP algorithm preprocesses the pattern string and constructs an `lps` array.
- During pattern matching, when a mismatch occurs, KMP uses the `lps` array to determine how far the pattern should be shifted without missing potential matches.

## `lps` (Longest Prefix Suffix) Array

`lps` stands for Longest Proper Prefix which is also Suffix. The `lps` array is a key component in the KMP algorithm.

### Definition

- A **Proper Prefix** is a prefix of a string that is not equal to the string itself.
- A **Suffix** is an ending part of the string.
- The `lps` array stores the lengths of the longest proper prefix in the pattern that is also a suffix.

### Purpose

- The `lps` array is used to skip characters that have already been matched after a mismatch is found.
- It he`lps` in determining the next position where the search should resume.

### ILLUSTRATION

- why a proper prefix that is also a suffix a correct algorithm for constructing the `lps` array in the `KMP` algorithm?

### The Role of Proper Prefix that is also a Suffix in `lps` Array

The KMP algorithm improves string matching efficiency by utilizing the `lps` array to avoid unnecessary re-examination of characters after a mismatch occurs. The key to this efficiency lies in identifying repetitive patterns within the search pattern itself. 

1. **Characterizing Repetitive Patterns:** A proper prefix that is also a suffix in a pattern indicates a repetitive sequence of characters. This repetition is crucial because if a mismatch occurs after matching a part of the pattern, you don't need to recheck the entire pattern from the beginning.

2. **Example:**
   - Consider a ***pattern*** like "AABAACAABAA". The substring "AABAA" is both a prefix and a suffix in the pattern.
   - If you are matching this pattern in a ***text*** and a mismatch occurs after the second "AA" (text: "AABAABAABAACAABA")
    - Obviously, there is a mismatch at pattern[5]: `C` and text[5]: `B`.
    - In the naive way, we will startover and matches the pattern from text[1] again.
    - But in observation ***text***: AAB is a repeated match with ***pattern[0~2]***: AAB, what we should do next is not to move back and compare the string all over again, but to check the whether the next char matches the next char of the repeated match (AAB'A').
   
   - And we already know that the first "AAB" matches because it will be in the `lps` array.

3. **`lps` Array Construction:**
   - The `lps` array keeps track of the lengths of the longest proper prefix which is also a suffix for every sub-pattern of the pattern.
   - When a mismatch occurs, the `lps` array guides you to the next position in the pattern where a match could occur, without re-examining already matched characters.

5. **Optimization in Pattern Matching:** 
   - This approach significantly reduces the number of comparisons needed, especially in cases where the pattern contains repeated sub-patterns.
   - It he`lps` to quickly find the starting point of a possible match in the pattern, following a mismatch.


### Example

Consider the pattern `AAACAAAA`:
- The `lps` array would be `[0, 1, 2, 0, 1, 2, 3, 3]`.
- This array indicates the maximum length of the prefix which is also a suffix at each point in the pattern.

## Conclusion

The KMP algorithm, with its `lps` array, significantly improves the efficiency of string matching by utilizing the information about the pattern's own structure. This leads to less time spent on comparisons and faster overall search times.
