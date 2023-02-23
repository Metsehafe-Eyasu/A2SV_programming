def draw_cross(start_row, start_col, char, grid, rows, cols):
    # Row-right traversal
    for i in range(start_col+1, cols):
        if grid[start_row][i] == '.':
            grid[start_row][i] = char
        else:
            break
    # Row-left traversal
    for i in range(start_col-1, -1, -1):
        if grid[start_row][i] == '.':
            grid[start_row][i] = char
        else:
            break
    # Col-down traversal
    for i in range(start_row+1, rows):
        if grid[i][start_col] == '.':
            grid[i][start_col] = char
        else:
            break
    # Col-up traversal
    for i in range(start_row-1, -1, -1):
        if grid[i][start_col] == '.':
            grid[i][start_col] = char
        else:
            break

rows, cols = list(map(int, input().split()))
grid = [list(input()) for _ in range(rows)]


home_row, home_col = None, None
rest_row, rest_col = None, None

# Find home and restaurant location
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == 'S':
            home_col = j
            home_row = i
        if grid[i][j] == 'T':
            rest_col = j
            rest_row = i
        if home_col is not None and rest_col is not None:
            break

draw_cross(home_row, home_col, 'S', grid, rows, cols)
draw_cross(rest_row, rest_col, 'T', grid, rows, cols)

# Check open route horizontally
for i in range(rows):
    last = '*'
    for j in range(cols):
        if (grid[i][j], last) == ('S', 'T') or (grid[i][j], last) == ('T', 'S'):
            print('Yes')
            exit()
            
        if grid[i][j] != '.':
            last = grid[i][j]

# Check open route vertically
for i in range(cols):
    last = '*'
    for j in range(rows):
        if (grid[j][i], last) == ('S', 'T') or (grid[j][i], last) == ('T', 'S'):
            print('Yes')
            exit()
            
        if grid[j][i] != '.':
            last = grid[j][i]
            
print('No')