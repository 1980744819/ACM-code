<div class="problemindexholder" problemindex="C">
        <div class="ttypography"><div class="problem-statement"><div class="header"><div class="title">C. Producing Snow</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file"><div class="property-title">input</div>standard input</div><div class="output-file"><div class="property-title">output</div>standard output</div></div><div><p>Alice likes snow a lot! Unfortunately, this year's winter is already over, and she can't expect to have any more of it. Bob has thus bought her a gift&nbsp;— a large snow maker. He plans to make some amount of snow every day. On day <span class="tex-span"><i>i</i></span> he will make a pile of snow of volume <span class="tex-span"><i>V</i><sub class="lower-index"><i>i</i></sub></span> and put it in her garden.</p><p>Each day, every pile will shrink a little due to melting. More precisely, when the temperature on a given day is <span class="tex-span"><i>T</i><sub class="lower-index"><i>i</i></sub></span>, each pile will reduce its volume by <span class="tex-span"><i>T</i><sub class="lower-index"><i>i</i></sub></span>. If this would reduce the volume of a pile to or below zero, it disappears forever. All snow piles are independent of each other. </p><p>Note that the pile made on day <span class="tex-span"><i>i</i></span> already loses part of its volume on the same day. In an extreme case, this may mean that there are no piles left at the end of a particular day.</p><p>You are given the initial pile sizes and the temperature on each day. Determine the total volume of snow melted on each day. </p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer <span class="tex-span"><i>N</i></span> (<span class="tex-span">1 ≤ <i>N</i> ≤ 10<sup class="upper-index">5</sup></span>)&nbsp;— the number of days. </p><p>The second line contains <span class="tex-span"><i>N</i></span> integers <span class="tex-span"><i>V</i><sub class="lower-index">1</sub>, <i>V</i><sub class="lower-index">2</sub>, ..., <i>V</i><sub class="lower-index"><i>N</i></sub></span> (<span class="tex-span">0 ≤ <i>V</i><sub class="lower-index"><i>i</i></sub> ≤ 10<sup class="upper-index">9</sup></span>), where <span class="tex-span"><i>V</i><sub class="lower-index"><i>i</i></sub></span> is the initial size of a snow pile made on the day <span class="tex-span"><i>i</i></span>.</p><p>The third line contains <span class="tex-span"><i>N</i></span> integers <span class="tex-span"><i>T</i><sub class="lower-index">1</sub>, <i>T</i><sub class="lower-index">2</sub>, ..., <i>T</i><sub class="lower-index"><i>N</i></sub></span> (<span class="tex-span">0 ≤ <i>T</i><sub class="lower-index"><i>i</i></sub> ≤ 10<sup class="upper-index">9</sup></span>), where <span class="tex-span"><i>T</i><sub class="lower-index"><i>i</i></sub></span> is the temperature on the day <span class="tex-span"><i>i</i></span>.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output a single line with <span class="tex-span"><i>N</i></span> integers, where the <span class="tex-span"><i>i</i></span>-th integer represents the total volume of snow melted on day <span class="tex-span"><i>i</i></span>.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005906420969080108" id="id0037274127438865157" class="input-copier">Copy</div></div><pre id="id005906420969080108">3<br>10 10 5<br>5 7 2<br></pre></div><div class="output"><div class="title">Output</div><pre>5 12 4<br></pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004773828458116902" id="id00178208938415497" class="input-copier">Copy</div></div><pre id="id004773828458116902">5<br>30 25 20 15 10<br>9 10 12 4 13<br></pre></div><div class="output"><div class="title">Output</div><pre>9 20 35 11 25<br></pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first sample, Bob first makes a snow pile of volume 10, which melts to the size of 5 on the same day. On the second day, he makes another pile of size 10. Since it is a bit warmer than the day before, the first pile disappears completely while the second pile shrinks to 3. At the end of the second day, he has only a single pile of size 3. On the third day he makes a smaller pile than usual, but as the temperature dropped too, both piles survive till the end of the day.</p></div></div><p>  </p></div>
</div>

## 题目大意
> 有个人每天都会弄一堆雪在院子里面，然后天气很热，每天雪都会融化当前温度的体积，直到这堆雪融化完了，问你每天会融化多少雪。

## 思路
> 这个题目开始想多了，很烦，其实还是比较简单的，就求出每堆雪会在哪天融化完的，还有融化当天比平常少融化多少，减去就好了。但是在求哪天融化的时候，必须优化一点，否则时间不够，优化的时候，后面加入的雪堆就当做一开就存在，这样就只要一次扫描就可以求出所有的雪堆哪天融化的，用了一下lower_bound()这个函数，可以快速求出雪堆是哪天融化的.

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
const int maxn = 100005;
struct node
{
	ll n;
	ll total;
} pi[maxn];
ll v[maxn], t[maxn];
ll num[maxn];
void init()
{
	for (int i = 0; i < maxn; i++)
	{
		pi[i].n = 0;
		pi[i].total = 0;
		v[i] = 0;
		t[i] = 0;
		num[i] = 0;
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	// freopen("test.out","w",stdout);
	int n;
	while (~scanf("%d", &n))
	{
		init();
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &v[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &t[i]);
			v[i] += num[i - 1];
			num[i] = num[i - 1] + t[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (v[i] > 0)
			{
				int a = lower_bound(num, num + n + 1, v[i]) - num;
				if (num[a] >= v[i])
				{
					if (pi[a].n > 0)
					{
						pi[a].n++;
						pi[a].total += num[a] - v[i];
					}
					else
					{
						pi[a].n = 1;
						pi[a].total = num[a] - v[i];
					}
				}
			}
			else
			{
				pi[i].n++;
				pi[i].total += t[i];
			}
		}
		int cou = 0;
		for (int i = 1; i <= n; i++)
		{
			printf("%lld ", t[i] * (i - cou) - pi[i].total);
			cou += pi[i].n;
		}
		printf("\n");
	}
	return 0;
}
```