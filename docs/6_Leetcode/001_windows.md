# 动态滑动窗口

## 例题 [3.无重复的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/)

> 描述：给定一个字符串s，请你找出其中不含有重复字符的最长子串的长度。

>示例1：
>- 输入：s="abcabcbb"
>- 输出：3
>- 解释：因为无重复的最长子串是"abc"，所以其长度为3

> 示例2：
> - 输入：s="bbbbb"
> - 输出：1
> - 解释：因为无重复的最长子串是"b"，所以其长度为1


解题思路：
- 使用哈希表来做，可以用一个布尔数组来存放当前字符是否已经在窗口内`let mut windows = [false, 128]`
- 在存放好之后就进行迭代，在迭代过程中，需要再次用一个`while`来判断最左侧当前是否和右侧冲突

完整代码如下：
```rust
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let s = s.as_bytes();
        let mut ans = 0;
        let mut left = 0;
        let mut windows = [false; 128];

        // 滑动窗口的重点，右侧1个1个滑，但是左侧可能会走很多步
        for(right, &c) in s.iter().enumerate() {
            let c = c as usize;
            while windows[c] {
                windows[s[left] as usize] = false;
                left += 1;
            }
            windows[c] = true;
            ans = ans.max(right - left + 1);
        }
        ans as _
    }
}
// @lc code=end


#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test_example() {
        // TODO: 添加测试用例
        let mut s = String::new();
        s = "bbbbb".to_string();

        assert_eq!(Solution::length_of_longest_substring(s), 1);
    }
}

```


## 例题 [3090. 每个字符最多出现2次的最长子字符串](https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/description/)

这个题的解题思路和上边基本一致，唯一需要注意的是，需要把布尔数组换成次数数组，同时在左边判断的时候也要注意，是`>=2`，因为如果此时数组已经有2个，就不能再放了。

完整代码如下：
```rust

// @lc code=start
impl Solution {
    pub fn maximum_length_substring(s: String) -> i32 {
        // 一个哈希表，放置在这个窗口中他们的个数
        let mut windows = [0; 128];
        let mut ans = 0;
        let mut left = 0;

        let s=  s.as_bytes();

        for (right, &c) in s.iter().enumerate() {
            let c = c as usize;
            while windows[c] >= 2 {
                windows[s[left] as usize] -= 1;
                left += 1;
            }
            windows[c] += 1;
            ans = ans.max(right - left + 1);
        }  
            
        ans as _
    }
}
// @lc code=end


#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test_example() {
        // TODO: 添加测试用例
        let s = "bcbbbcba".to_string();
        let ans = 4;
        assert_eq!(Solution::maximum_length_substring(s), ans);
    }
}

```