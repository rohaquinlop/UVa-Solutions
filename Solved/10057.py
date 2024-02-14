from sys import stdin


def solve(cnt: dict[int, int], highest: int, n: int) -> tuple[int, int, int]:
    if n%2 != 0:
        accum = 0
        for i in range(highest + 1):
            accum += cnt[i]
            if accum > n//2:
                return i, cnt[i], 1
    # if n is even
    accum = 0
    low_median = 0
    high_median = 0

    for i in range(highest + 1):
        accum += cnt[i]
        if accum >= n//2:
            low_median = i
            break
    accum = 0
    for i in range(highest + 1):
        accum += cnt[i]
        if accum >= (n//2)+1:
            high_median = i
            break

    if low_median == high_median:
        return low_median, cnt[low_median], 1

    A = low_median
    nums_A = cnt[low_median] + cnt[high_median]
    unique_A = high_median - low_median + 1
    return A, nums_A, unique_A


def main():
    lines = stdin.readlines()
    i = 0
    ans = ""

    # convert every line to integer, the lines could be a string with spaces
    array = [int(item) for line in lines for item in line.split()]

    while i < len(array):
        n = array[i]
        i += 1
        cnt: dict[int, int] = {}
        highest = 0

        for _ in range(n):
            cnt[array[i]] = cnt.get(array[i], 0) + 1
            highest = max(highest, array[i])
            i += 1
        A, nums_A, uniques_A = solve(cnt, highest, n)
        ans += f"{A} {nums_A} {uniques_A}\n"
    print(ans, end="")

if __name__ == "__main__":
    main()