from random import randint 

def generate(rows = 10, cols = 10, max = 1000):
    result = []
    for i in range(rows):
        row = []
        for j in range(cols):
            x = randint(0, max)
            row.append(x)
        result.append(row)
    return result

def solve(A, n, m):
    lb, ub = 0, m-1
    while(lb<=ub):
        # global max in a column - O(n)
        j = (lb + ub)//2
        max = A[0][j]
        pos = 0
        for i in range(1, n):
            if A[i][j]>max:
                max = A[i][j]
                pos = i
        
        # global max at(pos, j)
        if A[pos][j]<A[pos][j-1]:
            ub = j - 1
        elif A[pos][j]<A[pos][j+1]:
            lb = j + 1
        else:
            return (A[pos][j], pos, j)

def print_matrix(A):
    for i in A:
        for j in i:
            print(j, end = "\t")
        print()

def problem ():
    problemMatrix = [
	[ 4,  5,  6,  7,  8,  7,  6,  5,  4,  3,  2],
	[ 5,  6,  7,  8,  9,  8,  7,  6,  5,  4,  3],
	[ 6,  7,  8,  9, 10,  9,  8,  7,  6,  5,  4],
	[ 7,  8,  9, 10, 11, 10,  9,  8,  7,  6,  5],
	[ 8,  9, 10, 11, 12, 11, 10,  9,  8,  7,  6],
	[ 7,  8,  9, 10, 11, 10,  9,  8,  7,  6,  5],
	[ 6,  7,  8,  9, 10,  9,  8,  7,  6,  5,  4],
	[ 5,  6,  7,  8,  9,  8,  7,  6,  5,  4,  3],
	[ 4,  5,  6,  7,  8,  7,  6,  5,  4,  3,  2],
	[ 3,  4,  5,  6,  7,  6,  5,  4,  3,  2,  1],
	[ 2,  3,  4,  5,  6,  5,  4,  3,  2,  1,  0]
    ]
    val, r, c = solve(problemMatrix, 10, 10)
    print("Matrix:")
    print_matrix(problemMatrix)
    print("-------------------Result---------------------\n")
    print("Value : {}, row = {}, col = {}".format(val, r+1, c+1))
    print("------------------------------------------------")

def main():
    #n, m = map(int, input().split())
    n, m, max = 10, 10, 1000
    A = generate()
    val, r, c = solve(A, n, m)
    print("Matrix:")
    print_matrix(A)
    print("-------------------Result---------------------\n")
    print("Value : {}, row = {}, col = {}".format(val, r+1, c+1))
    print("------------------------------------------------")
   
    

if __name__ == "__main__":
    #problem()
    main()








        
        

