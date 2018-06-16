N = int(raw_input())
while N :
    result = []
    query_data = raw_input().split()
    if query_data[0] == 'insert':
        result.insert(int(query_data[2]), int(query_data[1]))
    elif query_data[0] == 'print':
        print result
    elif query_data[0] == 'remove':
        result.remove(int(query_data[1]))
    elif query_data[0] == 'append':
        result.append(int(query_data[1]))
    elif query_data[0] == 'sort':
        result.sort()
    elif query_data[0] == 'pop':
        result.pop()
    elif query_data[0] == 'reverse':
        result.reverse()
    N -= 1