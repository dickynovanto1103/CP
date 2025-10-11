while True:
	try:
		n = int(input())
		p = int(input())

		# print(f"n: {n} p: {p}")
		res = round(p ** (1/n))
		print(res)
	except EOFError:
		break;
