import json

n = int(input())
a = dict()



for i in range(n):
	tmp = json.loads(input())
	val = tmp["citing_paper_count"]
	for y in tmp["authors"]["authors"]:
		if y["full_name"] in a:
			a[y["full_name"]].append(val)
		else:
			a[y["full_name"]] = [val]

ans = dict()

for x in a:
	a[x].sort(reverse=True)
	val = 0
	for i in range(len(a[x])):
		if a[x][i] <= i :
			break
		val = i+1
	if val in ans :
		ans[val].append(x)
	else :
		ans[val] = [x]

for x in sorted(ans.keys(), reverse=True) :
	for y in sorted(ans[x]):
		print(y, x)

