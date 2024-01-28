import heapq
from sys import stdin
from math import ceil

def solve(medicines, priority_frecuency, k):
    ans = []
    medicine_ith = [1 for _ in range(len(medicines))]
    while len(ans) < k:
        frecuency, priority = heapq.heappop(medicines)
        ans.append( (frecuency, priority) )
        ith = medicine_ith[priority]+1
        heapq.heappush(medicines, (priority_frecuency[priority]*ith, priority))
        medicine_ith[priority] = ith
    return ans

def main():
    lines = stdin.readlines()

    t = int(lines[0])
    i = 1
    ans = ""

    while t > 0:
        t -= 1
        n, k = map(int, lines[i].split())
        i += 1

        medicines = []
        medicine_name = ["" for _ in range(n)]
        priority_frecuency = [0 for _ in range(n)]

        for j in range(n):
            name, frecuency = lines[i].split()
            frecuency = int(frecuency)
            i += 1
            medicines.append((frecuency, j))
            medicine_name[j] = name
            priority_frecuency[j] = frecuency
        heapq.heapify(medicines)

        local_ans = solve(medicines, priority_frecuency, k)

        for frecuency, priority in local_ans:
            ans += f'{frecuency} {medicine_name[priority]}\n'
    print(ans, end='')


if __name__ == '__main__':
    main()
