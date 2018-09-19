# Protect Sheep
<div class="problemindexholder" problemindex="A">
        <div class="ttypography"><div class="problem-statement"><div class="header"><div class="title">A. Protect Sheep</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file"><div class="property-title">input</div>standard input</div><div class="output-file"><div class="property-title">output</div>standard output</div></div><div><p>Bob is a farmer. He has a large pasture with many sheep. Recently, he has lost some of them due to wolf attacks. He thus decided to place some shepherd dogs in such a way that all his sheep are protected.</p><p>The pasture is a rectangle consisting of <span class="tex-span"><i>R</i> × <i>C</i></span> cells. Each cell is either empty, contains a sheep, a wolf or a dog. Sheep and dogs always stay in place, but wolves can roam freely around the pasture, by repeatedly moving to the left, right, up or down to a neighboring cell. When a wolf enters a cell with a sheep, it consumes it. However, no wolf can enter a cell with a dog.</p><p>Initially there are no dogs. Place dogs onto the pasture in such a way that no wolf can reach any sheep, or determine that it is impossible. Note that since you have many dogs, you do <span class="tex-font-style-bf">not</span> need to minimize their number. </p></div><div class="input-specification"><div class="section-title">Input</div><p>First line contains two integers <span class="tex-span"><i>R</i></span> (<span class="tex-span">1 ≤ <i>R</i> ≤ 500</span>) and <span class="tex-span"><i>C</i></span> (<span class="tex-span">1 ≤ <i>C</i> ≤ 500</span>), denoting the number of rows and the numbers of columns respectively.</p><p>Each of the following <span class="tex-span"><i>R</i></span> lines is a string consisting of exactly <span class="tex-span"><i>C</i></span> characters, representing one row of the pasture. Here, '<span class="tex-font-style-tt">S</span>' means a sheep, '<span class="tex-font-style-tt">W</span>' a wolf and '<span class="tex-font-style-tt">.</span>' an empty cell.</p></div><div class="output-specification"><div class="section-title">Output</div><p>If it is impossible to protect all sheep, output a single line with the word "<span class="tex-font-style-tt">No</span>".</p><p>Otherwise, output a line with the word "<span class="tex-font-style-tt">Yes</span>". Then print <span class="tex-span"><i>R</i></span> lines, representing the pasture after placing dogs. Again, '<span class="tex-font-style-tt">S</span>' means a sheep, '<span class="tex-font-style-tt">W</span>' a wolf, '<span class="tex-font-style-tt">D</span>' is a dog and '<span class="tex-font-style-tt">.</span>' an empty space. You are not allowed to move, remove or add a sheep or a wolf.</p><p>If there are multiple solutions, you may print any of them. You don't have to minimize the number of dogs.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007842315378831679" id="id0027370919734916876" class="input-copier">Copy</div></div><pre id="id007842315378831679">6 6<br>..S...<br>..S.W.<br>.S....<br>..W...<br>...W..<br>......<br></pre></div><div class="output"><div class="title">Output</div><pre>Yes<br>..SD..<br>..SDW.<br>.SD...<br>.DW...<br>DD.W..<br>......<br></pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004210582859878689" id="id005716349434105323" class="input-copier">Copy</div></div><pre id="id004210582859878689">1 2<br>SW<br></pre></div><div class="output"><div class="title">Output</div><pre>No<br></pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004088616180862714" id="id005001898589950518" class="input-copier">Copy</div></div><pre id="id004088616180862714">5 5<br>.S...<br>...S.<br>S....<br>...S.<br>.S...<br></pre></div><div class="output"><div class="title">Output</div><pre>Yes<br>.S...<br>...S.<br>S.D..<br>...S.<br>.S...<br></pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example, we can split the pasture into two halves, one containing wolves and one containing sheep. Note that the sheep at (2,1) is safe, as wolves cannot move diagonally.</p><p>In the second example, there are no empty spots to put dogs that would guard the lone sheep.</p><p>In the third example, there are no wolves, so the task is very easy. We put a dog in the center to observe the peacefulness of the meadow, but the solution would be correct even without him.</p></div></div><p>  </p></div>
</div>

> *嗨呀，鸽了好多天再来写博客，惭愧惭愧。*

## 题目大意
> **有一个R*C的矩阵，有的单元住着一只羊，有的单元住着一条狼，狼可以上下左右随便走，如果走到羊的格子，就会把羊吃掉，因此让你安排几条狗保护羊，狼不可以通过狗的格子，问你是否可以保护所有的羊（狗可以随便无限安排），如果可以打印出一种安排方法**

## 思路
> *很简单的思路，如果羊挨着狼，那么，无论狗怎么放，羊都会被吃掉，否则直接在羊的上下左右四周安排狗守着，狼就无法吃到狗了呀。签到题，就是这么简单。*
## 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=505;
char im[maxn][maxn];
int r,c;

int main(){
	// freopen("test.txt","r",stdin);
	//freopen("test.out","w",stdout);
	
	while(~scanf("%d %d",&r,&c)){
		memset(im,'.',sizeof(im));
		for(int i=1;i<=r;i++){
			getchar();
			for(int j=1;j<=c;j++){
				scanf("%c",&im[i][j]);
				// printf("%c",im[i][j]);
			}
			// printf("\n");
		}
		int flag=0;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				if(im[i][j]=='S'){
					if(im[i][j+1]=='W'||im[i][j-1]=='W'||im[i+1][j]=='W'||im[i-1][j]=='W'){
						flag=1;
						printf("No\n");
						break;
					}
					else{
						if(im[i][j+1]=='.')
							im[i][j+1]='D';
						if(im[i][j-1]=='.')
						im[i][j-1]='D';
						if(im[i-1][j]=='.')
						im[i-1][j]='D';
						if(im[i+1][j]=='.')
						im[i+1][j]='D';
					}
				}
			}
			if(flag){
				break;
			}
		}
		if(!flag){
			printf("Yes\n");
			for(int i=1;i<=r;i++){
				for(int j=1;j<=c;j++){
					printf("%c",im[i][j]);
				}
				printf("\n");
			}
		}
	}
    return 0;
}
