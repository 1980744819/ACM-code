<div class="problemindexholder" problemindex="B">
        <div class="ttypography"><div class="problem-statement"><div class="header"><div class="title">B. Primal Sport</div><div class="time-limit"><div class="property-title">time limit per test</div>1.5 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file"><div class="property-title">input</div>standard input</div><div class="output-file"><div class="property-title">output</div>standard output</div></div><div><p>Alice and Bob begin their day with a quick game. They first choose a starting number <span class="tex-span"><i>X</i><sub class="lower-index">0</sub> ≥ 3</span> and try to reach one million by the process described below. </p><p>Alice goes first and then they take alternating turns. In the <span class="tex-span"><i>i</i></span>-th turn, the player whose turn it is selects a prime number smaller than the current number, and announces the smallest multiple of this prime number that is not smaller than the current number.</p><p>Formally, he or she selects a prime <span class="tex-span"><i>p</i> &lt; <i>X</i><sub class="lower-index"><i>i</i> - 1</sub></span> and then finds the minimum <span class="tex-span"><i>X</i><sub class="lower-index"><i>i</i></sub> ≥ <i>X</i><sub class="lower-index"><i>i</i> - 1</sub></span> such that <span class="tex-span"><i>p</i></span> divides <span class="tex-span"><i>X</i><sub class="lower-index"><i>i</i></sub></span>. Note that if the selected prime <span class="tex-span"><i>p</i></span> already divides <span class="tex-span"><i>X</i><sub class="lower-index"><i>i</i> - 1</sub></span>, then the number does not change.</p><p>Eve has witnessed the state of the game after two turns. Given <span class="tex-span"><i>X</i><sub class="lower-index">2</sub></span>, help her determine what is the smallest possible starting number <span class="tex-span"><i>X</i><sub class="lower-index">0</sub></span>. Note that the players don't necessarily play optimally. You should consider all possible game evolutions.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The input contains a single integer <span class="tex-span"><i>X</i><sub class="lower-index">2</sub></span> (<span class="tex-span">4 ≤ <i>X</i><sub class="lower-index">2</sub> ≤ 10<sup class="upper-index">6</sup></span>). It is guaranteed that the integer <span class="tex-span"><i>X</i><sub class="lower-index">2</sub></span> is composite, that is, is not prime.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output a single integer&nbsp;— the minimum possible <span class="tex-span"><i>X</i><sub class="lower-index">0</sub></span>.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009157128479498244" id="id001714640757543473" class="input-copier">Copy</div></div><pre id="id009157128479498244">14<br></pre></div><div class="output"><div class="title">Output</div><pre>6<br></pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005159917768934943" id="id009918115461485524" class="input-copier">Copy</div></div><pre id="id005159917768934943">20<br></pre></div><div class="output"><div class="title">Output</div><pre>15<br></pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0042118287436951274" id="id0039492129251991903" class="input-copier">Copy</div></div><pre id="id0042118287436951274">8192<br></pre></div><div class="output"><div class="title">Output</div><pre>8191<br></pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test, the smallest possible starting number is <span class="tex-span"><i>X</i><sub class="lower-index">0</sub> = 6</span>. One possible course of the game is as follows: </p><ul> <li> Alice picks prime 5 and announces <span class="tex-span"><i>X</i><sub class="lower-index">1</sub> = 10</span> </li><li> Bob picks prime 7 and announces <span class="tex-span"><i>X</i><sub class="lower-index">2</sub> = 14</span>. </li></ul><p>In the second case, let <span class="tex-span"><i>X</i><sub class="lower-index">0</sub> = 15</span>. </p><ul> <li> Alice picks prime 2 and announces <span class="tex-span"><i>X</i><sub class="lower-index">1</sub> = 16</span> </li><li> Bob picks prime 5 and announces <span class="tex-span"><i>X</i><sub class="lower-index">2</sub> = 20</span>. </li></ul></div></div><p>  </p></div>
</div>

>难得起个大早，写一篇结题报告吧，这个题我智障想了好久好久，开始我以为是个找规律的题目，没想到在1000000那里翻船了，然后又左思右想，终于想到了

## 题目大意

>有两个人在玩游戏，轮流来的，首先给出一个$X_{0}$,每次选取一个质数，这个质数比当前数值小，然后让这个质数的最小倍数大于等于当前数值(等于的时候是说这个质数本身就是当前数值的因数)，这个数字便是下一个数字。题目给$X_{2}$(这个数字是个非质数)的结果，希望你能求出满足要求的最小的$X_{0}$

## 思路

>**首先明确一点,每个非质数都可以变成几个质数的乘积，因此$x_{1}$的范围是[$X_2$-P($X_2$)+1,$X_2$],$X_0$的范围是[$X_1$-P($X_1$)+1,X1)],可以看出来选取的质数越大，上一个数字的最小值越小。首先运用素数筛，灵活改变一点，不仅可以筛出非质数，而且标注非质数的最大质数因子，这是最重要的一步，可以求出P($X_1$),即可求出最小的$X_0$**

## 代码

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1000006;
int prime[maxn];
void getprime()
{
    int n = 2;
    while (n < maxn)
    {
        int num = n * 2;
        while (num < maxn)
        {
            prime[num] = n;
            num += n;
        }
        num = n + 1;
        while (prime[num] != 0 && num < maxn)
        {
            num++;
        }
        n = num;
    }
}
int main()
{
    getprime();
    int x0, x1, x2;
    while (~scanf("%d", &x2))
    {
        int a = 0, b = 0;
        b = prime[x2];
        x0 = 99999999;
        for (int i = x2 - b + 1; i <= x2; i++)
        {
            a = prime[i];
            x0 = min(i - a + 1, x0);
        }
        printf("%d\n", x0);
    }
    return 0;
}

```