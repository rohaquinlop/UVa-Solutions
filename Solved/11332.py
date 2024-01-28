from sys import stdin

def main():
    lines = stdin.readlines()

    for line in lines:
        n = int(line)
        if n == 0:
            break
        while n >= 10:
            n = sum(map(int, list(str(n))))
        print(n)

if __name__ == '__main__':
    main()
