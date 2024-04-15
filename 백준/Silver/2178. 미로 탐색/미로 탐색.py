from collections import deque

board = []
N, M = map(int, input().split())

for _ in range(N):
    board.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def OOM(x, y):
    return x < 0 or y < 0 or x >= N or y >= M

def BFS():
    q = deque()
    q.append((0, 0))

    while q:
        x, y = q.popleft()

        if x == N - 1 and y == M - 1:
            break

        for dir in range(4):
            nx = x + dx[dir]
            ny = y + dy[dir]

            if not OOM(nx, ny) and board[nx][ny] == 1:
                q.append((nx, ny))
                board[nx][ny] = board[x][y] + 1

    return

if __name__ == '__main__':
    BFS()
    print(board[N - 1][M - 1])